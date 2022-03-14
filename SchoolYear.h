#pragma once
#include "AS.h"
#include "Class.h"
#include "semester.h"
struct schoolyear
{
	//data
	int start;
	int senum = 0;
	semester* selist;
	//listpointer
	schoolyear* next;
};