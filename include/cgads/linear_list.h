#ifndef CGADS_LINEAR_LIST_H_
#define CGADS_LINEAR_LIST_H_

#include <cstddef>
#include <iostream>

template<class ElemType>
struct SingleList{
    ElemType data;
    SingleList *next;
};

template<class T>
class LinearList
{
    using List = SingleList<T>;
public:
    LinearList()
    {
        single_list_ = new SingleList<T>();
    }
    ~LinearList()
    {
        if(single_list_ != nullptr)
        {
            delete single_list_;
            single_list_ = nullptr;
        }
    }

    SingleList<T> *find(int index);
    int insert(int index, T data);//before index
    int remove(int index);

//private:
    SingleList<T> *single_list_;
};

template<class T>
SingleList<T> *LinearList<T>::find(int index)
{
    SingleList<T> *p;
    int i = 0;
    while (p && i<index)
    {
        p = single_list_->next;
        ++i;
    }
    if(p && i==index)
        return p;
    return nullptr;
}

template<class T>
int LinearList<T>::insert(int index, T data)
{
    SingleList<T> *p;
    if(index==0)
        p = single_list_;
    else
        p = find(index-1);

    if(p==nullptr)
        return -1;

    SingleList<T> *s = new SingleList<T>();
    s->data = data;
    s->next = p->next;
    p->next = s;

    return 0;
}

template<class T>
int LinearList<T>::remove(int index)
{
    SingleList<T> *p;
    if(index==0)
        p = single_list_;
    else
        p = find(index-1);

    if(p==nullptr || p->next==nullptr)
        return -1;

    SingleList<T> *s=new SingleList<T>();
    s = p->next;
    p->next = s->next;
    delete s;
    s = nullptr;
}

#endif //CGADS_LINEAR_LIST_H_
