#ifndef QUEUE_H
#define QUEUE_H
#include<list.hpp>
template<typename T>
class mqueue
{
    public:
        mqueue() : list_() {}
        void push(T a)
        {
            list_.push(a);
        }
        T pop()
        {
            list_.pop();
        }
    private:
        mlist<T> list_;
};
#endif