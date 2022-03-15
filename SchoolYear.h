#pragma once
#include "AS.h"
#include "Class.h"
#include "semester.h"
struct schoolyear
{
	//data
	char* name;
	bool se[3];
	semester* selist;
	//listpointer
	schoolyear* next;

	schoolyear() : name(nullptr), se({false, false, false}), selist(nullptr), next(nullptr){};
};