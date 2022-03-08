#include "SchoolYear.h"

void CreateYearInfo(YearList* CurY)
{
	int SY, CT, CN;
	YearList* tmp = new YearList();
	tmp->year.classes = new ClassList();
	cout << "Please enter a year: ";
	cin >> SY;
	system("cls");


	cout << "Please enter a class type:" << endl;
	cout << "Enter 1 if APCS" << endl;
	cout << "Enter 2 if CLC" << endl;
	cout << "Enter 3 if VP" << endl;
	cout << "Your Choice: ";
	cin >> CT;
	system("cls");


	cout << "Please enter the class number: ";
	cin >> CN;
	system("cls");


	int choice;
	cout << "Do you want to save the information?" << endl;
	cout << "1. Yes                         2. No" << endl;
	cout << "Your choice: ";
	cin >> choice;
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
		SaveYearInfo(CurY);
		cout << "Class information has been saved";
		system("cls");
	}
	else
	{
		CreateYearInfo(CurY);
		system("cls");
	}
	delete tmp;
}