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

        //if (choice_2 == 1) CreateNY(*year, new_year);
    }
    if (choice_1 == 2)
    {
        cout << "Please enter class's school year: ";
        int new_year;
        cin >> new_year;
        //CreateNC(*year, new_year);
    }
}

/*
void CreateNY(schoolyear& y, string name) {
    if (CheckDuplicateYear(y))
    {
        cout << "This school year has already existed!";
        return;
    }
    y.name = name;
    cout << "New school year is created!";
}
void CreateNC(Class& y, string CurY) {
    cout << "please enter the class name: ";
    cin.ignore(1000, '\n');
    getline(cin, y.name);
    cout << "new class is created!";
	return;
}
*/
