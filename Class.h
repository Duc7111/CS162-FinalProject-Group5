#pragma once
#include "student.h"

struct Class
{
    char* name;
    student* stlist;

    Class* next;
};

void save2File(Class c);