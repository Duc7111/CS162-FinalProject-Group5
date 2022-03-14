#include<iostream>
#include<cstring>

#include "const.h"
#include "console.h"
#include "Screen.h"
#include "AS.h"
#include "student.h"
#include "schoolyear.h"

using namespace std;
/*
void CreateYearInfo(YearList* CurY, AS log)
{
	Inscreen(log);
	int SY, CT, CN;
	char opin[slen];
	YearList* tmp = new YearList();
	tmp->year.classes = new ClassList();
	cout << "Please enter a year: ";
	cin.ignore(slen, '\n');
	cin.get(opin, slen);
	SY = convert(opin);
	while (SY < 2000 || SY >= 2030) {
		cout << "Invalid option. Try again." << endl;
		cout << "Your option: ";
		cin.ignore(100, '\n');
		cin.get(opin, slen);
		SY = convert(opin);
	}
	system("cls");
	Inscreen(log);

	cout << "Please enter a class type:" << endl;
	cout << "Enter 1 if APCS" << endl;
	cout << "Enter 2 if CLC" << endl;
	cout << "Enter 3 if VP" << endl;
	cout << "Your Choice: ";
	cin.ignore(slen, '\n');
	cin.get(opin, slen);
	CT = convert(opin);
	while (CT < 1 || CT >= 4) {
		cout << "Invalid option. Try again." << endl;
		cout << "Your option: ";
		cin.ignore(100, '\n');
		cin.get(opin, slen);
		CT = convert(opin);
	}
	system("cls");

	Inscreen(log);
	cout << "Please enter the class number: ";
	cin.ignore(slen, '\n');
	cin.get(opin, slen);
	CN = convert(opin);
	while (CN < 0 ) {
		cout << "Invalid number. Try again." << endl;
		cout << "Your number: ";
		cin.ignore(100, '\n');
		cin.get(opin, slen);
		CN = convert(opin);
	}
	system("cls");
	Inscreen(log);

	int choice;
	cout << "Do you want to save the information?" << endl;
	cout << "1. Yes                         2. No" << endl;
	cout << "Your choice: ";
	cin.ignore(slen, '\n');
	cin.get(opin, slen);
	choice = convert(opin);
	while (choice < 0 || choice >=3 ) {
		cout << "Invalid number. Try again." << endl;
		cout << "Your number: ";
		cin.ignore(100, '\n');
		cin.get(opin, slen);
		choice = convert(opin);
	}
	if (choice == 1)
	{
		tmp->year.StartYear = SY;
		tmp->year.classes->ClassType = CT;
		tmp->year.classes->ClassNo = CN;
		if (CurY != NULL)
		{
			CurY->next = tmp;
			CurY = CurY->next;
		}
		else CurY = tmp;
		//SaveYearInfo(CurY);
		gotoxy(0, 11);
		cout << "Class information has been saved" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
	}
	delete tmp;
}*/