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
	list<semester>* selist;

	schoolyear();
	schoolyear(const string& name);
	
	bool checkSe(const semester& s);
	void save2File();
};

void CreateNY(schoolyear*& y, int data);
void CreateNC(schoolyear*& y, int CurY);
void CreateGeneralInfo(schoolyear*& year);
