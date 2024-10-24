#include<types.hpp>
template<typename T>
T pow(T value,size_t degree)
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