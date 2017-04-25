/*  main.c  - main */

#include <xinu.h>

sid32 g_sem;

process	main(void)
{

	/* Run the Xinu shell */
	g_sem = semcreate(0);


	recvclr();
	resume(create(shell, 8192, 50, "shell", 1, CONSOLE));

	/* Wait for shell to exit and recreate it */

	while (TRUE) {
		receive();
		sleepms(200);
		kprintf("\n\nMain process recreating shell\n\n");
		resume(create(shell, 4096, 20, "shell", 1, CONSOLE));
	}
	return OK;
    
}
