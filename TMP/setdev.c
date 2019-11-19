/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	start_trace(trace_flag, ctr1000, currpid, __func__);
	short	*nxtdev;

	if (isbadpid(pid))
	{
		end_trace(trace_flag, ctr1000, currpid, __func__);
		return(SYSERR);
	}
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
	end_trace(trace_flag, ctr1000, currpid, __func__);
	return(OK);
}
