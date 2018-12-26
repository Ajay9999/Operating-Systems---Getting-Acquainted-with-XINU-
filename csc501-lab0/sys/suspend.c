/* suspend.c - suspend */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  suspend  --  suspend a process, placing it in hibernation
 *------------------------------------------------------------------------
 */
SYSCALL	suspend(int pid)
{
	STATWORD ps;    
	struct	pentry	*pptr;		/* pointer to proc. tab. entry	*/
	int	prio;			/* priority returned		*/
        unsigned long start_time;
        unsigned long exec_time;

        if(syscall_trace==1){
                start_time = ctr1000;
        } 

	disable(ps);
	if (isbadpid(pid) || pid==NULLPROC ||
	 ((pptr= &proctab[pid])->pstate!=PRCURR && pptr->pstate!=PRREADY)) {
		restore(ps);
        if(syscall_trace==1)
               {
                exec_time = ctr1000 - start_time;
                proctab[currpid].syscall_freq[currpid][24]++;
                syscall_time[currpid][24] = syscall_time[currpid][24] + exec_time;
                }
		return(SYSERR);
	}
	if (pptr->pstate == PRREADY) {
		pptr->pstate = PRSUSP;
		dequeue(pid);
	}
	else {
		pptr->pstate = PRSUSP;
		resched();
	}
	prio = pptr->pprio;
	restore(ps);
        
        if(syscall_trace==1)
               {
                exec_time = ctr1000 - start_time;
                proctab[currpid].syscall_freq[currpid][24]++;
                syscall_time[currpid][24] = syscall_time[currpid][24] + exec_time;
                }
	return(prio);
}
