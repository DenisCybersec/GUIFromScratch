
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
                resize(size_*2);
            }
            size_++;
            innerPtr_[size_] = a;
        }
        T pop()
        {
            return innerPtr_[size_--];
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
            if(size >= memorySize_)
            {
                mrealloc(innerPtr_,size);
            }else
            {
                mrealloc(innerPtr_,memorySize_);
            }
        }
};
