#define pr_fmt(fmt) KBUILD_MODNAME ":%s:%d: " fmt, __func__, __LINE__
#include "myfs.h"



void myfs_kill_superblock(struct super_block *sb) {
    printk(KERN_INFO
           "myfs superblock is destroyed. Unmount succesful.\n");
    kill_block_super(sb);
}

struct dentry *myfs_mount(struct file_system_type *fs_type,
                             int flags, const char *dev_name,
                             void *data) {
    struct dentry *ret;
    ret = mount_bdev(fs_type, flags, dev_name, data, myfs_fill_super);

    if (unlikely(IS_ERR(ret))) {
        printk(KERN_ERR "Error mounting myfs.\n");
    } else {
        printk(KERN_INFO "myfs is succesfully mounted on: %s\n",
               dev_name);
    }

    return ret;
}
struct file_system_type myfs_fs_type = {
    .owner = THIS_MODULE,
    .name = "myfs",
    .mount = myfs_mount,
    .kill_sb = myfs_kill_superblock,
    .fs_flags = FS_REQUIRES_DEV,
};



struct kmem_cache *myfs_inode_cache = NULL;

static int __init myfs_init(void)
{
    int ret;

    myfs_inode_cache = kmem_cache_create("myfs_inode_cache",
                                         sizeof(struct myfs_inode),
                                         0,
                                         (SLAB_RECLAIM_ACCOUNT| SLAB_MEM_SPREAD),
                                         NULL);
    if (!myfs_inode_cache) {
        return -ENOMEM;
    }

    ret = register_filesystem(&myfs_fs_type);
    if (likely(0 == ret)) {
        printk(KERN_INFO "Sucessfully registered myfs\n");
    } else {
        printk(KERN_ERR "Failed to register myfs. Error code: %d\n", ret);
    }

    return ret;
}

static void __exit myfs_exit(void)
{
    int ret;

    ret = unregister_filesystem(&myfs_fs_type);
    kmem_cache_destroy(myfs_inode_cache);

    if (likely(ret == 0)) {
        printk(KERN_INFO "Sucessfully unregistered myfs\n");
    } else {
        printk(KERN_ERR "Failed to unregister myfs. Error code: %d\n",
               ret);
    }
}

module_init(myfs_init);
module_exit(myfs_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("buqiu");
