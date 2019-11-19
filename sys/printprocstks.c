#include <stdio.h>
#include <kernel.h>
#include <proc.h>

unsigned long *esp;

void printprocstks(int priority)
{
	int pid;
	struct pentry *proc;
	
	kprintf("\n");

	for(pid=0; pid<NPROC; pid++)
	{
		proc = &proctab[pid];	
		
		if (proc->pprio>priority && proc->pstate!=PRFREE)
		{
			kprintf("\nProcess\t[%s]", proc->pname);
			kprintf("\n\tpid: %d", pid);
			kprintf("\n\tpriority: %d", proc->pprio);
			kprintf("\n\tbase: 0x%08lx", proc->pbase);
			kprintf("\n\tlimit: 0x%08lx", proc->plimit);
			kprintf("\n\tlen: %d", proc->pstklen);
			
			if (pid == currpid)
				asm("movl %esp,esp");
			else
				esp = (unsigned long*)proc->pesp;
			kprintf("\n\tpointer: 0x%08lx", esp);		
		}
	}
}
