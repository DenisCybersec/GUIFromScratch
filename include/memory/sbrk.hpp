#ifndef SBRK_H
#define SBRK_H
#include<syscall.hpp>
void* msbrk(long increment); // system call for get memory
#endif