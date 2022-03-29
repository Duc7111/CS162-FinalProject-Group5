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

<<<<<<< HEAD
void CreateNY(schoolyear& y, AS log);
void CreateGeneralInfo(schoolyear& year, AS log);
=======
void CreateNY(schoolyear& y);
void CreateGeneralInfo(schoolyear& year);
>>>>>>> e0e65547d9af1a76d8cb291145285c098c615b53
bool checkSchoolYear(schoolyear& sy);
bool checkyear(string year);