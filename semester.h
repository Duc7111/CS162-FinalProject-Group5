#pragma once
#include "SchoolYear.h"
#include "course.h"

struct semester
{
    int sn; //1(Fall), 2(Summer), 3(Autumn)
    int schoolYear; //start year
    int sdate[3]; //start date
    int edate[3]; //end date
    course* colist;
    //list pointer
    semester* next;
};