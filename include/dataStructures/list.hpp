#ifndef LIST_H
#define LIST_H
#include<types.hpp>
template<typename T>
struct Node
{
    T value;
    Node* prev;
    Node* next;
};
template<typename T>
class mlist
{
    public:
        mlist()
        {
            size_ = 0;
            first_ = nullptr;
            last_ = nullptr;
        }
        mlist(T initVal){
            Node<T>* nd = new Node<T>{initVal, nullptr, nullptr};
            size_ = 1;
            first_ = nd;
            last_ = first_;
        }
        void push(T value)
        {
            Node<T>* nd = new Node<T>{value, last_, nullptr};
            if (last_) {
                last_->next = nd;
            } else {
                first_ = nd;
            }
            last_ = nd;
            size_ += 1;
        }
        T pop()
        {
            if(last_)
            {
                T val = last_->value;
                last_ = last_->prev;
                return val;
            }else
            {
                return NULL;
            }
        }
        inline size_t size(){ return size_;}
        inline Node<T>* getHead() {return first_;}
        inline Node<T>* getEnd() {return last_;}
    private:
        size_t size_;
        Node<T>* first_;
        Node<T>* last_;
};
#endif