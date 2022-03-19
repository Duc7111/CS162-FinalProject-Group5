#pragma once
#include <string>

#include "data.h"

using std::string;

struct student;

struct course
{
    int ID;
    string name;
    string teacher;
    int credits;
    int ms = 50; // = 50
    int cur = 0; //current number of student = 0
    list<student>* stlist;
    int s[2]; //MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || s[x] = day*7 + S;
};


