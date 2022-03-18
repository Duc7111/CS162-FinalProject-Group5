#include<iostream>
#include<cstring>

#include "const.h"
#include "console.h"
#include "Screen.h"
#include "AS.h"
#include "student.h"
#include "schoolyear.h"

using namespace std;

schoolyear::schoolyear() : name(""), selist(nullptr), next(nullptr){};
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

void CreateGeneralInfo(schoolyear* &year)
{
    //schoolyear* year = new schoolyear();
    cout << "1. Create a new school year." << endl;
    cout << "2. Insert a new class." << endl;
    cout << "3. return to menu." << endl;
    cout << "Your choice: ";
    int choice_1; 
	cin >> choice_1;
    system("cls");

    if (choice_1 == 1)
    {
        int new_year;
        cout << "Please enter the first year of the school year: ";
        cin >> new_year;
        system("cls");

        cout << "Your new school year is " << new_year << "-" << new_year + 1 << endl;
        cout << "confirm creating this new school year?" << endl;
        cout << "1. Yes                           2. No" << endl;
        cout << "Your choice: ";
        int choice_2; cin >> choice_2;
        system("cls");

        if (choice_2 == 1) CreateNY(year, new_year);
    }
    if (choice_1 == 2)
    {
        cout << "Please enter class's school year: ";
        int new_year;
        cin >> new_year;
        CreateNC(year, new_year);
    }
}

void CreateNY(schoolyear*& y, string name)
{
	schoolyear* new_y = new schoolyear();
	new_y->name = name;
	new_y->newclass = NULL;
	new_y->next = NULL;
	
	if (y == NULL) y = new_y;
	else
	{
		schoolyear* tmp = y;
		while (tmp != NULL)
			tmp = tmp->next;
		tmp = new_y;
	}
	cout << "New school year is created!";
}


void CreateNC(schoolyear*& y, string CurY)
{
    Class* data = new Class();
    schoolyear* tmp = y;
    bool flag = false;

    cout << "please enter the class name: ";
    cin.ignore(1000, '\n');
	getline(cin, data->name);
    data->next = nullptr;

    while (tmp != NULL)
    {
        if (tmp->name == CurY)
        {
            flag = true;
            break;
        }
        tmp = tmp->next;
    }
    if (flag)
    {
        if (tmp->newclass = NULL) tmp->newclass = data;
        else
        {
            Class* new_class = tmp->newclass;
            while (new_class != NULL)
                new_class = new_class->next;
            new_class = data;
        }
	cout << "new class is created!";
    }
    else cout << "School year for this class does not exist, please try again";
}
