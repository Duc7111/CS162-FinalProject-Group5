#include <iostream>
#include <fstream>
#include <string>
#include "addstudent.h"
#include "Screen.h"
#include "AS.h"
#include "Class.h"
#include "const.h"

using namespace std;


/*
void AddStudent(Class*& clist)
{
    
    student* cur;
    cur = clist->stlist;
    if (cur->ID == 0)
    {
        cout << "ID: ";
        cin >> cur->ID;
        while (cur->ID != 0)
        {
            cout << "First name: ";
            cin.ignore();
            getline(cin, cur->fname);
            cout << "Last name: ";
            getline(cin, cur->lname);
            cout << "Gender: ";
            cin >> cur->gender;
            char date[10];
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
            cin.ignore();
            getline(cin, cur->SID);
            cout << "No: ";
            cin >> cur->No;
            cur->pass = cur->SID;
            cur->next = new student;
            cur = cur->next;
            cout << "ID: ";
            cin >> cur->ID;
        }
    }
    else
    {

        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cout << "ID: ";
        cin >> cur->ID;
        while (cur->ID != 0)
        {
            cout << "First name: ";
            cin.ignore();
            getline(cin, cur->fname);
            cout << "Last name: ";
            getline(cin, cur->lname);
            cout << "Gender: ";
            cin >> cur->gender;
            char date[10];
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
            cin.ignore();
            getline(cin, cur->SID);
            cout << "No: ";
            cin >> cur->No;
            cur->pass = cur->SID;
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
            getline(fin, cur->fname,',');
            getline(fin, cur->lname,',');
            fin >> cur->gender; fin.ignore();
            fin >> cur->dob[0]; fin.ignore();
            fin >> cur->dob[1]; fin.ignore();
            fin >> cur->dob[2]; fin.ignore();
            getline(fin, cur->SID, ',');
            fin >> cur->No;
            fin.ignore();
            cur->pass = cur->SID;
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
            getline(fin, cur->fname, ',');
            getline(fin, cur->lname, ',');
            fin >> cur->gender; fin.ignore();
            fin >> cur->dob[0]; fin.ignore();
            fin >> cur->dob[1]; fin.ignore();
            fin >> cur->dob[2]; fin.ignore();
            getline(fin, cur->SID, ',');
            fin >> cur->No;
            fin.ignore();
            cur->pass = cur->SID;
            cur->next = new student;
            cur = cur->next;
            fin >> cur->ID;
        }
        cur->next = nullptr;
    }

    
    fin.close();
}
*/