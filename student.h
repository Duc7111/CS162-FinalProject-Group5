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

struct student
{
    // system data (username = ID)
    char* pass = nullptr;
    // personal data
    int ID = 0;
    char* fname = nullptr;
    char* lname = nullptr;
    bool gender = 0; // 0 = female / 1 = male
    int dob[3] = { 0,0,0 };
    char* SID = nullptr;
    //class data
    char* clname;
    int No;
    //course data
    course* colist = nullptr;
    int conum = 0;
    //list pointer
    student* next;
};


void destructer(student& s);

bool login(student& s, int ID, char* pass);

void changeStudent(student& s);