
#ifndef STACK_H
#define STACK_H
#include<vector.hpp>
#include<types.hpp>
template<typename T>
class mstack
{
    public:
        mstack(size_t size) : vctr_(size) {}
        void push(T a)
        {
            vctr_.push_back(a);
        }
        T pop()
        {
            return vctr_.pop_back();
        }
        size_t size()
        {
            return vctr_.size();
        }
        size_t mem()
        {
            return vctr_.memorySize();
        }
    private:
        mvector<T> vctr_;
};
#endif