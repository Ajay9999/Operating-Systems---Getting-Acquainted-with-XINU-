/* resume.c - resume */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * resume  --  unsuspend a process, making it ready; return the priority
 *------------------------------------------------------------------------
 */
SYSCALL resume(int pid)
{
	STATWORD ps;    
	struct	pentry	*pptr;		/* pointer to proc. tab. entry	*/
        unsigned long start_time;
        unsigned long exec_time;

        if(syscall_trace==1){
                start_time = ctr1000;
		proctab[currpid].syscall_freq[currpid][9]++;
        }
	int	prio;			/* priority to return		*/

	disable(ps);
	if (isbadpid(pid) || (pptr= &proctab[pid])->pstate!=PRSUSP) {
		restore(ps);

        if(syscall_trace==1)
               {
                exec_time = ctr1000 - start_time;
//                proctab[currpid].syscall_freq[currpid][9]++;
                syscall_time[currpid][9] = syscall_time[currpid][9] + exec_time;
                }

		return(SYSERR);
	}
	prio = pptr->pprio;
	ready(pid, RESCHYES);
	restore(ps);
        
        if(syscall_trace==1)
               {
                exec_time = ctr1000 - start_time;
 //               proctab[currpid].syscall_freq[currpid][9]++;
                syscall_time[currpid][9] = syscall_time[currpid][9] + exec_time;
                }

	return(prio);
}
