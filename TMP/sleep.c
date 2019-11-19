/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep(int n)
{	
	start_trace(trace_flag, ctr1000, currpid, __func__);
	STATWORD ps;    
	if (n<0 || clkruns==0)
	{
		end_trace(trace_flag, ctr1000, currpid, __func__);
		return(SYSERR);
	}
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		end_trace(trace_flag, ctr1000, currpid, __func__);
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);
	end_trace(trace_flag, ctr1000, currpid, __func__);
	return(OK);
}
