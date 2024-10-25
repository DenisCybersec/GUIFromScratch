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
class list
{
    public:
        list(T initVal){
            Node<T> nd = Node<T>();
            nd.value = initVal;
            first_ = &nd;
            last_ = first_;
        }
        void addNode(Node<T> nd)
        {
            nd->prev = last_;
            last_->next = nd;
            last_=last_next;
        }
        inline Node<T>* getHead() {return first_;}
        inline Node<T>* getEnd() {return last_;}
    private:
        size_t size;
        Node<T>* first_;
        Node<T>* last_;
};
#endif