#pragma once
#include <string>
#include <fstream>

#include "course.h"
#include "data.h"

using std::string;

struct semester
{
    int sn; //1(Fall), 2(Summer), 3(Autumn)
    int sdate[3]; //start date
    int edate[3]; //end date
    list<course>* colist; // course list

    semester();
    semester(const string& dir);//full dir
    void save2File(string dir);//schoolyear dir
};

void SaveSemester(list<semester>*& se);
void SemesterExecution(list<semester>*& se, AS log);