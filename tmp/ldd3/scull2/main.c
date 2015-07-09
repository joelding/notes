#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>

MODULE_LICENSE("Dual BSD/GPL");

static dev_t scull_devno;
static int scull_major = 0;
static int scull_minor = 0;
static int scull_nr_devs = 1;

module_param(scull_major, int, S_IRUGO);
module_param(scull_minor, int, S_IRUGO);

#if 0
static ssize_t scull_read(struct file *filp,
			char __user *,
			size_t,
			loff_t *)
{
}

static ssize_t scull_write(struct file *filp,
			char __user *,
			size_t,
			loff_t *)
{
}

#endif
static int scull_open(struct inode *inode,
			struct file *filp)
{
	return 0;
}

static int scull_release(struct inode *inode,
			struct file *filp)
{
	return 0;
}

static struct file_operations scull_fops = {
	.owner = THIS_MODULE,
//	.read = scull_read,
//	.write = scull_write,
	.open = scull_open,
	.release = scull_release,
};

static struct cdev cdev;

static int scull_init(void)
{
	int retval = 0;

	printk(KERN_ALERT "build: %s %s\n", __DATE__, __TIME__);

	if (scull_major) {
		scull_devno = MKDEV(scull_major, scull_minor);
		retval = register_chrdev_region(scull_devno, 
						scull_nr_devs, // count
						"scull" // name
						);
	} else {
		retval = alloc_chrdev_region(&scull_devno, 
						scull_minor, // first minor
						scull_nr_devs, // count
						"scull" // name
						);
	}

	if (retval < 0) {
		printk(KERN_WARNING "%s@%d fail retval=%d\n", __FILE__, __LINE__, retval);
		goto err_get_devno;
	} 
		
	if (scull_major != MAJOR(scull_devno))
		scull_major = MAJOR(scull_devno);

	printk(KERN_ALERT "%s major=%d, minor=%d\n", __func__, MAJOR(scull_devno), MINOR(scull_devno));

	cdev_init(&cdev, &scull_fops);
	cdev.owner = THIS_MODULE;
	cdev.ops = &scull_fops;
	cdev_add(&cdev, MKDEV(scull_major, scull_minor), 1);

err_get_devno:
	return retval;
}

static void scull_exit(void)
{
	printk(KERN_ALERT "%s\n", __func__);
	cdev_del(&cdev);
	unregister_chrdev_region(scull_devno, 1);
}

module_init(scull_init);
module_exit(scull_exit);

