// vector.hpp
#include <malloc.hpp>
#include<types.hpp>
class OutOfRangeException { // MOVE TO SEPARATE FILE AFAP
public:
    OutOfRangeException(const char* message) : message_(message) {}
    const char* what() const {
        return message_;
    }

private:
    const char* message_;
};
template<typename T>
class vector {
    public:
        vector(size_t size){ // Constructor for dynamic array
            innerPtr_ = (T*)mmalloc(size*sizeof(T));
            size_ = size;
            memorySize_ = size;
        }
        T& at(size_t pos)
        {
            if(pos < memorySize_)
            {
                return innerPtr_[pos];
            }
            else
            {
                throw OutOfRangeException("Attemp to access memory outside vector");
            }
        }
        void set(size_t pos, T val)
        {
            if(pos < memorySize_)
            {
                innerPtr_[pos] = val;
            }
            else
            {
                throw OutOfRangeException("Attemp to access memory outside vector");
            }
        }
        T* ptr()
        {
            return innerPtr_;
        }
        void resize(size_t size)
        {
            innerPtr_ = mrealloc(innerPtr_,size);
            if(size_ < size)
            {
                size_ = size;
            }
            memorySize_ = size;
        }
        void push_back(T a)
        {
            if(size_ < memorySize_)
            {
                innerPtr_[size_] = a;
            }
            else
            {
                resize(memorySize_*2);
                innerPtr_[size_] = a;
            }
        }
        T pop_back()
        {
            size_ -= 1;
            return innerPtr_[size_+1]; 
        }
        size_t size()
        {
            return size_;
        }
        ~vector<T>()
        {
            mfree(innerPtr_);
        }
        T operator [](size_t i)
        {
            return this->at(i);
        }
    private:
        T* innerPtr_; // Pointer to the inner array
        size_t size_; // Size of the vector
        size_t memorySize_; // Size of allocated memory
};