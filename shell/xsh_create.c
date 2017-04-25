#include <xinu.h>
#include <stdio.h>
#include <string.h>

shellcmd xsh_create(int nargs, char *args[]) {

    pid32   pid;
    pri16   priority;
    int32   type;
    char    *name_process = "";
    // Stores address of function to call
    // This is determined through set logic and 
    // args passed in by the user.
    void    *func_to_call;
   

    if (nargs == 1) {
        kprintf("Not enough args \n");
    }
    else if ( nargs == 2 ) {
            func_to_call = "test_process";

            if(strncmp(args[1], "cpu_b", 6) == 0) {
                kprintf("Creating a CPU-Bound Process \n");
                name_process = "CPU-BOUND";
                priority = 50;
                type = 0;
            }
            else if(strncmp(args[1], "cpu_io", 7) == 0) {
                kprintf("Creating a Interactive Process \n");
                name_process = "CPU-IO";
                priority = 40;
                type = 1;
            }
            else if(strncmp(args[1], "cpu_hungry",11 ) == 0) {
                kprintf("Creating a straving process \n");
                name_process = "Hungry";
                priority = 5;
                type = 2;
            }
            else {
                kprintf("Not a correct arg \n");
                return 1;
            }
    }
    else {
        kprintf("Too many arguments\n");
        return 1;
    }
    kprintf("Out of the big else if statement \n");
    pid = create(test_process, 1024, priority, name_process, 1, type);
    if(type==2) {
        return 0;
    }
    else {
        kprintf("Resuming \n");
        resume(pid);
        return 0;
    }
}
