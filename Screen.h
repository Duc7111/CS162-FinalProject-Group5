#pragma once
#include "const.h"
#include "console.h"
#include "AS.h"
#include "student.h"
#include "SchoolYear.h"
#include "course.h"
#include "semester.h"
#include "Class.h"
#include "data.h"
#include "addstudent.h"
int StartScreen();
void SignupScreen();
void SignupSystem();
short loginp1();
bool checkspecial(string str);
int convert(string str);
void loginas(AS& log);
int start(AS log);
void viewprofile(AS log);
void changepass(AS& log);
int menuformainAS(AS log);
void Inscreen(AS log);
int schoolyearScreen(AS log);
bool checkstring(string str);
void loginSt(student& s);
void semesterscreen(AS log, schoolyear& year);
void Inscreenst(student st);
int studentscreen1(student& st);
void viewstudent(student log);
void changepassst(student& st);
int SeScreen(AS log);