/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");
	syscallsummary_start();
	printsegaddress();
	printtos();
	printprocstks(0);
	sleep(1);
	getprio(getpid());
	syscallsummary_stop();
	printsyscallsummary();
	return 0;
}
