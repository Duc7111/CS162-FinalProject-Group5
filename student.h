// txt file format
//
// <class>
// ID,pass,fname,lname,gender,dob[0],dob[1],dob[2],SID
// ...
// default pass: SID
#pragma once

struct student
{
    // system data (username = ID)
    char* pass = nullptr;
    // personal data
    int ID = 0;
    char* fname = nullptr;
    char* lname = nullptr;
    bool gender = 0; // 0 = female / 1 = male
    int dob[3] = {0,0,0};
    char* SID = nullptr;
};

void destructer(student &s);

bool login(student &s, char* username, char* pass);

void changeStudent(student &s);
