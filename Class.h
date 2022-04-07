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
    void save2FileE();
    bool checkClass();
};
void GotoClass(Class& new_class, AS log);
void CreateNC(Class& new_class,AS log);
