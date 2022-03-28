#include<iostream>
#include<cstring>
#include<fstream>
#include<direct.h>

#include "const.h"
#include "console.h"
#include "Screen.h"
#include "AS.h"
#include "student.h"
#include "schoolyear.h"
#include "Class.h"

using namespace std;

schoolyear::schoolyear() : name(""){};

schoolyear::schoolyear(const string& name)
{
	this->name = name;
    Fall = semester("data\\schoolyear\\" + name + "\\Fall");
    Autumn = semester("data\\schoolyear\\" + name + "\\Autumn");
    Summer = semester("data\\schoolyear\\" + name + "\\Summner");
}

void schoolyear::save2File()
{
	ofstream fout("data\\schoolyear\\schoolyear.txt", ios_base::app);
	fout << name << endl;
	fout.close();
	string dir = "data\\schoolyear\\" + name;
	const char* d = dir.c_str();
	_mkdir(d);
	Fall.save2File(dir);
	Autumn.save2File(dir);
	Summer.save2File(dir);
}

bool checkSchoolYear(schoolyear& sy)
{
    ifstream fin("data\\schoolyear\\schoolyear.txt");
    while(!fin.eof())
    {
        string temp;
        getline(fin, temp);
        if(sy.name == temp)
        {
            sy = schoolyear(temp);
            return true;
        }
    }
    return false;
}

void CreateGeneralInfo(schoolyear& year)
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
        cout << "Please enter the school year (EX: 2000-2001): ";
        cin.ignore(1000, '\n');
    	getline(cin, year.name);
        system("cls");

        cout << "Your new school year is " << new_year << endl;
        cout << "Confirm creating this new school year?" << endl;
        cout << "1. Yes                           2. No" << endl;
        cout << "Your choice: ";
        int choice_2; 
	cin >> choice_2;
        system("cls");
	    
        if (choice_2 == 1) CreateNY(year);
    }
    //if (choice_1 == 2) CreateNC();
}

void CreateNY(schoolyear& y) {
    if (checkSchoolYear(y)) {
        cout << "This school year has already existed.";
        return;
    }
    else {
        y.save2File();
        cout << "New school year has been created successfully" << endl;
        cout << "You can now process this school year information, starting with semesters." << endl;
        cout << "1. Yes, proceed to continue with semesters.            2. No, maybe later." << endl;
        cout << "Your choice: ";
        int choice;
        cin >> choice;
        //if (choice == 1) SemesterExecution(y);
    }
}



