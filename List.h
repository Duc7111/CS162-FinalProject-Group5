#pragma once
template<class T>
struct Node
{
    //data
    T data;
    Node* next;

    Node(T t);
    //destructor
    ~Node();
};

template<class T>
struct list
{
    Node<T>* pHead;
    Node<T>* pTail;
    
    void destructor();
    void add(T data);
};