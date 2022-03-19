#pragma once

void dataBase();

template<class T>
struct list
{
    T data;
    list<T>* next;
};