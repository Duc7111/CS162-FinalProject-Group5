#pragma once

void dataBase();

template<class T>
struct list
{
    T data;
    list<T>* next;

    list<T>() : data(), next(nullptr){};
    list<T>(const T& d) : data(d), next(nullptr){};
    list<T>(const T& d, list<T>* n) : data(d), next(n){};
};

template<class T>
void dellist(list<T>* pHead)
{
    while (pHead)
    {
        list<T>* temp = pHead;
        pHead = pHead->next;
        delete temp;
    }
}