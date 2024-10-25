#ifndef SYSCALL_H
#define SYSCALL_H
void* msyscall(long number, void* arg);
void* msyscall(long number, void* arg1,void* arg2,unsigned long arg3);
#endif