//name: boen zhang
//lab02
//4/4/2018
//program description: Iterating over tasks using DFS

#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

/* list_for_each() dfs */
void dfs(struct task_struct *task){
  struct task_struct *task_next;
  struct list_head *list;

  list_for_each(list, &task->children) {
    task_next = list_entry(list, struct task_struct, sibling);

    printk(KERN_INFO "name: %-s  state: %ld  pid:%d\n", task_next->comm, task_next->state, task_next->pid);

    dfs(task_next);
  }  
}



/* Called when module is loaded */
int DFSTree_init(void){
  printk(KERN_INFO "Load DFSTree Module\n");

  dfs(&init_task);

  return 0;
}



/* Called when module is unloaded */
void DFSTree_exit(void){
  printk(KERN_INFO "UnLoading DFSTree Module\n");
}

module_init(DFSTree_init);
module_exit(DFSTree_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Iterating over tasks using DFS") ;
MODULE_AUTHOR("boen") ;
