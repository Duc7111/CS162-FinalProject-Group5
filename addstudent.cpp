#include <iostream>
#include <fstream>
#include "addstudent.h"
#include "Screen.h"
#include "AS.h"
using namespace std;







void AddStudent(Student*& list)
{
    Student* cur;
    Student* head;
    head = list;
    cur = list;
    Student* tmp = list;
    if (cur->next == nullptr)
    {


        cout << "no: ";
        cin >> cur->no;
        while (cur->no != 0)
        {
            while (Check(tmp, cur->no) == false)
            {
                cout << "Number already exist. Try again: ";
                cin >> cur->no;
            }
            cout << "ID: ";
            cin >> cur->ID;
            while (Check(tmp, cur->ID) == false)
            {
                cout << "ID already exist. Try again: ";
                cin >> cur->ID;
            }
            cout << "First name: ";
            char* temp = new char[100];
            cin.ignore(1000, '\n');
            cin.get(temp, 100, '\n');
            cur->FirstName = temp;
            cout << "Last name: ";
            char* temp1 = new char[100];
            cin.ignore(1000, '\n');
            cin.get(temp1, 100, '\n');
            cur->LastName = temp1;
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
            cur->next = new Student;
            cur = cur->next;
            cout << "no: ";
            cin >> cur->no;

            while (Check(tmp, cur->no) == false)
            {
                cout << "Number already exist. Try again: ";
                cin >> cur->no;
            }
        }
    }
    else
    {

        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cout << "no: ";
        cin >> cur->no;
        while (cur->no != 0)
        {
            cout << "ID: ";
            cin >> cur->ID;
            cout << "First name: ";
            char* temp = new char[100];
            cin.ignore(1000, '\n');
            cin.get(temp, 100, '\n');
            cur->FirstName = temp;
            cout << "Last name: ";
            char* temp1 = new char[100];
            cin.ignore(1000, '\n');
            cin.get(temp1, 100, '\n');
            cur->LastName = temp1;
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
            cur->next = new Student;
            cur = cur->next;
            cout << "no: ";
            cin >> cur->no;
        }

    }

    cur->next = nullptr;
}


// save student into text file
void SaveStudent(Student*& list)
{
    Student* cur = list;
    ofstream fout("FirstYearStudent.txt", ios_base::out | ios_base::app);
    while (cur->next != nullptr)
    {
        fout << cur->no << "," << cur->ID << "," << cur->FirstName << "," << cur->LastName << "," << cur->gender << "," << cur->dob[0] << "," << cur->dob[1] << "," << cur->dob[2] << "," << cur->SID << "," << endl;
        cur = cur->next;
    }
    fout.close();
}


// check if ID, no, SID are already entered
bool Check(Student*& list, int& id)
{
    Student* head = list;
    Student* cur = list;
    if (head->next == nullptr) return true;
    else
    {
        if (head->ID == id) return false;
        else
        {
            cur = cur->next;
            while (cur->next != nullptr && cur->ID != id)
            {
                cur = cur->next;
            }
            if (cur->ID == id) return false;
            else return true;
        }
    }
}

// load Student already entered
void LoadStudent(Student*& list)
{
    ifstream fin("FirstYearStudent.txt", ios_base::in);
    if (!fin.is_open()) {
        return;
    }
    Student* head = list;
    Student* cur = list;
    if (list->next == nullptr)
    {

        fin >> cur->no;
        fin.ignore();

        fin >> cur->ID;
        fin.ignore();
        char* name = new char[100];
        fin.getline(name, 100, ',');
        cur->FirstName = name;
        char* name1 = new char[100];
        fin.getline(name1, 100, ',');
        cur->LastName = name1;
        fin >> cur->gender; fin.ignore();
        fin >> cur->dob[0]; fin.ignore();
        if (cur->dob[0] == 0) return;
        fin >> cur->dob[1]; fin.ignore();
        fin >> cur->dob[2]; fin.ignore();
        char* SID = new char[100];
        fin.getline(SID, 100, ',');
        fin.ignore();
        cur->SID = SID;

        cur->next = new Student;
        cur = cur->next;

    }


    while (cur->next != nullptr) cur = cur->next;
    fin >> cur->no;
    fin.ignore();

    fin >> cur->ID;
    fin.ignore();
    char* name = new char[100];
    fin.getline(name, 100, ',');
    cur->FirstName = name;
    char* name1 = new char[100];
    fin.getline(name1, 100, ',');
    cur->LastName = name1;
    fin >> cur->gender; fin.ignore();
    fin >> cur->dob[0]; fin.ignore();
    fin >> cur->dob[1]; fin.ignore();
    fin >> cur->dob[2]; fin.ignore();
    char* SID = new char[100];
    fin.getline(SID, 100, ',');
    fin.ignore();
    cur->SID = SID;
    cur->next = new Student;
    cur = cur->next;


    cur->next = nullptr;
    fin.close();
}


//QuickInput

void QuickInput(Student*& list)
{
    ifstream fin("QuickInput.txt", ios_base::in);
    if (!fin.is_open()) {
        return;
    }
    Student* head = list;
    Student* cur = list;
    if (list->next == nullptr)
    {

        fin >> cur->no;
        fin.ignore();

        fin >> cur->ID;
        fin.ignore();
        char* name = new char[100];
        fin.getline(name, 100, ',');
        cur->FirstName = name;
        char* name1 = new char[100];
        fin.getline(name1, 100, ',');
        cur->LastName = name1;
        fin >> cur->gender; fin.ignore();
        fin >> cur->dob[0]; fin.ignore();
        if (cur->dob[0] == 0) return;
        fin >> cur->dob[1]; fin.ignore();
        fin >> cur->dob[2]; fin.ignore();
        char* SID = new char[100];
        fin.getline(SID, 100, ',');
        fin.ignore();
        cur->SID = SID;

        cur->next = new Student;
        cur = cur->next;

    }


    while (cur->next != nullptr) cur = cur->next;
    fin >> cur->no;
    fin.ignore();

    fin >> cur->ID;
    fin.ignore();
    char* name = new char[100];
    fin.getline(name, 100, ',');
    cur->FirstName = name;
    char* name1 = new char[100];
    fin.getline(name1, 100, ',');
    cur->LastName = name1;
    fin >> cur->gender; fin.ignore();
    fin >> cur->dob[0]; fin.ignore();
    fin >> cur->dob[1]; fin.ignore();
    fin >> cur->dob[2]; fin.ignore();
    char* SID = new char[100];
    fin.getline(SID, 100, ',');
    fin.ignore();
    cur->SID = SID;
    cur->next = new Student;
    cur = cur->next;


    cur->next = nullptr;
    fin.close();
}