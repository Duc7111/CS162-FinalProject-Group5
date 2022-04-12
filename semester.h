#pragma once
#include <string>
#include <fstream>

#include "course.h"
#include "data.h"


using std::string;
struct schoolyear;
struct semester
{
    string name; //1(Fall), 2(Summer), 3(Autumn)
    int sdate[3]; //start date
    int edate[3]; //end date
    list<course>* colist; // course list

    semester();
    semester(const string& dir);//full dir

    void save2File(string dir);//schoolyear dir
    void setCur(const string& dir);
};
void SaveSemester(list<semester>*& se);
void SemesterExecution(semester& se, AS log);
int getnamese(AS log);
void AddCourse2Semester(semester& sem, AS log);

void ViewCourse(semester& sem);
void FindCoursetodo(schoolyear& sy, semester& sem, int& id);

void ViewCourse(schoolyear& sy, semester& sem);
void LoadCourses(schoolyear& sy, semester& sem);

void FindCourse(schoolyear& sy, semester& sem, int& id);
void UpdateCourse(schoolyear& sy, semester& sem);
void Update(list <course>* tmp, int choice);