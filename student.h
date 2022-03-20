// txt file format
//
// 
// ID,pass,clname
// ...
// default pass: SID
#pragma once

#include "data.h"
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
    // class data
    string clname;
    int No;
    //course data
    list<course>* colist;
    int conum = 0;

    void save2File();
};

bool login(student& s, int ID, string pass);

void changeStudent(student& s);