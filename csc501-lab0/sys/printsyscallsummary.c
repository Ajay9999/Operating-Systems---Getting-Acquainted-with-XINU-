#include <stdio.h>
#include <kernel.h>
#include <proc.h>
//#include <conf.h>
//int syscall_freq[NPROC][27];
 int syscall_trace=1;
 int syscall_time[NPROC][27];

 char syscall_name[27][20]={"sys_freemem","sys_chprio","sys_getpid","sys_getprio","sys_gettime","sys_kill","sys_receive","sys_recvclr","sys_recvtim",
		"sys_resume","sys_scount","sys_sdelete","sys_send","sys_setdev","sys_setnok","sys_screate","sys_signal","sys_signaln","sys_sleep",
		"sys_sleep10","sys_sleep100","sys_sleep1000","sys_sreset","sys_stacktrace","sys_suspend","sys_unsleep","sys_wait"};

 int i,j;
void syscallsummary_start()
{
 syscall_trace=1;
 initsyscall_freq();
 initsyscall_time();
}
void syscallsummary_stop(){
 syscall_trace = 0;

}
void initsyscall_freq()
{

for(i=0;i<NPROC;i++)
{
//proctab[i].syscallcnt=0;
 for(j=0;j<27;j++)
 {
   proctab[i].syscall_freq[i][j]=0;
 }  
}
}


void initsyscall_time()
{
for(i=0;i<NPROC;i++)
{
for(j=0;j<27;j++)
{
  syscall_time[i][j]=0;
}
}
}


void printsyscallsummary()
{
 kprintf("\nvoid printsyscallsummary()\n");
for(i=0;i<NPROC;i++)
{
if(strlen(proctab[i].pname)>0)
{
//if(proctab[i].pstate==PRFREE)
//{
    kprintf("Process [pid:%d]\n",i);
for(j=0;j<27;j++)
{
    if(proctab[i].syscall_freq[i][j] > 0)
{
//kprintf("Process [pid:%d]\n",i);
    kprintf("\tSyscall: %s, Count: %d, Average execution time: %d (ms)\n",syscall_name[j],proctab[i].syscall_freq[i][j],(int)(syscall_time[i][j]/(proctab[i].syscall_freq[i][j])));
//}
}
}
}
}
}

