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

    Class();

    void save2File();
    bool checkClass();
};

void CreateNC(Class& new_class,AS log);
