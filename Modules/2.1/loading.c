#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
static int hello_init(void){
	//printk(KERN_INFO "%s: In init\n", __func__);
	//printk (KERN_EMERG "TEST: Kernel Loaded EMERG\n");
	//printk (KERN_CRIT "TEST: Kernel Loaded CRIT\n");
	printk (KERN_ALERT "Kernel Module Loaded\n");
	//printk (KERN_ERR "TEST: Kernel Loaded ERR\n");
	//printk (KERN_WARNING "TEST: Kernel Loaded WARNING\n");
	//printk (KERN_NOTICE "TEST: Kernel Loaded NOTICE\n");
	//printk (KERN_INFO "TEST: Kernel Loaded INFO\n");
	//printk (KERN_DEBUG "TEST: Kernel Loaded DEBUG\n");
	return 0;
}

static void hello_exit(void){
	//printk(KERN_INFO "%s: In exit\n", __func__);
	printk(KERN_ALERT "Kernel Module Removed\n");
}

module_init(hello_init);
module_exit(hello_exit);
