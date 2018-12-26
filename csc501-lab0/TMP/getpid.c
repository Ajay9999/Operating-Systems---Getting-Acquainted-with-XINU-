/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include<lab0.h>

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
        unsigned long start_time;
	unsigned long exec_time;
    
	if(syscall_trace==1){
		start_time = ctr1000;
	}
	
	if(syscall_trace==1){
		exec_time = ctr1000 - start_time;
		proctab[currpid].syscall_freq[currpid][2]++;
		syscall_time[currpid][2] = syscall_time[currpid][2] + exec_time;
	}
	return(currpid);
}
