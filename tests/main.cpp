#include<gtest/gtest.h>
#include<iostream>
#include<hashmap.hpp>
#include<io.hpp>
#include<thread.hpp>
void func(void* arg)
{
    *(int*)arg = 10;
    int uuid = getpid();
    mprint("He110 from n3w thr3ad\n",23);
    mprintInt(uuid);
    mprint("\n",1);
}
int main()
{
    //::testing::InitGoogleTest();
    //return RUN_ALL_TESTS();
    int ptr = 12;
    func(&ptr);
    thread nThread = thread(func,&ptr);
}