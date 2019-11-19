/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
	start_trace(trace_flag, ctr1000, currpid, __func__);
extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
	{
		end_trace(trace_flag, ctr1000, currpid, __func__);
		return(SYSERR);
	}

	end_trace(trace_flag, ctr1000, currpid, __func__);
	return(semaph[sem].semcnt);
}
