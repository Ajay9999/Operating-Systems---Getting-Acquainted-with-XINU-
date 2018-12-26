/* sleep100.c - sleep100 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * sleep100  --  delay the caller for a time specified in 1/100 of seconds
 *------------------------------------------------------------------------
 */
SYSCALL sleep100(int n)
{
	STATWORD ps;
        unsigned long start_time;
        unsigned long exec_time;

        if(syscall_trace==1){
                start_time = ctr1000;
        }    

	if (n < 0  || clkruns==0)
        {
          if(syscall_trace==1)
               {
                exec_time = ctr1000 - start_time;
                proctab[currpid].syscall_freq[currpid][20]++;
                syscall_time[currpid][20] = syscall_time[currpid][20] + exec_time;
                }
	         return(SYSERR);
        }
	disable(ps);
	if (n == 0) {		/* sleep100(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n*10);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
        if(syscall_trace==1)
               {
                exec_time = ctr1000 - start_time;
                proctab[currpid].syscall_freq[currpid][20]++;
                syscall_time[currpid][20] = syscall_time[currpid][20] + exec_time;
                }
	return(OK);
}
