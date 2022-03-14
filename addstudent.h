#pragma once


struct Student
{
    int no;
    int ID;
    char* FirstName = nullptr;
    char* LastName = nullptr;
    bool gender; // 0: Female ; // 1: Male
    int dob[3] = { 0,0,0 };
    char* SID = nullptr;
    Student* next;

};
void AddStudent(Student*& list);
// save student into text file
void SaveStudent(Student*& list);
// check if ID, no, SID are already entered
bool Check(Student*& list, int& id);

// load Student already entered
void LoadStudent(Student*& list);

//QuickInput

void QuickInput(Student*& list);
