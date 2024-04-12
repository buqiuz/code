#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "simple_char_device"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A complex kernel module with character device");

static int major_number;
static char message[256] = "Hello from the kernel!\n";
static int message_size = 0;

static int device_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    return 0;
}

static ssize_t device_read(struct file *file, char __user *buffer, size_t length, loff_t *offset)
{
    int bytes_read = 0;
    if (*offset >= message_size)
        return 0;
    while (length && (message_size - *offset)) {
        put_user(message[*offset], buffer++);
        *offset += 1;
        length--;
        bytes_read++;
    }
    return bytes_read;
}

static ssize_t device_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset)
{
    int bytes_written = 0;
    int space_available = sizeof(message) - *offset;
    if (length > space_available)
        return -ENOSPC;
    if (copy_from_user(message + *offset, buffer, length))
        return -EFAULT;
    *offset += length;
    message_size = *offset;
    return length;
}

static struct file_operations fops = {
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write,
};

static int __init complex_init(void)
{
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "Registered correctly with major number %d\n", major_number);
    printk(KERN_INFO "Create a device with `mknod /dev/%s c %d 0`\n", DEVICE_NAME, major_number);
    return 0;
}

static void __exit complex_exit(void)
{
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Unregistered the device\n");
}

module_init(complex_init);
module_exit(complex_exit);
