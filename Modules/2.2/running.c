#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>

struct task_struct *task;	// Structure defined in sched.h for task/processes
struct task_struct *task_child;	// Structure needed to iterate through task children
struct list_head *list;	// Structure needed to iterate throught the list in each task task->children struct 

int iterate_init(void)		// Init Module
{
	printk(KERN_INFO "%s","LOADING MODULE\n");
	
	for_each_process( task ){
		//printk(KERN_INFO "\nPARENT PID: %d PROCESS: %s STATE: %ld", task->pid, task->comm, task->state);
		printk(KERN_INFO "\nPID: %d CMD: %s STATE: %ld", task->pid, task->comm, task->state);
		list_for_each(list, &task->children){
			task_child = list_entry( list, struct task_struct, sibling );
			
			//printk(KERN_INFO "\nCHILD OF %s[%d] PID: %d PROCESS %s STATE: %ld", task->comm, task->pid, task_child->pid, task_child->comm, task_child->state);
			printk(KERN_INFO "\nPID: %d CMD: %s STATE: %ld", task_child->pid, task->comm, task_child->state);
		}
		printk("----------------------------------");
	}
	
	
	return 0;
	
}

void cleanup_exit(void)
{
	printk(KERN_INFO "%s", "REMOVING MODULE\n");
	
}

module_init(iterate_init);
module_exit(cleanup_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("ITERATE THROUGH ALL PROCESSES/ CHILD PROCESSES IN THE OS");
MODULE_AUTHOR("Laerehte");

