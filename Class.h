#pragma once
#include "student.h"

struct Class
{
    string name;
    student* stlist;

    Class* next;
};

void save2File(Class c);