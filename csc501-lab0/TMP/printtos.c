#include<stdio.h>
unsigned long *bp;
unsigned long *sp;

void printtos()
{
       // int i=0;
        //int j=0;
       // asm("movl %esp,%ebp");
       asm("movl %ebp,bp");
        //asm("movl %esp,sp");
        	
	kprintf("\nvoid printtos()\n");
	kprintf("\nAddress and contents before the function call [0x%08x]:0x%08x\n",(bp+2),*(bp+2));
	kprintf("\nAddress and contents after the function call [0x%08x]:0x%08x\n",bp,*bp);
        printstacks();
}

void printstacks()
{
        int i=0,stackloc[4],j;
        asm("movl %ebp,bp");
        asm("movl %esp,sp");
        for(j=0;j<4;j++)
        {
        stackloc[j]=j;
        }
        int stackdiff = bp-sp+1;      
        while((stackdiff>0) && (i<=3))
        {
     
	kprintf("\tElements in stack of content [0x%08x]:0x%08x\n", (sp+i),*(sp+i));
        i++;
        stackdiff--;
        }

        kprintf("********************************\n\n");

}




