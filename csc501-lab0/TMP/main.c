/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int prX;
void halt();

prch(c)
char c;
{
	int i;
	sleep(5);	
}

int main()
{
	kprintf("\nHello World, Xinu lives\n");
        kprintf("********************************\n\n");
        kprintf("\nlong zfunction(long param)\n");
        kprintf("\nThe value is 0x%08x\n",zfunction(0xaabbccdd));
        kprintf("*********************************\n\n");
        printsegaddress();
        printtos();
        printprocstks(10);
        syscallsummary_start();
        resume(prX = create(prch,2000,20,"proc X",1,'A'));
	sleep(10);
        sleep(5);
        syscallsummary_stop();         
        printsyscallsummary();
        kprintf("********************************\n\n");
        return 0;
}
