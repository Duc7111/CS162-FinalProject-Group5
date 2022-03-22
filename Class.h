#pragma once
#include <string>

#include "student.h"
#include "data.h"

struct Class
{
    std::string name;
    list<student>* stlist;

    void save2File();
};