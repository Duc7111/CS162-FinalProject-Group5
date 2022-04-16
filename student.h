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
    int conum = 0;
    list<course>* colist;

    student();
    student(int id); // get info from file only !!!
    ~student();

    bool createAcc();
    void save2File();
    void change(); // change in file
    
    bool addCourse(const course& co);
    bool removeCourse(int ID);
    void viewCourse();
};

bool login(student& s, int ID, string pass);

void changeStudent(student& s);