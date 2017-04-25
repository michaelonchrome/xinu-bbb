#include <xinu.h>
#include <stdio.h>
#include <string.h>

shellcmd xsh_signal_s(void) {
    kprintf("Signaling the global semaphore\n");
    signal(g_sem);
}