/* getprio.c - getprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * getprio -- return the scheduling priority of a given process
 *------------------------------------------------------------------------
 */
SYSCALL getprio(int pid)
{
	start_trace(trace_flag, ctr1000, currpid, __func__);
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		end_trace(trace_flag, ctr1000, currpid, __func__);
		return(SYSERR);
	}
	restore(ps);
	end_trace(trace_flag, ctr1000, currpid, __func__);
	return(pptr->pprio);
}
