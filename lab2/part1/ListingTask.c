//name: boen zhang
//lab02
//4/4/2018
//program description: Iterating over tasks linearly

#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>


/* Called when module is loaded */
int ListingTask_init(void)
{


  printk(KERN_INFO "Load ListingTask Module\n");

  struct task_struct *task;

  for_each_process(task){
    printk(KERN_INFO "name: %-s  state: %ld  pid:%d\n", task->comm, task->state, task->pid);
  }


  return 0;
}

/* Called when module is unloaded */
void ListingTask_exit(void){

  printk(KERN_INFO "UnLoading ListingTask Module\n");
}


module_init(ListingTask_init);
module_exit(ListingTask_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Iterating over tasks linearly") ;
MODULE_AUTHOR("boen") ;
