#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include "foo.h"

MODULE_LICENSE("Dual BSD/GPL");

static char *whom = "world";
static int howmany = 1;

module_param(whom, charp, S_IRUGO);
module_param(howmany, int, S_IRUGO);

static int hello_init(void)
{
	printk(KERN_ALERT "%s\n", whom);
	printk(KERN_ALERT "%d\n", howmany);
	printk(KERN_ALERT "%d\n", add(1, 2));
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "%d\n", sub(5, 3));
	printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

