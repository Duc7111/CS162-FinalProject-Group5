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

void CreateGeneralInfo(schoolyear& year, AS log)
{
    //schoolyear* year = new schoolyear();
   /* cout << "1. Create a new school year." << endl;
    cout << "2. Insert a new class." << endl;
    cout << "3. return to menu." << endl;
    cout << "Your choice: ";
    int choice_1; 
	cin >> choice_1;*/
    

    //if (choice_1 == 1)
    //{
    system("cls");
    Inscreen(log);
        cout << "Please enter the school year (Format: 2000-2001): ";
        //cin.ignore(1000, '\n');
    	getline(cin, year.name);
        
        while (checkyear(year.name) == false) {
            cout << "Invalid School Year. Try again" << endl;
            cout << "Please enter the school year (Format: 2000-2001): ";
            getline(cin, year.name);
        }
        cout << "Your new school year is " << year.name << endl;
        cout << "Confirm creating this new school year?" << endl;
        cout << "1. Yes                           2. No" << endl;
        cout << "Your choice: ";
        int choice_2;
        string choice;
        getline(cin, choice);
        choice_2 = convert(choice);
        system("cls");
        if (choice_2 == 1) CreateNY(year,log);
    //}
    //if (choice_1 == 2) CreateNC();
}

void CreateNY(schoolyear& y,AS log) {
    if (checkSchoolYear(y)) {
        Inscreen(log);
        cout << "This school year has already existed.";
        system("pause");
        return;
    }
    else {
        y.save2File();
        Inscreen(log);
        cout << "New school year has been created successfully" << endl;
        system("pause");
        /*cout << "New school year has been created successfully" << endl;
        cout << "You can now process this school year information, starting with semesters." << endl;
        cout << "1. Yes, proceed to continue with semesters.            2. No, maybe later." << endl;
        cout << "Your choice: ";
        int choice;
        cin >> choice;*/
        //if (choice == 1) SemesterExecution(y);
    }
}


bool checkyear(string year) {
    for (int i = 0; i <= 3; i++) {
        if (year[i] <= 47 || year[i] >= 58)
            return false;
    }
    if (year[4] != '-')
        return false;
    for (int i = 5; i >= 8; i++) {
        if (year[i] <= 47 || year[i] >= 58)
            return false;
    }
    return true;
}
