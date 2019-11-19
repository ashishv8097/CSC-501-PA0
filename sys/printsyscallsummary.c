#include <stdio.h>
#include <conf.h>
#include <lab0.h>

struct pid_page pide[NPROC];
int trace_flag=0;

unsigned long stime;

void syscallsummary_start(void)
{
	int pid, syscallid;
	for(pid=0; pid<NPROC; pid++)
		for(syscallid=0; syscallid<27; syscallid++)
		{
			pide[pid].sce[syscallid].count=0;
			pide[pid].sce[syscallid].time=0;
		}
	
	trace_flag=1;
}

void syscallsummary_stop(void)
{
	trace_flag=0;
}

void printsyscallsummary(void)
{
	int pid, sid;

	kprintf("\n");
	
	for(pid=0; pid<NPROC; pid++)
        {	
		int fprint_done=0;
	        for(sid=0; sid<27; sid++)
                {
                        if(pide[pid].sce[sid].count>0)
			{
				if (fprint_done==0)
				{
					kprintf("\nProcess [pid:%d]", pid);
					fprint_done=1;
				}
				kprintf("\n\tSyscall: %s, ", pide[pid].sce[sid].syscall_name);
				kprintf("count: %d, ", pide[pid].sce[sid].count);
				kprintf("average execution time: %lu (ms)", pide[pid].sce[sid].time / pide[pid].sce[sid].count);
                	}
		}
	}
}

void start_trace(int trace_flag, unsigned long start_time, int pid, const char func_name[])
{
	if(trace_flag)
	{
                int sid = syscallid(func_name);
		if(pide[pid].sce[sid].count==0)
			pide[pid].sce[sid].syscall_name=(char *)func_name;
                pide[pid].sce[sid].count++;
		stime = start_time;
	}
}

void end_trace(int trace_flag, unsigned long end_time, int pid, const char func_name[])
{
	if(trace_flag)
        {	
		int sid = syscallid(func_name);
		unsigned long exec_time = end_time - stime;
		pide[pid].sce[sid].time = pide[pid].sce[sid].time + exec_time;
	}
}

int syscallid(const char fname[])
{
    if(!strcmp(fname,"chprio"))			return 0;
    else if(!strcmp(fname,"freemem"))		return 1;
    else if(!strcmp(fname,"getpid"))		return 2;
    else if(!strcmp(fname,"getprio"))		return 3;
    else if(!strcmp(fname,"gettime"))		return 4;
    else if(!strcmp(fname,"kill"))		return 5;
    else if(!strcmp(fname,"receive"))		return 6;
    else if(!strcmp(fname,"recvclr"))		return 7;
    else if(!strcmp(fname,"recvtim"))		return 8;
    else if(!strcmp(fname,"resume"))		return 9;
    else if(!strcmp(fname,"scount"))		return 10;
    else if(!strcmp(fname,"screate"))		return 11;
    else if(!strcmp(fname,"sdelete"))		return 12;
    else if(!strcmp(fname,"send"))		return 13;
    else if(!strcmp(fname,"setdev"))		return 14;
    else if(!strcmp(fname,"setnok"))		return 15;
    else if(!strcmp(fname,"signal"))		return 16;
    else if(!strcmp(fname,"signaln"))		return 17;
    else if(!strcmp(fname,"sleep"))		return 18;
    else if(!strcmp(fname,"sleep10"))		return 19;
    else if(!strcmp(fname,"sleep100"))		return 20;
    else if(!strcmp(fname,"sleep1000"))		return 21;
    else if(!strcmp(fname,"sreset"))		return 22;
    else if(!strcmp(fname,"stacktrace"))	return 23;
    else if(!strcmp(fname,"suspend"))		return 24;
    else if(!strcmp(fname,"unsleep"))		return 25;
    else if(!strcmp(fname,"wait")) 		return 26;
    else 					return 27;
}
