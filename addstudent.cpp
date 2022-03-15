#include <iostream>
#include <fstream>
#include "addstudent.h"
#include "Screen.h"
#include "AS.h"
#include "Class.h"
#include "const.h"

using namespace std;



void AddStudent(Class*& clist)
{

    student* cur;
    student* head;
    head = clist->stlist;
    cur = clist->stlist;
    if (cur->ID == 0)
    {
        cout << "ID: ";
        char* id = new char[30];
        cin.ignore(30, '\n');
        cin.get(id, 30, '\n');
        cur->ID = convert(id);
        while (cur->ID != 0)
        {
            cout << "First name: ";
            char* temp = new char[100];
            cin.ignore(1000, '\n');
            cin.get(temp, 100, '\n');
            cur->fname = temp;
            cout << "Last name: ";
            char* temp1 = new char[100];
            cin.ignore(1000, '\n');
            cin.get(temp1, 100, '\n');
            cur->lname = temp1;
            cout << "Gender: ";
            cin >> cur->gender;
            char date[10];
            cout << "DOB: day: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->dob[0] = convert(date);
            cout << "Month: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->dob[1] = convert(date);
            cout << "Year: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->dob[2] = convert(date);
            while (checkDob(cur->dob) == false)
            {
                cout << "Invalid Date" << endl;
                cout << "DOB: Day: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->dob[0] = convert(date);
                cout << "Month: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->dob[1] = convert(date);
                cout << "Year: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->dob[2] = convert(date);

            }
            cout << "Social ID: ";
            char* temp2 = new char[100];
            cin.ignore(1000, '\n');
            cin.get(temp2, 100, '\n');
            cur->SID = temp2;
            cout << "No: ";
            cin >> cur->No;
            cur->next = new student;
            cur = cur->next;
            cout << "ID: ";
            cin.ignore(30, '\n');
            cin.get(id, 30, '\n');
            cur->ID = convert(id);
        }
    }
    else
    {

        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cout << "ID: ";
        char* id = new char[30];
        cin.ignore(30, '\n');
        cin.get(id, 30, '\n');
        cur->ID = convert(id);
        while (cur->ID != 0)
        {
            cout << "First name: ";
            char* temp = new char[100];
            cin.ignore(1000, '\n');
            cin.get(temp, 100, '\n');
            cur->fname = temp;
            cout << "Last name: ";
            char* temp1 = new char[100];
            cin.ignore(1000, '\n');
            cin.get(temp1, 100, '\n');
            cur->lname = temp1;
            cout << "Gender: ";
            cin >> cur->gender;
            char date[10];
            cout << "DOB: day: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->dob[0] = convert(date);
            cout << "Month: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->dob[1] = convert(date);
            cout << "Year: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->dob[2] = convert(date);
            while (checkDob(cur->dob) == false)
            {
                cout << "Invalid Date" << endl;
                cout << "DOB: day: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->dob[0] = convert(date);
                cout << "Month: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->dob[1] = convert(date);
                cout << "Year: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->dob[2] = convert(date);

            }
            cout << "Social ID: ";
            char* temp2 = new char[100];
            cin.ignore(1000, '\n');
            cin.get(temp2, 100, '\n');
            cur->SID = temp2;
            cout << "No: ";
            cin >> cur->No;



            cur->next = new student;
            cur = cur->next;
            cout << "ID: ";
            cin >> cur->ID;
        }
    }

    cur->next = nullptr;
}



void QuickInput(Class*& clist)
{
    ifstream fin("QuickInput.txt", ios_base::in);
    if (!fin.is_open()) {
        return;
    }
    student* head = clist->stlist;
    student* cur = clist->stlist;
    if (clist->stlist->ID == 0)
    {

        fin >> cur->ID;
        while (cur->ID != 0)
        {
            fin.ignore();
            char* name = new char[100];
            fin.getline(name, 100, ',');
            cur->fname = name;
            char* name1 = new char[100];
            fin.getline(name1, 100, ',');
            cur->lname = name1;
            fin >> cur->gender; fin.ignore();
            fin >> cur->dob[0]; fin.ignore();
            fin >> cur->dob[1]; fin.ignore();
            fin >> cur->dob[2]; fin.ignore();
            char* SID = new char[100];
            fin.getline(SID, 100, ',');

            cur->SID = SID;

            fin >> cur->No;
            fin.ignore();
            cur->next = new student;
            cur = cur->next;
            fin >> cur->ID;
        }

        cur->next = nullptr;
    }



    else
    {
        while (cur->next != nullptr) cur = cur->next;
        fin >> cur->ID;
        while (cur->ID != 0)
        {
            fin.ignore();
            char* name = new char[100];
            fin.getline(name, 100, ',');
            cur->fname = name;
            char* name1 = new char[100];
            fin.getline(name1, 100, ',');
            cur->lname = name1;
            fin >> cur->gender; fin.ignore();
            fin >> cur->dob[0]; fin.ignore();
            fin >> cur->dob[1]; fin.ignore();
            fin >> cur->dob[2]; fin.ignore();
            char* SID = new char[100];
            fin.getline(SID, 100, ',');

            cur->SID = SID;

            fin >> cur->No;
            fin.ignore();
            cur->next = new student;
            cur = cur->next;
            fin >> cur->ID;
        }
        cur->next = nullptr;
    }


    fin.close();
}
