/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <proc.h>
#include <lab0.h>

extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
	start_trace(trace_flag, ctr1000, currpid, __func__);
    /* long	now; */

	/* FIX ME -- no getutim */
	end_trace(trace_flag, ctr1000, currpid, __func__);
	return OK;
}
