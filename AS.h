// txt file format
// 
// username,pass,fname,lname,gender,dob[0],dob[1],dob[2],SID
// ...
//

#pragma once
#include <string>

using std::string;
struct AS
{
    //system data
    string username = nullptr;
    string pass = nullptr;
    //personal data
    string fname = nullptr;
    string lname = nullptr;
    bool gender = 0; // 0 = female, 1 = male
    int dob[3] = { 0,0,0 };
    string SID = nullptr;
};

void destructer(AS& as);

bool checkDob(int dob[3]);

bool checkAS(string username);

void save2File(const AS& as);

bool login(AS& as, string username, string pass); // input -> check pass -correct-> get info from file -> return true

void changeAS(AS& as);