#pragma once
#include "SchoolYear.h"
#include "course.h"
#include <string>
using std::string;

struct semester
{
    int sn; //1(Fall), 2(Summer), 3(Autumn)
    string SY; //school year name
    int sdate[3]; //start date
    int edate[3]; //end date
    course* colist; // course list
    //list pointer
    semester* next;
};

