extern long zfunction (long param);
extern void printsegaddress();
extern void printtos();
extern void printprocstks(int priority);
unsigned long ctr1000;
extern int syscall_trace;
//extern int syscall_freq[NPROC][27];
extern int syscall_time[NPROC][27];
void printsyscallsummary();
void initsyscall_time();
void initsyscall_freq();
void syscallsummary_start();
void syscallsummary_stop();
 
