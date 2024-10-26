#ifndef PAIR_H
#define PAIR_H
template<typename T,typename K>
class mpair
{
    public:
        mpair(T a, K b)
        {
            first = a;
            second = b;
        }
        T first;
        T second;
};
#endif