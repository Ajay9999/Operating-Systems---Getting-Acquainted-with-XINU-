#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

unsigned long *sp;

void printprocstks(int priority)
{

           kprintf("\nvoid printprocstks(int %d)\n",priority);
int i=0;
while(i<=NPROC)
{

if(proctab[i].pprio > priority)
{
            kprintf("Process Name: [%s]\n", proctab[i].pname);
            kprintf("\tProces ID (pid): %d\n",getpid()); 
            kprintf("\tProcess priority: %d\n",proctab[i].pprio);
            kprintf("\tbase of run time stack: 0x%08x\n",proctab[i].pbase);
            kprintf("\tlimit of stack for process: 0x%08x\n",proctab[i].plimit);
            kprintf("\tStack lenght: %d\n",proctab[i].pstklen);
if(i==currpid){
            asm("movl %esp,sp");
            kprintf("\tStack pointer: 0x%08x\n", sp);
}
else
            kprintf("Stored value of stack pointer: 0x%08x\n",proctab[i].pesp);
}
i++;
}
kprintf("********************************\n\n");
}


