
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/statfs.h>

static int myfs_fill_super(struct super_block *sb, void *data, int silent) {
    return 0;
}