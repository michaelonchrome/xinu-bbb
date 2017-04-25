#include<xinu.h>

int32   set_usage(pid32 pid, int32 type) {
    struct procent *ptr;
    intmask mask;
    mask = disable();

    if (isbadpid(pid)) {
        restore(mask);
        return (int32) SYSERR;
    }

    ptr = &proctab[pid];
    ptr->cpu_usage = type;
    restore(mask);
    return ptr->cpu_usage;
}