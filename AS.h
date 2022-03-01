#pragma once

struct AS
{
    //system data
    char* username;
    char* pass;
    //personal data
    char* fname;
    char* lname;
    bool gender; // 0 = female, 1 = male
    int dob[3];
    int SID;
};

int checkAS(char* username);

void save2File(const AS &as);

bool login(AS &as, char* username, char* pass); // input -> check pass -correct-> get info from file -> return true
