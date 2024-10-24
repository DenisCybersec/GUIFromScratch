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
            size_ = 0; // by default 0 elements
            memorySize_ = size; 
        }
        T& at(size_t pos) // get element from vector
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
        void set(size_t pos, T val) // set value 
        {
            if(pos < memorySize_)
            {
                this->at(pos) = val;
            }
        }
        T* ptr() // get ptr to raw access to memory
        {
            return innerPtr_;
        }
        void resize(size_t size) // resize memory allocated to vector
        {
            innerPtr_ = mrealloc(innerPtr_,size);
            if(size_ < size)
            {
                size_ = size;
            }
            memorySize_ = size;
        }
        void push_back(T a) // push element in the end of vector
        {
            if(size_ >= memorySize_)
            {
                resize(memorySize_*2);
                innerPtr_[size_] = a;
            }
            innerPtr_[size_] = a;
            size_++;
        }
        T pop_back() // get last element of vector
        {
            if(size_ == 0)
            {
                throw OutOfRangeException("Attemp to access memory outside vector");
            }
            return innerPtr_[--size_]; 
        }
        size_t size() const // get size of vector
        {
            return size_;
        }
        size_t memorySize() const // get size of allocated memory to vector
        {
            return memorySize_;
        }
        ~vector<T>()
        {
            mfree(innerPtr_); // free memory
        }
        T& operator [](size_t i) // sugar
        {
            return this->at(i);
        }
    private:
        T* innerPtr_; // Pointer to the inner array
        size_t size_; // Size of the vector
        size_t memorySize_; // Size of allocated memory
};