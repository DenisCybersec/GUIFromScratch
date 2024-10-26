#include<malloc.hpp>
#include<vector.hpp>
#include<stack.hpp>
#include<threads.h>
#include<queue.hpp>
#include<gtest/gtest.h>
TEST(MEMORY, ALLOCATING)
{
    char* ptr = (char*)mmalloc(1024);
    ptr[1024] = 1;
    mfree(ptr);
    unsigned long long* ptrL = (unsigned long long*)mmalloc(1024*1024*sizeof(unsigned long long));
    ptrL[1024*1024] = 1;
    mfree(ptrL);
}
TEST(VECTOR, VECTOR)
{
    mvector<int> vctr(20);
    for(size_t i = 0;i<1000;i++)
    {
        vctr.push_back(i);
    }
    for(size_t i = 0;i<1000;i++)
    {
        std::cout << vctr.at(i) << " ";
    }
}
TEST(STACK, STACK)
{
    mstack<int> stack(20);
    for(size_t i = 0;i<1000;i++)
    {
        stack.push(i);
    }
    for(size_t i = 0;i<1000;i++)
    {
        std::cout << stack.pop() << " ";
    }
}
TEST(QUEUE,QUEUE)
{
    mqueue<int> q;
    for(size_t i = 0;i<1000;i++)
    {
        q.push(i);
    }
    for(size_t i = 0;i<1000;i++)
    {
        std::cout << q.pop() << " ";
    }
}