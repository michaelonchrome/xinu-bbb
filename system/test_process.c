#include <xinu.h>

// Calculation process

void test_process(int32 type) {

    kprintf("Entering test_process \n");
    pid32 pid;
    pid = getpid();
    set_malleable(pid);
    if(type == 0) {
        int i,j;
        j=0;
        i=0;
        set_usage(pid, 1);
        while(1) {
            j=(1+1+1+1)/2;
            i++;
            if(i=10000) {
                kprintf("Suspending HIGH CPU USAGE \n");
                suspend(getpid());
            }
        }
        
    }
    else if(type == 1) {
        set_usage(pid, 2);
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
        set_usage(pid, 3);
        kprintf("Im hungry \n");
        suspend(pid);
        while(1) {

        }
    }
    else {
        kprintf("CANT CREATE PROCESS \n");
        return ;
    }
    
}