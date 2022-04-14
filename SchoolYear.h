#pragma once
#include<iostream>
#include<string> 

#include "AS.h"
#include "semester.h"
#include "data.h"

using std::string;

struct schoolyear
{
	//data
	string name; //schoolyear name(2021-2022)
	semester Fall, Summer, Autumn;

	schoolyear();
	schoolyear(const string& name);
	
	void save2File();
};


void CreateNY(schoolyear& y, AS log);
void CreateGeneralInfo(schoolyear& year, AS log);
bool checkSchoolYear(schoolyear& sy);
bool checkyear(string year);
void getschoolyear(schoolyear& year, AS log);
