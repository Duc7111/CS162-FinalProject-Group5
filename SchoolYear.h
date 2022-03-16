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

<<<<<<< HEAD
	schoolyear();
};
=======
	schoolyear() : name(nullptr), se({false, false, false}), selist(nullptr), next(nullptr){};
};
>>>>>>> 385306ea36b22e7e33d4748b8ae9f5c6e2e1592d
