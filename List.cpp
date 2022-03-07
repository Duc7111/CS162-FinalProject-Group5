#include "List.h"

template<class T>
struct Node
{
    //data
    T data;
    Node* next;

    Node(T t) : data(t), next(nullptr);
    //destructor
    ~Node() delete data;
};

template<class T>
struct list
{
    Node<T>* pHead;
    Node<T>* pTail;

    void destructor()   
    {
        while(pHead != nullptr)
        {
            Node<T> temp = pHead;
            pHead = pHead->next;
            delete temp;
        }
    }

    void add(T data)
    {
        pTail->next = new Node(data);
        pTail = pTail->next;
    }
};