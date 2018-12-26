/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep(int n)
{
	STATWORD ps;
        unsigned long start_time;
	unsigned long exec_time;
    
	if(syscall_trace==1){
		start_time = ctr1000;
	}
    
	if (n<0 || clkruns==0)
        {
          if(syscall_trace==1)
               {
		exec_time = ctr1000 - start_time;
		proctab[currpid].syscall_freq[currpid][18]++;
		syscall_time[currpid][18] = syscall_time[currpid][18] + exec_time;
		}
        
		return(SYSERR);
         }
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
          if(syscall_trace==1)
               {
                exec_time = ctr1000 - start_time;
                proctab[currpid].syscall_freq[currpid][18]++;
                syscall_time[currpid][18] = syscall_time[currpid][18] + exec_time;
                }
        	return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
        {
		sleep10(10*n);
          if(syscall_trace==1)
               {
                exec_time = ctr1000 - start_time;
                proctab[currpid].syscall_freq[currpid][18]++;
                syscall_time[currpid][18] = syscall_time[currpid][18] + exec_time;
                }
	return(OK);
        }
}
