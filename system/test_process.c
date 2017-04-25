#include <xinu.h>

// Calculation process

void test_process(int32 type) {
    kprintf("Entering test_process \n");
    
    int i;
    if(type == 0) {

        while(1) {
            i = (10+2)/2;
        }
    }
    else if(type == 1) {
        int j;
        for(j=0; j<100; j++) {
            kprintf("%d. CPU IO PROCESS in ACTION \n", j);
        }
        
        kprintf("Waiting for a signal now \n");
        wait(g_sem);
        kprintf("Unlocked! \n");
        for(j=0; j<100; j++) {
            kprintf("%d ROUND 2 CPU IO PROCESS in ACTION \n", j);
        }

    }
    else if(type == 2) {
        kprintf("Im hungry \n");
        while(1) {

        }
    }
    else {
        kprintf("CANT CREATE PROCESS \n");
        return ;
    }
    
}