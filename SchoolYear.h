#pragma once
#include <iostream>
#include <fstream>
#include "AS.h"
#include "List.h"
using namespace std;

struct ClassList
{
	int ClassType;
	/*
	* 1 = APCS
	* 2 = CLC
	* 3 = VP
	*/
	int ClassNo;
};
/*
struct SchoolYear
{
	int StartYear;
	Classes CurrentClasses;
	SchoolYear* sNext;
};
*/
struct InitYear
{
	int StartYear;
	ClassList* classes;
};

struct YearList
{
	InitYear year;
	YearList* next;
};

void CreateYearInfo(YearList* CurY, AS log);
//void SaveYearInfo(YearList* CurY);
//void LoadYearInfo(YearList* CurY);
