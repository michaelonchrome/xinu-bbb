#include <xinu.h>

int32   clear_malleable(pid32 pid) {

    intmask mask;
    struct procent *prptr;
    mask = disable();
    if (isbadpid(pid)) {
        restore(mask);
        return (int32) SYSERR;
    }

    prptr = &proctab[pid];
    prptr->malleable_state=0;
    restore(mask);
    return prptr->malleable_state;

}