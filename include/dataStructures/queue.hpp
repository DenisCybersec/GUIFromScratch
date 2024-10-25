#ifndef QUEUE_H
#define QUEUE_H
template<typename T>
struct Node
{
    T value;
    Node* prev;
    Node* next;
};
template<typename T>
class queue
{
    public:
        queue()
        {
            last_ = nullptr;
            first_ = last_;
        }
        void push(T a)
        {
            if(!last_)
            {
                Node<T>* newNode = new Node<T>();
                newNode->value = a;
                last_ = newNode;
                first_ = last_;
            }else{
                Node<T>* newNode = new Node<T>();
                newNode->value = a;
                last_->prev = newNode;
                newNode->next = last_;
                last_ = newNode;
            }
        }
        T pop()
        {
            Node<T>* tmp = first_;
            first_ = first_->prev; 
            return tmp->value;
        }
    private:
        Node<T>* last_;
        Node<T>* first_;
};
#endif