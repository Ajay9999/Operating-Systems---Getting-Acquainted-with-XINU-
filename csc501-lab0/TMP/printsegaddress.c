#include <stdio.h>
extern long  etext, edata, end;   //Global variables which point to memory addresses

void printsegaddress()
{
	kprintf("\nvoid printsegaddress()\n");
        kprintf("\nAddress and contents of end of segments:etext[0x%08x]=0x%08x,edata[0x%08x]=0x%08x,ebss[0x%08x]=0x%08x\n",(&etext),*(&etext),(&edata),*(&edata),(&end),*(&end));
	kprintf("\nAddress and contents of preeceding end of segements :etext[0x%08x]=0x%08x,edata[0x%08x]=0x%08x,ebss[0x%08x]=0x%08x\n",(&etext - 1),*(&etext-1),(&edata - 1),*(&edata-1),(&end-1),*(&end-1));
	kprintf("\nAddress and contents of after end of segments :etext[0x%08x]=0x%08x,edata[0x%08x]=0x%08x,ebss[0x%08x]=0x%08x\n",(&etext+1),*(&etext+1),(&edata+1),*(&edata+1),(&end+1),*(&end+1));
        kprintf("********************************\n\n");
}
