#pragma once
#include <string>

#include "const.h"
#include "Screen.h"
#include "AS.h"
#include "student.h"
#include "semester.h"

struct Class
{
    std::string name;
    list<student>* stlist;

    void save2File();
};

void CreateNC(Class& new_class,AS log);
