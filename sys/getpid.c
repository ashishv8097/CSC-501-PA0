/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	start_trace(trace_flag, ctr1000, currpid, __func__);
	end_trace(trace_flag, ctr1000, currpid, __func__);
	return(currpid);
}
