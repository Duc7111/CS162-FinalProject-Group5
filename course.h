#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "data.h"

using std::string;

const string day[6] = {"MON", "TUE", "WED", "THU", "FRI", "SAT"};
const string t[4] = {"7:30", "9:30", "13:30", "15:30"};

struct course
{
    int ID = 0;
    string name;
    string teacher;
    int credits;
    int s[2]; //MON = 0, TUE = 1, ..., S1 = 1, S2 = 2, ... || s[x] = day*7 + S;
    int ms;
    int cur;
    list<int[5]>* stlist; // 0: ID, 1: midterm, 2: final, 3: other, 4: total
    
    course();
    course(const course& co);
    course(int id);
    
    void save2File(string dir);
    bool checkCourse(const string& dir);
    bool checkStudent(int ID);
};
/*
struct CourseRegister
{
    course RegCourse;
    int sdate[3];
    int edate[3];
};

void PreCourseRegisttration(CourseRegister& CR);
*/
bool CheckSection(int section);  //check if the section of the course is valid
void PrintSection(int section1, int section2); //print out the section of the course
void PrintCourse(list<course>* cur); //print the course information