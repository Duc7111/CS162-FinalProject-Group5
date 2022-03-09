#pragma once

template<class T>
struct Node
{
    //data
    T data;
    Node* next;

    Node() : data(), next(nullptr){};
    Node(T t) : data(t), next(nullptr){};
    Node(T t, Node* next) : data(t), next(next){};
};

template<class T>
struct list
{
    Node<T>* pHead;
    Node<T>* pTail;

    list() : pHead (new Node<T>), pTail(nullptr){};
    ~list()
    {
        while(pHead)
        {
            pTail = pHead;
            pHead = pHead->next;
            delete pTail;
        }
    }

    void push_back(T data)
    {
        pTail->next = new Node(data);
        pTail = pTail->next;
    }
    void push_front(T data)
    {
        Node<T> temp = pHead->next;
        pHead->next = new Node<T>(data, temp);
    }

    void operator += (list const & l)
    {
        pTail->next = l->pHead->next;
        pTail = l.pTail;
    }
};