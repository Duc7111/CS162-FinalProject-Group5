#pragma once

struct student
{
    // system data
    char* username = nullptr;
    char* pass = nullptr;
    // personal data
    int ID = 0;
    char* fname = nullptr;
    char* lname = nullptr;
    bool gender = 0; // 0 = female / 1 = male
    int dob[3] = {0,0,0};
    char* SID = nullptr;
};
