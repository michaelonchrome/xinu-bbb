#include <xinu.h>

int32   set_malleable(pid32 pid) {
    struct procent *prptr;
    intmask mask;
    mask = disable();

    if (isbadpid(pid)) {
        restore(mask);
        return (int32) SYSERR;
    }


    prptr = &proctab[pid];
    prptr->malleable_state=1;
    restore(mask);
    return prptr->malleable_state;

}