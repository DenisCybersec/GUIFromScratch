#include<io.hpp>
#include<malloc.hpp>
#include<pow.hpp>
#include<syscall.hpp>
void print(char* buf, size_t size)
{
    syscall(1,(void*)1,buf,size);
}
void read(char* buf, size_t size)
{
    syscall(0,(void*)0,buf,size);
}
void printInt(int number)
{
        int length = 0;
        int tempNumber = number;
        if(number < 0) // case that number is negative
        {
            print("-",1);
            tempNumber = -number;
        }
        for(size_t j = 1;j<=10;j++) // get digit amount 
        {
            if(tempNumber < pow(10,j)) 
            {
                length = j;
                break;
            }
        }
        char* ptr = (char*)mmalloc(length*sizeof(char));
        for(size_t j = 0;j<length;j++) // transform int to digit array
        {
            ptr[j] = (char)(tempNumber%10 + '0');
            tempNumber /= 10;
        }
        for(int j = length - 1;j >= 0;j--) // print char by char
        {
            print((char*)ptr+j,1);
        }
        mfree(ptr);
}