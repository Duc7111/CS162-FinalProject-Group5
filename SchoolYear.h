#pragma once
#include "AS.h"
#include "Class.h"
#include "semester.h"
struct schoolyear
{
	//data
	int start;
	bool se[3];
	se[0] = false;
	se[1] = false;
	se[2] = false;
	semester* selist;
	//listpointer
	schoolyear* next;
};