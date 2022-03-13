#pragma once
#include "AS.h"
#include "Class.h"

struct schoolyear
{
	int start;
	semester* pHead;
	SchoolYear* sNext;
};

struct InitYear
{
	int StartYear;
	ClassList* classes;
};

void CreateYearInfo(YearList* CurY, AS log);
//void SaveYearInfo(YearList* CurY);
//void LoadYearInfo(YearList* CurY);
