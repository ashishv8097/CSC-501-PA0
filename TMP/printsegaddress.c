#include <stdio.h>

extern unsigned long etext, edata, end;

void printsegaddress(void)
{
	kprintf("\n\nCurrent:");
		kprintf(" etext[0x%08lx]=0x%08lx,", &etext, etext);
		kprintf(" edata[0x%08lx]=0x%08lx,", &edata, edata);
		kprintf(" ebss[0x%08lx]=0x%08lx", &end, end);

	kprintf("\nPreceding:");
		kprintf(" etext[0x%08lx]=0x%08lx,", &etext-1, *(&etext-1));
		kprintf(" edata[0x%08lx]=0x%08lx,", &edata-1, *(&edata-1));
		kprintf(" ebss[0x%08lx]=0x%08lx", &end-1, *(&end-1));

	kprintf("\nAfter:");
		kprintf(" etext[0x%08lx]=0x%08lx,", &etext+1, *(&etext+1));
		kprintf(" edata[0x%08lx]=0x%08lx,", &edata+1, *(&edata+1));
		kprintf(" ebss[0x%08lx]=0x%08lx", &end+1, *(&end+1));
}
