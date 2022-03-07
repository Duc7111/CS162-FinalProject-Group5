#pragma once

template<class T>
struct Node
{
    //data
    T data;
    Node* next;

    Node() : data(), next(nullptr){};
    Node(T t) : data(t), next(nullptr){};
};

template<class T>
struct list
{
    Node<T>* pHead;
    Node<T>* pTail;

    list() : pHead = new Node<T>(), pTail(nullptr){};
    ~list()
    {
        while(pHead)
        {
            pTail = pHead;
            pHead = pHead->next;
            delete pTail;
        }
        pTail = nullptr;
    }

    void add(T data)
    {
        pTail->next = new Node(data);
        pTail = pTail->next;
    }
};