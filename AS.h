// txt file format
// 
// username,pass,fname,lname,gender,dob[0],dob[1],dob[2],SID
// ...
//

#pragma once

using std::string;
struct AS
{
    //system data
    string username;
    string pass;
    //personal data
    string fname;
    string lname;
    bool gender; // 0 = female, 1 = male
    int dob[3];
    string SID;
};

// void destructer(AS& as);

bool checkDob(int dob[3]);

bool checkAS(string username);

void save2File(const AS& as);

bool login(AS& as, string username, string pass); // input -> check pass -correct-> get info from file -> return true

void changeAS(AS& as);