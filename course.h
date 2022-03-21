#pragma once
#include <string>
#include <fstream>

#include "data.h"

using std::string;

struct course
{
    int ID;
    string name;
    string teacher;
    int credits;
    int s[2]; //MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || s[x] = day*7 + S;
    int ms;
    int cur;
    list<int[5]>* stlist; // 0: ID, 1: midterm, 2: final, 3: other, 4: total
    
    course();
    course(int id);
    void save2File(string dir);
};