# SPDX-License-Identifier: GPL-2.0
#
# Makefile for the Linux ext2 filesystem module.

obj-m += ext2_module.o

ext2_module-y := balloc.o dir.o file.o ialloc.o inode.o \
                 ioctl.o namei.o super.o symlink.o trace.o

# For tracepoints to include our trace.h from tracepoint infrastructure
CFLAGS_trace.o := -I$(src)

ext2_module-$(CONFIG_EXT2_FS_XATTR)     += xattr.o xattr_user.o xattr_trusted.o
ext2_module-$(CONFIG_EXT2_FS_POSIX_ACL) += acl.o
ext2_module-$(CONFIG_EXT2_FS_SECURITY)  += xattr_security.o

all:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
