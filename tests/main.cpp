#include<gtest/gtest.h>
#include<iostream>
#include<hashmap.hpp>
int main()
{
    //::testing::InitGoogleTest();
    //return RUN_ALL_TESTS();
    mhashmap<size_t,size_t> mp;
    std::cout << "!!!!\n" << std::endl;
    mp.insert(1026,2);
    mp.insert(2,10);
    std::cout << mp.get(1026) << std::endl;;
    std::cout << mp.get(2) << std::endl;
}