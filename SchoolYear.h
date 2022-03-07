#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Classes
{
	int ClassType;
	/*
	* 1 = APCS
	* 2 = CLC
	* 3 = VP
	*/
	int ClassNo;
};

struct SchoolYear
{
	int StartYear;
	Classes CurrentClasses;
	SchoolYear* sNext;
};

void CreateYearInfo(SchoolYear* CurY);
void SaveYearInfo(SchoolYear* CurY);
void LoadYearInfo(SchoolYear* CurY);