#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>


MODULE_AUTHOR("Maksym Bilych IO-82");
MODULE_DESCRIPTION("Hello world printing Linux module for lab5");
MODULE_LICENSE("Dual BSD/GPL");

static int times = 1;
module_param(times, uint, S_IRUGO);
MODULE_PARM_DESC(times, "The amount of times to print hello world");

static int __init thisinit(void)
{
  uint i = 0;

  if(times == 0)
  {
    printk(KERN_WARNING "Entered parameter equals 0");
  } 
  else if(times >= 5 && times <= 10)
  {
    printk(KERN_WARNING "Entered parameter is between 5 and 10");
  } 
  else if(times > 10)
  {
    printk(KERN_ERR "Entered parameter is bigger than 10");
    return -EINVAL;
  }

  for(i=0; i< times; i++)
  {
    printk(KERN_EMERG "Hello, world!\n");
  }

  printk(KERN_INFO "Times: %d\n", times);

  return 0;
}

static void __exit thisexit(void)
{
  /* Do nothing here right now */
}

module_init(thisinit);
module_exit(thisexit);
