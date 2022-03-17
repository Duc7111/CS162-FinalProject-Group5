#pragma once
#include<iostream>
#include<cstring>
using namespace std; 

#include "AS.h"
#include "Class.h"
#include "semester.h"

//#include "Screen.h"
//#include "console.h"

struct schoolyear
{
	//data
	int year;
	Class* newclass;
	semester* selist;
	
	//listpointer
	schoolyear* next;

	// schoolyear();
};

void CreateNY(schoolyear*& y, int data);
void CreateNC(schoolyear*& y, int CurY);
void CreateGeneralInfo(schoolyear*& year);
