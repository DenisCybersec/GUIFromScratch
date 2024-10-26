#ifndef IO_H
#define IO_H
#include<types.hpp>
#include<pow.hpp>
#include<malloc.hpp>
void mprint(char* buf,size_t size); // output first size elements from buffer 
void mprintInt(int buf); // print integer normally 123 -> "123"
void mread(char* buf,size_t size); // read from stdint
#endif