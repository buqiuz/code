#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <linux/fs.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <errno.h>

#include "revofs.h"

struct superblock {
    struct revofs_sb_info info;
    char padding[4064]; /* Padding to match block size */
};

/* Returns ceil(a/b) */
static inline uint32_t idiv_ceil(uint32_t a, uint32_t b)
{
    uint32_t ret = a / b;
    if (a % b)
        return ret + 1;
    return ret;
}

static struct superblock *write_superblock(int fd, struct stat *fstats)
{
    struct superblock *sb = malloc(sizeof(struct superblock));
    if (!sb)
        return NULL;

    uint32_t nr_blocks = fstats->st_size / REVOFS_BLOCK_SIZE;
    uint32_t nr_inodes = nr_blocks;
    uint32_t mod = nr_inodes % REVOFS_INODES_PER_BLOCK;
    if (mod)
        nr_inodes += REVOFS_INODES_PER_BLOCK - mod;
    uint32_t nr_istore_blocks = idiv_ceil(nr_inodes, REVOFS_INODES_PER_BLOCK);
    uint32_t nr_ifree_blocks = idiv_ceil(nr_inodes, REVOFS_BLOCK_SIZE * 8);
    uint32_t nr_bfree_blocks = idiv_ceil(nr_blocks, REVOFS_BLOCK_SIZE * 8);
    uint32_t nr_data_blocks =
        nr_blocks - nr_istore_blocks - nr_ifree_blocks - nr_bfree_blocks;

    memset(sb, 0, sizeof(struct superblock));
    sb->info = (struct revofs_sb_info){
        .magic = htole32(REVOFS_MAGIC),
        .nr_blocks = htole32(nr_blocks),
        .nr_inodes = htole32(nr_inodes),
        .nr_istore_blocks = htole32(nr_istore_blocks),
        .nr_ifree_blocks = htole32(nr_ifree_blocks),
        .nr_bfree_blocks = htole32(nr_bfree_blocks),
        .nr_free_inodes = htole32(nr_inodes - 1),
        .nr_free_blocks = htole32(nr_data_blocks - 1),
    };

    int ret = write(fd, sb, sizeof(struct superblock));
    if (ret != sizeof(struct superblock)) {
        free(sb);
        return NULL;
    }

    printf(
        "Superblock: (%ld)\n"
        "\tmagic=%#x(RE)\n"
        "\tnr_blocks=%u\n"
        "\tnr_inodes=%u (istore=%u blocks)\n"
        "\tnr_ifree_blocks=%u\n"
        "\tnr_bfree_blocks=%u\n"
        "\tnr_free_inodes=%u\n"
        "\tnr_free_blocks=%u\n",
        sizeof(struct superblock), sb->info.magic, sb->info.nr_blocks,
        sb->info.nr_inodes, sb->info.nr_istore_blocks, sb->info.nr_ifree_blocks,
        sb->info.nr_bfree_blocks, sb->info.nr_free_inodes,
        sb->info.nr_free_blocks);

    return sb;
}

static int write_inode_store(int fd, struct superblock *sb)
{
    /* Allocate a zeroed block for inode store */
    char *block = malloc(REVOFS_BLOCK_SIZE);
    if (!block)
        return -1;

    memset(block, 0, REVOFS_BLOCK_SIZE);

    /* Root inode (inode 0) */
    struct revofs_inode *inode = (struct revofs_inode *) block;
    uint32_t first_data_block = 1 + le32toh(sb->info.nr_bfree_blocks) +
                                le32toh(sb->info.nr_ifree_blocks) +
                                le32toh(sb->info.nr_istore_blocks);
    inode->i_mode = htole32(S_IFDIR | S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR |
                            S_IWGRP | S_IXUSR | S_IXGRP | S_IXOTH);
    inode->i_uid = 0;
    inode->i_gid = 0;
    inode->i_size = htole32(REVOFS_BLOCK_SIZE);
    inode->i_ctime = inode->i_atime = inode->i_mtime = htole32(0);
    inode->i_blocks = htole32(1);
    inode->i_nlink = htole32(2);
    inode->ei_block = htole32(first_data_block);

    int ret = write(fd, block, REVOFS_BLOCK_SIZE);
    if (ret != REVOFS_BLOCK_SIZE) {
        ret = -1;
        goto end;
    }

    /* Reset inode store blocks to zero */
    memset(block, 0, REVOFS_BLOCK_SIZE);
    uint32_t i;
    for (i = 1; i < sb->info.nr_istore_blocks; i++) {
        ret = write(fd, block, REVOFS_BLOCK_SIZE);
        if (ret != REVOFS_BLOCK_SIZE) {
            ret = -1;
            goto end;
        }
    }
    ret = 0;

    printf(
        "Inode store: wrote %d blocks\n"
        "\tinode size = %ld B\n",
        i, sizeof(struct revofs_inode));

end:
    free(block);
    return ret;
}

static int write_ifree_blocks(int fd, struct superblock *sb)
{
    char *block = malloc(REVOFS_BLOCK_SIZE);
    if (!block)
        return -1;

    uint64_t *ifree = (uint64_t *) block;

    /* Set all bits to 1 */
    memset(ifree, 0xff, REVOFS_BLOCK_SIZE);

    /* First ifree block, containing first used inode */
    ifree[0] = htole64(0xfffffffffffffffe);
    int ret = write(fd, ifree, REVOFS_BLOCK_SIZE);
    if (ret != REVOFS_BLOCK_SIZE) {
        ret = -1;
        goto end;
    }

    /* All ifree blocks except the one containing 2 first inodes */
    ifree[0] = 0xffffffffffffffff;
    uint32_t i;
    for (i = 1; i < le32toh(sb->info.nr_ifree_blocks); i++) {
        ret = write(fd, ifree, REVOFS_BLOCK_SIZE);
        if (ret != REVOFS_BLOCK_SIZE) {
            ret = -1;
            goto end;
        }
    }
    ret = 0;

    printf("Ifree blocks: wrote %d blocks\n", i);

end:
    free(block);

    return ret;
}

static int write_bfree_blocks(int fd, struct superblock *sb)
{
    uint32_t nr_used = le32toh(sb->info.nr_istore_blocks) +
                       le32toh(sb->info.nr_ifree_blocks) +
                       le32toh(sb->info.nr_bfree_blocks) + 2;

    char *block = malloc(REVOFS_BLOCK_SIZE);
    if (!block)
        return -1;
    uint64_t *bfree = (uint64_t *) block;

    /*
     * First blocks (incl. sb + istore + ifree + bfree + 1 used block)
     * we suppose it won't go further than the first block
     */
    memset(bfree, 0xff, REVOFS_BLOCK_SIZE);
    uint32_t i = 0;
    while (nr_used) {
        uint64_t line = 0xffffffffffffffff;
        for (uint64_t mask = 0x1; mask; mask <<= 1) {
            line &= ~mask;
            nr_used--;
            if (!nr_used)
                break;
        }
        bfree[i] = htole64(line);
        i++;
    }
    int ret = write(fd, bfree, REVOFS_BLOCK_SIZE);
    if (ret != REVOFS_BLOCK_SIZE) {
        ret = -1;
        goto end;
    }

    /* other blocks */
    memset(bfree, 0xff, REVOFS_BLOCK_SIZE);
    for (i = 1; i < le32toh(sb->info.nr_bfree_blocks); i++) {
        ret = write(fd, bfree, REVOFS_BLOCK_SIZE);
        if (ret != REVOFS_BLOCK_SIZE) {
            ret = -1;
            goto end;
        }
    }
    ret = 0;

    printf("Bfree blocks: wrote %d blocks\n", i);
end:
    free(block);

    return ret;
}

static int write_data_blocks(int fd, struct superblock *sb)
{
    /* FIXME: unimplemented */
    return 0;
}


// message type
#define NETLINK_MSG_FOR_SCHIPS    30 // no more than 32
// The port number
#define USER_PORT        123
#define MSG_LEN         125
#define MAX_PLOAD       MSG_LEN


typedef struct _user_msg_info
{
    struct nlmsghdr hdr;
    char  msg[MSG_LEN];
} user_msg_info;



int main(int argc, char **argv)
{
    int skfd;
    int ret_nl;
    user_msg_info u_info;
    socklen_t len;
    struct nlmsghdr *nlh = NULL;
    struct sockaddr_nl bind_addr;
    struct sockaddr_nl dest_addr;
    char *umsg = "hello Revofs";

    /* create NETLINK socket */
    skfd = socket(AF_NETLINK, SOCK_RAW, NETLINK_MSG_FOR_SCHIPS);
    if(skfd == -1)
    {
        perror("create socket error");
        return -1;
    }

    memset(&bind_addr, 0, sizeof(bind_addr));
    bind_addr.nl_family = AF_NETLINK; //AF_NETLINK
    bind_addr.nl_pid = USER_PORT;  //Port number (port ID)
    bind_addr.nl_groups = 0;
    if(bind(skfd, (struct sockaddr *)&bind_addr, sizeof(bind_addr)) != 0)
    {
        perror("bind() error\n");
        close(skfd);
        return -1;
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.nl_family = AF_NETLINK;
    dest_addr.nl_pid = 0; // to kernel 
    dest_addr.nl_groups = 0;

    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PLOAD));
    memset(nlh, 0, sizeof(struct nlmsghdr));
    nlh->nlmsg_len = NLMSG_SPACE(MAX_PLOAD);
    nlh->nlmsg_flags = 0;
    nlh->nlmsg_type = 0;
    nlh->nlmsg_seq = 0;
    nlh->nlmsg_pid = bind_addr.nl_pid; //self port

    memcpy(NLMSG_DATA(nlh), umsg, strlen(umsg));
    ret_nl= sendto(skfd, nlh, nlh->nlmsg_len, 0, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr_nl));
    if(!ret_nl)
    {
        perror("sendto error");
        close(skfd);
        exit(-1);
    }

    memset(&u_info, 0, sizeof(u_info));
    len = sizeof(struct sockaddr_nl);
    ret_nl= recvfrom(skfd, &u_info, sizeof(user_msg_info), 0, (struct sockaddr *)&dest_addr, &len);
    if(!ret_nl)
    {
        perror("recv form kernel error");
        close(skfd);
        exit(-1);
    }

    printf("from kernel:%s\n", u_info.msg);
    
    close(skfd);

    free((void *)nlh);


    if (argc != 2) {
        fprintf(stderr, "Usage: %s disk\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open disk image */
    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("open():");
        return EXIT_FAILURE;
    }

    /* Get image size */
    struct stat stat_buf;
    int ret = fstat(fd, &stat_buf);
    if (ret) {
        perror("fstat():");
        ret = EXIT_FAILURE;
        goto fclose;
    }

    /* Get block device size */
    if ((stat_buf.st_mode & S_IFMT) == S_IFBLK) {
        long int blk_size = 0;
        ret = ioctl(fd, BLKGETSIZE64, &blk_size);
        if (ret != 0) {
            perror("BLKGETSIZE64:");
            ret = EXIT_FAILURE;
            goto fclose;
        }
        stat_buf.st_size = blk_size;
    }

    /* Check if image is large enough */
    long int min_size = 100 * REVOFS_BLOCK_SIZE;
    if (stat_buf.st_size <= min_size) {
        fprintf(stderr, "File is not large enough (size=%ld, min size=%ld)\n",
                stat_buf.st_size, min_size);
        ret = EXIT_FAILURE;
        goto fclose;
    }

    /* Write superblock (block 0) */
    struct superblock *sb = write_superblock(fd, &stat_buf);
    if (!sb) {
        perror("write_superblock():");
        ret = EXIT_FAILURE;
        goto fclose;
    }

    /* Write inode store blocks (from block 1) */
    ret = write_inode_store(fd, sb);
    if (ret) {
        perror("write_inode_store():");
        ret = EXIT_FAILURE;
        goto free_sb;
    }

    /* Write inode free bitmap blocks */
    ret = write_ifree_blocks(fd, sb);
    if (ret) {
        perror("write_ifree_blocks()");
        ret = EXIT_FAILURE;
        goto free_sb;
    }

    /* Write block free bitmap blocks */
    ret = write_bfree_blocks(fd, sb);
    if (ret) {
        perror("write_bfree_blocks()");
        ret = EXIT_FAILURE;
        goto free_sb;
    }

    /* Write data blocks */
    ret = write_data_blocks(fd, sb);
    if (ret) {
        perror("write_data_blocks():");
        ret = EXIT_FAILURE;
        goto free_sb;
    }

free_sb:
    free(sb);
fclose:
    close(fd);

    return ret;
}
