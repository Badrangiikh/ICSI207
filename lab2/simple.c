#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/list.h>

/* birthday struct iig zarlaj bga ni */ 

struct birthday{
	int day;
	int month;
	int year;
	struct list_head list;
};

/* LIST HEAD in list.h dotor baidag. Eniig zarlaad linked listee uusgene */ 
static LIST_HEAD(birthday_list);

/* This function is called when the module is loaded. */
int simple_init(void){
    printk(KERN_INFO "Loading Module\n");
	struct birthday *person;
	int i=0;
	while(i<5){
        /* kmalloc ni kernel-d sanah oi nuutsluh arga. Slab.h iin tuslamjtai kmalloc iig hereglene. */ 
        /* GFP_KERNEL ni engiin kerneliin ramiig nuutsludug */ 
		person=kmalloc(sizeof(*person),GFP_KERNEL);
		person->day=2+i; 
        person->month=8+i; 
        person->year=1995+i;
        /* INIT_LIST_HEAD ni list.h-d baidag */ 
		INIT_LIST_HEAD(&person->list);
		list_add_tail(&person->list, &birthday_list);
		i++;
	}
    /* i iin utgiig shinechleh */ 
	i=1;
    /* list_for_each_entry ni list.h iinh buguud ugugdsun ugugdliin turliin listeer guideg */ 
	list_for_each_entry(person,&birthday_list,list){
		printk(KERN_INFO "%d amjilttai",i++);
	}
	printk(KERN_INFO "Linked listiig amjilttai uusgelee\n");
    return 0;
}

/* This function is called when the module is removed. */
/* Ene funktseer kerneliin sanah oigoos linked list-iig ustgana */ 
void simple_exit(void) {
	int i=1;
    struct birthday *ptr, *next;
	printk(KERN_INFO "Removing Module\n");
	list_for_each_entry_safe(ptr,next,&birthday_list,list){
		/* on each iteration ptr points to the next birthday struct */
		list_del(&ptr->list);
		kfree(ptr);
		printk(KERN_INFO "%d-r element amjilttai ustgagdlaa",i++);
	}
	printk(KERN_INFO "Listuudiig ustgaj duuslaa \n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");