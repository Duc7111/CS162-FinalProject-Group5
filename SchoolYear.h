#pragma once
#include<iostream>
#include<cstring>
using namespace std; 

#include "AS.h"
#include "semester.h"
#include "data.h"

//#include "Screen.h"
//#include "console.h"

struct schoolyear
{
	//data
	string name; //schoolyear name(2021-2022)
	list<semester>* selist;

	schoolyear();
};

void save2File(schoolyear* y);

void CreateNY(schoolyear*& y, int data);
void CreateNC(schoolyear*& y, int CurY);
void CreateGeneralInfo(schoolyear*& year);
