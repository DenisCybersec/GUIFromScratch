#include<sbrk.hpp>
#include<types.hpp>
void* mmalloc(size_t size); // dynamicly allocate memory 
void mfree(void* ptr); // free allocated memory
void* mrealloc(void* ptr, size_t size); // reallocate memory with memcpy