#pragma once
#include "AS.h"
#include "Class.h"
#include "semester.h"
#include "course.h"
struct schoolyear
{
	//data
	int year;
	char* name;
	bool se[3]; //se là gì?
	semester* selist;

	//listpointer
	schoolyear* next;

};