#include <iostream>
#include <fstream>
#include <string>
#include "Screen.h"
#include "AS.h"
#include "Class.h"
#include "const.h"
#include "student.h"
using namespace std;



void AddStudent(Class& clist,AS log)
{

    list<student>* cur = clist.stlist;


    if (cur->next == nullptr)
    {
        Inscreen(log);
        cout << "ID (Input 0 to stop): ";
        cin >> cur->data.ID;

        while (cur->data.ID != 0)
        {
            cout << "First name: ";
            cin.ignore();
            getline(cin, cur->data.fname);
            cout << "Last name: ";
            getline(cin, cur->data.lname);
            cout << "Gender (0:Male & 1:Female): ";
            cin >> cur->data.gender;
            char date[10];
            cout << "DOB: Day: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->data.dob[0] = convert(date);
            cout << "Month: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->data.dob[1] = convert(date);
            cout << "Year: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->data.dob[2] = convert(date);
            while (checkDob(cur->data.dob) == false)
            {
                cout << "Invalid Date" << endl;
                cout << "DOB: Day: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->data.dob[0] = convert(date);
                cout << "Month: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->data.dob[1] = convert(date);
                cout << "Year: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->data.dob[2] = convert(date);

            }
            cur->data.clname = clist.name;
            
            cout << "Social ID: ";
            cin.ignore();
            getline(cin, cur->data.SID);
            cout << "No: ";
            cin >> cur->data.No;
            cur->data.pass = cur->data.SID;
            cur->data.createAcc();
            cur->next = new list<student>;
            cur = cur->next;
            Inscreen(log);
            cout << "ID (Input 0 to stop): ";
            cin >> cur->data.ID;
        }
        //cur->next = nullptr;
    }
    else
    {

        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        Inscreen(log);
        cout << "ID (Input 0 to stop): ";
        cin >> cur->data.ID;
        while (cur->data.ID != 0)
        {
            cout << "First name: ";
            cin.ignore();
            getline(cin, cur->data.fname);
            cout << "Last name: ";
            getline(cin, cur->data.lname);
            cout << "Gender (0:Male & 1:Female): ";
            cin >> cur->data.gender;
            char date[10];
            cout << "DOB: Day: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->data.dob[0] = convert(date);
            cout << "Month: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->data.dob[1] = convert(date);
            cout << "Year: ";
            cin.ignore(10, '\n');
            cin.get(date, 10);
            cur->data.dob[2] = convert(date);
            while (checkDob(cur->data.dob) == false)
            {
                cout << "Invalid Date" << endl;
                cout << "DOB: Day: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->data.dob[0] = convert(date);
                cout << "Month: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->data.dob[1] = convert(date);
                cout << "Year: ";
                cin.ignore(10, '\n');
                cin.get(date, 10);
                cur->data.dob[2] = convert(date);

            }
            cur->data.clname = clist.name;
            cout << "Social ID: ";
            cin.ignore();
            getline(cin, cur->data.SID);
            cout << "No: ";
            cin >> cur->data.No;
            cur->data.pass = cur->data.SID;
            cur->data.createAcc();
            cur->next = new list<student>;
            cur = cur->next;
            Inscreen(log);
            cout << "ID (Input 0 to stop): ";
            cin >> cur->data.ID;
        }
    }

    cur->next = nullptr;
}

void QuickInput(Class& clist)
{
    ifstream fin("QuickInput.txt", ios_base::in);
    if (!fin.is_open()) {
        return;
    }

    list<student>* cur = clist.stlist;

    if (clist.stlist->data.ID == 0)
    {

        fin >> cur->data.ID;
        while (cur->data.ID != 0)
        {

            fin.ignore();
            getline(fin, cur->data.fname, ',');
            getline(fin, cur->data.lname, ',');
            fin >> cur->data.gender; fin.ignore();
            fin >> cur->data.dob[0]; fin.ignore();
            fin >> cur->data.dob[1]; fin.ignore();
            fin >> cur->data.dob[2]; fin.ignore();
            getline(fin, cur->data.SID, ',');
            fin >> cur->data.No;
            fin.ignore();
            cur->data.pass = cur->data.SID;
            cur->data.clname = clist.name;
            cur->data.createAcc();
            cur->next = new list<student>;
            cur = cur->next;
            fin >> cur->data.ID;
        }

        cur->next = nullptr;
    }



    else
    {
        while (cur->next != nullptr) cur = cur->next;
        fin >> cur->data.ID;
        while (cur->data.ID != 0)
        {

            fin.ignore();
            getline(fin, cur->data.fname, ',');
            getline(fin, cur->data.lname, ',');
            fin >> cur->data.gender; fin.ignore();
            fin >> cur->data.dob[0]; fin.ignore();
            fin >> cur->data.dob[1]; fin.ignore();
            fin >> cur->data.dob[2]; fin.ignore();
            getline(fin, cur->data.SID, ',');
            fin >> cur->data.No;
            fin.ignore();
            cur->data.pass = cur->data.SID;
            cur->data.clname = clist.name;
            cur->data.createAcc();
            cur->next = new list<student>;
            cur = cur->next;
            fin >> cur->data.ID;
        }
        cur->next = nullptr;
    }


    fin.close();

}
