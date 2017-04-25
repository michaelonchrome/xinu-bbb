#include <xinu.h>
#include <stdio.h>
#include <string.h>

void reprio(void) {
    struct procent *ptr; 
    int32 i = 0;
    for(i=0; i<NPROC; i++) {
        ptr = &proctab[i];
        pri16 new_p = 0;
        if(ptr->prstate == PR_FREE) {
            continue;
        }
        if(ptr->malleable_state==1) {
            kprintf("\n");
            kprintf("Current NPROC %d \n", NPROC);
            kprintf("Process Name : %s \n", ptr->prname);
            kprintf("Process prio: %d \n", ptr->prprio);
            kprintf("PID : %d \n", i);
            new_p = ptr->prprio;
            if(ptr->cpu_usage==1) {
                clear_malleable(pid);
                new_p = new_p/2;

            }
            else if(ptr->cpu_usage==2) {
                new_p = ptr->prprio;
            }
            else if (ptr->cpu_usage==3) {
                clear_malleable(pid);
                new_p = 150;
            }
            else {
                continue;
            }

             if(ptr->prprio != new_p) {
            kprintf("Changing P of %s \n", ptr->prname);
            chprio(i, new_p);
        }
        }
       
    }
    return;
}