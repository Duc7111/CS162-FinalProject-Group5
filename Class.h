#pragma once
#include "student.h"
#include <string>
struct Class
{
    string name;
    student* stlist;

    Class* next;
};

void save2File(Class c);