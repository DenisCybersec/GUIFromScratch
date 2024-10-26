#ifndef POW_H
#define POW_H
#include<types.hpp>
template<typename T>
T mpow(T value,size_t degree) // pow function
{
    T a = value;
    if(degree == 0)
    {
        return 1;
    }
    for(int i = 1;i<degree;i++)
    {
        a*=value;
    }
    return a;
}
#endif