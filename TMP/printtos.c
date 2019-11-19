#include <stdio.h>
#include <kernel.h>

unsigned long *esp, *ebp;

void printtos(void)
{
	asm("movl %esp,esp");
	asm("movl %ebp,ebp");
	
	kprintf("\n\nBefore[0x%08lx]: 0x%08lx", ebp+2, *(ebp+2));
	kprintf("\nAfter [0x%08lx]: 0x%08lx", ebp, *(ebp));
	
	int i;
	for(i=0; i<4 && esp<ebp; i++)
		kprintf("\n\telement[0x%08lx]: 0x%08lx", esp+i, *(&esp+i));
}
