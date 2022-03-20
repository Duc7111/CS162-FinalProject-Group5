#pragma once

void dataBase();

template<class T>
struct list
{
    T data;
    list<T>* next;

    list() : data(), next(nullptr){};
    list(T d) : data(d), next(nullptr){};
    list(T d, list<T>* n) : data(d), next(n){};
};