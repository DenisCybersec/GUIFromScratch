
#ifndef STACK_H
#define STACK_H
#include<vector.hpp>
#include<types.hpp>
template<typename T>
class stack
{
    public:
        stack(size_t size)
        {
            innerPtr_ = (T*)mmalloc(size * sizeof(T));
            size_ = 0;
            memorySize_ = size;
        }
        void push(T a)
        {
            if(size_ >= memorySize_)
            {
                resize(memorySize_*2);
            }
            innerPtr_[size_] = a;
            size_++;
        }
        T pop()
        {
            return innerPtr_[size_--];
        }
        size_t size()
        {
            return size_;
        }
        size_t mem()
        {
            return memorySize_;
        }
        ~stack()
        {
            mfree(innerPtr_);
        }
    private:
        T* innerPtr_;
        size_t size_;
        size_t memorySize_;
        void resize(size_t size)
        {
            innerPtr_ = (T*)mrealloc(innerPtr_,size*sizeof(T));
            if(size_ > size)
            {
                size_ = size;
            }
            memorySize_ = size;
        }
};
#endif