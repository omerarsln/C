#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/string.h>
#include <linux/file.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <linux/delay.h>
#include <asm/uaccess.h>

#define FILE_DIR "/dev/ttyACM0"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Character Device Driver");
MODULE_AUTHOR("Omer Arslan");

static char msg[100];
static short readPos = 0;
static int times = 0;

static int dev_open(struct inode *, struct file *);
static int dev_rls(struct inode *, struct file *);

static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

static void write_file(const char *, const char *);

static struct file_operations cmd_file_ops = {
    .read = dev_read,
    .open = dev_open,
    .write = dev_write,
    .release = dev_rls};

int init_module()
{
    int MajorNum = register_chrdev(91, "FormatDev", &cmd_file_ops);

    if (MajorNum < 0)
        printk(KERN_ALERT "Aygıt ekleme basarisiz... \n");
    else
        printk(KERN_INFO "Aygit eklendi\n");

    return MajorNum;
}

void cleanup_module()
{
    unregister_chrdev(91, "FormatDev");
    printk(KERN_INFO "Aygit kaldirildi");
}

static int dev_open(struct inode *inod, struct file *fil)
{
    times++;
    printk(KERN_INFO "Aygit %d kere acildi\n", times);
    return 0;
}

static ssize_t dev_read(struct file *filp, char *buff, size_t len, loff_t *off)
{
    short count = 0;

    while (len && (msg[readPos] != 0))
    {
        put_user(msg[readPos], buff++);
        count++;
        len--;
        readPos++;
    }

    return count;
}

static ssize_t dev_write(struct file *filp, const char *buff, size_t len, loff_t *off)
{
    short ind = 0;
    short count = 0;
    memset(msg, 0, 100);
    readPos = 0;
    while (len > 0)
    {
        msg[count++] = buff[ind++];
        len--;
    }
    write_file(FILE_DIR, msg);

    return count;
}

static int dev_rls(struct inode *inod, struct file *fil)
{
    printk(KERN_INFO "Aygit Kapatildi\n");
    return 0;
}

static void write_file(const char *filename, const char *data)
{
    struct file *filp;
    mm_segment_t oldfs;
    int ret;
    int count;
    filp = filp_open(filename, O_RDWR | O_APPEND, 0644);

    if (IS_ERR(filp))
    {
        printk("Dosya Acma Hatasi ...\n");
        return;
    }
    for (count = 0; data[count] != '\0'; count++)
        ;

    msleep(5000);

    printk(KERN_INFO "Mesaj : %s", data);

    oldfs = get_fs();
    set_fs(get_fs());
    ret = vfs_write(filp, data, count, &filp->f_pos);

    set_fs(oldfs);
    filp_close(filp, NULL);
}