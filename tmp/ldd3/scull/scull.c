#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>

MODULE_LICENSE("Dual BSD/GPL");

static dev_t scull_dev;
static int scull_major = 0;
static int scull_minor = 0;

module_param(scull_major, int, S_IRUGO);
module_param(scull_minor, int, S_IRUGO);

static int scull_init(void)
{
	int retval = 0;

	do {
		if (scull_major) {
			scull_dev = MKDEV(scull_major, scull_minor);
			if ((retval = register_chrdev_region(scull_dev, 
								1, // count
								"scull" // name
								))) {
				printk(KERN_ALERT "%s@%d fail retval=%d\n", __FILE__, __LINE__, retval);
				break;
			}
			
			printk(KERN_ALERT "%s major=%d, minor=%d\n", __func__, MAJOR(scull_dev), MINOR(scull_dev));
		} else {
			if ((retval = alloc_chrdev_region(&scull_dev, 
								0, // first minor
							       	1, // count
								"scull" // name
								))) {
				printk(KERN_ALERT "%s@%d fail retval=%d\n", __FILE__, __LINE__, retval);
				break;
			}
		
			printk(KERN_ALERT "%s major=%d, minor=%d\n", __func__, MAJOR(scull_dev), MINOR(scull_dev));
		}

	} while (0);

	return retval;
}

static void scull_exit(void)
{
	printk(KERN_ALERT "%s\n", __func__);
	unregister_chrdev_region(scull_dev, 1);
}

module_init(scull_init);
module_exit(scull_exit);

