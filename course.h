#pragma once
#include "student.h"

struct course
{
    int ID;
    char* name;
    char* teacher;
    int credit;
    int ms = 50;
    int cur = 0; //current number of student 
    student* stlist;
    int s[2]; //MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || s[x] = day*7 + S;

    course* next;
};