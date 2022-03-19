#pragma once
// txt file format
//
// 
// ID,pass,clname
// ...
// default pass: SID
#include "course.h"

using std::string;

struct student
{
    // system data (username = ID)
    string pass;
    // personal data
    int ID = 0;
    string fname;
    string lname;
    bool gender = 0; // 0 = female / 1 = male
    int dob[3] = { 0,0,0 };
    string SID;
    //class data
    string clname;
    int No;
    //course data
    course* colist = nullptr;
    int conum = 0;
    //list pointer
    student* next;
};

bool login(student& s, int ID, string pass);

void changeStudent(student& s);