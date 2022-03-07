// txt file format
//
// -<class>,num
//  ID,pass,fname,lname,gender,dob[0],dob[1],dob[2],SID
// ^
// |Intentional leading space
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
    //class data
    int No;
};

void destructer(student &s);

bool login(student &s, char* username, char* pass);

void changeStudent(student &s);
