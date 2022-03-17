#pragma once

#include "AS.h"
#include "Class.h"
#include "semester.h"

struct schoolyear
{
	//data
	string name;
	semester* selist;
	//listpointer
	schoolyear* next;

	schoolyear();
};

#include<iostream>
#include<cstring>
using namespace std;

#include "AS.h"
//#include "Screen.h"
//#include "console.h"

/*
#include "Class.h"
#include "semester.h"
#include "student.h"
#include "course.h"
*/

struct classname
{
	string cname = NULL;
	classname* next;
};

struct schoolyear
{
	int year;
	classname* newclass = NULL;
	//semester* selist;
	schoolyear* next;
};

void CreateNY(schoolyear*& y, int data);
void CreateNC(schoolyear*& y, int CurY);
void CreateGeneralInfo(schoolyear*& y);
