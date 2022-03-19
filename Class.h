#pragma once
#include <string>

#include "student.h"
#include "const.h"

struct Class
{
    std::string name;
    list<student> stlist;
};

void save2File(Class c);