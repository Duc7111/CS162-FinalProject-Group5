#pragma once

struct AS
{
    //system data
    char* username = nullptr;
    char* pass = nullptr;
    //personal data
    char* fname = nullptr;
    char* lname = nullptr;
    bool gender = 0; // 0 = female, 1 = male
    int dob[3] = {0,0,0};
    int SID = 0;
};

void destructer(AS &as);

bool checkDob(int dob[3]);

bool checkAS(char* username);

void save2File(const AS &as);

bool login(AS &as, char* username, char* pass); // input -> check pass -correct-> get info from file -> return true
