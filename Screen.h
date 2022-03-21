#pragma once
#include "AS.h"
#include "student.h"
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