#include<sbrk.hpp>
#include<types.hpp>
void* mmalloc(size_t size);
void mfree(void* ptr);
void* mrealloc(void* ptr, size_t size);