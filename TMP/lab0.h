#ifndef LAB0_H
#define LAB0_H
long zfunction(long param);
void printsegaddress(void);
void printtos(void);
void printprocstks(int priority);
void syscallsummary_start(void);
void syscallsummary_stop(void);
void start_trace(int trace_flag, unsigned long start_time, int pid, const char func_name[]);
void end_trace(int trace_flag, unsigned long end_time, int pid, const char func_name[]);
void printsyscallsummary(void);
int syscallid(const char fname[]);

extern unsigned long ctr1000;
struct syscall_format
{
        char *syscall_name;
        int count;
        unsigned long time;
};

struct pid_page
{
	struct syscall_format sce[27];
};

extern struct pid_page pide[];

extern int trace_flag;
#endif
