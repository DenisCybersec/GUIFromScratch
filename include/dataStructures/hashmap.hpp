#ifndef HASHMAP_H
#define HASHMAP_H
#define MEM_SIZE 1024
#include<vector.hpp>
#include<list.hpp>
#include<pair.hpp>
size_t hash(void* ptr,size_t size)
{
    size_t summ = 0;
    for(int i = 0;i<size;i++)
    {
        summ += ((char*)ptr)[i];
    }
    return summ % MEM_SIZE;
}
template<typename K,typename V>
class mhashmap
{
    public:
        mhashmap() : vctr_(MEM_SIZE){
            for(size_t i = 0;i<MEM_SIZE;i++)
            {
                vctr_.at(i) = mlist<mpair<K,V>>();
            }
        }
        void insert(K key, V value)
        {
            mpair<K,V> pr = mpair<K,V>(key,value);
            size_t hashedKey = hash(&key,sizeof(key));
            mlist<mpair<K,V>>& lst = vctr_.at(hashedKey);
            lst.push(pr);
        }
        V get(K key)
        {
            size_t hashedKey = hash(&key,sizeof(key));
            mlist<mpair<K,V>>& lst = vctr_.at(hashedKey);
            Node<mpair<K,V>>* head = lst.getHead();
            Node<mpair<K,V>>* end = lst.getEnd();
            for(size_t j = 0; j < lst.size() ; j++)
            {
                mpair<K,V> pr = head->value;
                if(pr.first == key)
                {
                    return pr.second;
                }
                else
                {
                    if(head != end)
                    {
                        head = head->next;
                    }
                }
            }
            return NULL;
        }
    private:
        mvector<mlist<mpair<K,V>>> vctr_;
};
#endif