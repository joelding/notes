#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

static dev_t scull_devno;
static int scull_major = 0;
static int scull_minor = 0;
static int scull_nr_devs = 1;

module_param(scull_major, int, S_IRUGO);
module_param(scull_minor, int, S_IRUGO);

#define BUF_LEN 80
static char message[BUF_LEN];

static ssize_t scull_read(struct file *filp,
			char __user *buffer,
			size_t count,
			loff_t *offset)
{
	ssize_t retval = 0;

	printk(KERN_DEBUG "%s count=%d\n", __func__, count);
	#if 0
	if (*offset == 0) {
		retval = 0;
		goto err_0;
	}
	#endif
	if (copy_to_user(buffer, message, BUF_LEN)) {
		retval = -EFAULT;
		goto err_0;
	}

	retval = strlen(message);
	memset(message, 0, BUF_LEN);
	printk(KERN_DEBUG "%s retval=%d\n", __func__, retval);
err_0:
	return retval;
}

static ssize_t scull_write(struct file *filp,
			const char __user *buffer,
			size_t count,
			loff_t *offset)
{
	ssize_t retval = 0;


	printk(KERN_DEBUG "%s count=%d\n", __func__, count);
	
	memset(message, 0, BUF_LEN);
	if (copy_from_user(message, buffer, count)) {
		retval = -EFAULT;
		goto err_0;
	}

	*offset += count;
	return count;

err_0:
	return retval;
}

//static struct cdev cdev;
struct scull_dev {
	struct cdev cdev;
} *scull_devices;

static int scull_open(struct inode *inode,
			struct file *filp)
{
	struct scull_dev *dev;

	printk(KERN_DEBUG "%s\n", __func__);
       	dev = container_of(inode->i_cdev, struct scull_dev, cdev);
	filp->private_data = dev;
	
	return 0;
}

static int scull_release(struct inode *inode,
			struct file *filp)
{
	printk(KERN_DEBUG "%s\n", __func__);

	return 0;
}

static struct file_operations scull_fops = {
	.owner = THIS_MODULE,
	.read = scull_read,
	.write = scull_write,
	.open = scull_open,
	.release = scull_release,
};

static int scull_init(void)
{
	int retval = 0;

	printk(KERN_DEBUG "build: %s %s\n", __DATE__, __TIME__);

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
		printk(KERN_WARNING "Fail to get major %d\n", scull_major);
		return retval;
	} 
		
	if (scull_major != MAJOR(scull_devno))
		scull_major = MAJOR(scull_devno);

	printk(KERN_DEBUG "%s major=%d, minor=%d\n", __func__, MAJOR(scull_devno), MINOR(scull_devno));

	scull_devices = kmalloc(sizeof(struct scull_dev), GFP_KERNEL);
	if (!scull_devices) {
		retval = -ENOMEM;
		goto err_0;
	}
	memset(scull_devices, 0, sizeof(struct scull_dev));

	cdev_init(&(scull_devices->cdev), &scull_fops);
	scull_devices->cdev.owner = THIS_MODULE;
//	scull_devices->cdev.ops = &scull_fops;
	if ((retval = cdev_add(&(scull_devices->cdev), MKDEV(scull_major, scull_minor), 1)) < 0) {
		printk(KERN_WARNING "Fail to add a char device to the system\n");
		goto err_1;
	}

	return 0;
err_1:
	kfree(scull_devices);
err_0:
	unregister_chrdev_region(scull_devno, 1);

	return retval;
}

static void scull_exit(void)
{
	printk(KERN_DEBUG "%s\n", __func__);
	cdev_del(&scull_devices->cdev);
	kfree(scull_devices);
	unregister_chrdev_region(scull_devno, 1);
}

module_init(scull_init);
module_exit(scull_exit);

