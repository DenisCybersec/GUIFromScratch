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
        }
        T& at(size_t pos)
        {
            if(pos < size_)
            {
                return innerPtr_[pos];
            }
            else
            {
                throw OutOfRangeException("Attemp to access memory outsize vector");
            }
        }
        void set(size_t pos, T val)
        {
            innerPtr_[pos] = val;
        }
        void resize(size_t newSize)
        {
            innerPtr_ = mrealloc(innerPtr_,newSize);
        }
        T* ptr()
        {
            return innerPtr_;
        }
        size_t size()
        {
            return size_;
        }
    private:
        T* innerPtr_; // Pointer to the inner array
        size_t size_; // Size of the vector
};