#include <xinu.h>
#include <stdio.h>
#include <string.h>

shellcmd xsh_malleable(int nargs, char *args[]) {
    
    pid32 pid;
    char ch;
    char *m_flag;

    if (nargs ==1) {
        kprintf("Error: Requires PID for malleable flag\n");
        return 1;
    }
    else if ( nargs == 2) {
        m_flag = args[1];
        ch = *m_flag++;
        
         while(ch != NULLCH) {
            if ((ch < '0') || (ch > '9')) {
                kprintf("%s: non-digit in priority\n", args[1]);
                return 1;
            }
            pid = 10*pid + (ch - '0');
            ch = *m_flag++;
         }

    }
    else {
        kprintf("Too many arguments \n");
        return 1;
    }
    set_malleable(pid);
}
