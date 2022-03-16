#pragma once
#include "AS.h"
#include "Class.h"
#include "semester.h"

struct schoolyear
{
	//data
	char* name;
	semester* selist;
	//listpointer
	schoolyear* next;

	schoolyear();
};