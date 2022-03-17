#pragma once
// txt file format
//
// -<class>
//  ID,pass,fname,lname,gender,dob[0],dob[1],dob[2],SID,No
// ^
// |Intentional leading space
// ...
// default pass: SID
#include "course.h"

using std::string;

struct student
{
    // system data (username = ID)
    string pass = nullptr;
    // personal data
    int ID = 0;
    string fname = nullptr;
    string lname = nullptr;
    bool gender = 0; // 0 = female / 1 = male
    int dob[3] = { 0,0,0 };
    string SID = nullptr;
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