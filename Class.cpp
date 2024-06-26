#include <fstream>

#include "const.h"
#include "console.h"
#include "Screen.h"
#include "AS.h"
#include "student.h"
#include "Class.h"
#include "data.h"
#include "addstudent.h"

using namespace std;

Class::Class() : name(""), stlist(nullptr){}

void Class::save2File()
{
    ofstream fout("data\\class\\class.txt", ios_base::app);
    fout << name << endl;
    fout.close();
    fout.open("data\\class\\" + name + ".txt", ios_base::trunc);
    fout.close();
    list<student>* temp = stlist;
    while(temp)
    {
        temp->data.save2File();
        temp = temp->next;
    }
}

void Class::save2FileE()
{
    ofstream fout("data\\class\\" + name + ".txt", ios_base::app);
    fout.close();
    list<student>* temp = stlist;
    while (temp)
    {
        temp->data.save2File();
        temp = temp->next;
    }

}

bool Class::checkClass()
{
    fstream fin("data\\class\\class.txt", ios_base::out | ios_base::app);
    fin.close();
    fin.open("data\\class\\class.txt", ios_base::in);
    string temp;
    while(!fin.eof())
    {
        getline(fin, temp);
        if(temp == name) return true;
    }
    return false;
}

void CreateNC(Class &new_class, AS log)
{
    Inscreen(log);
    cout << "Enter the name of the new class: ";
    //cin.ignore(1000, '\n');
    getline(cin, new_class.name);
    while (new_class.checkClass() == true) {
        cout << new_class.name << " Already existed on database." << endl;
        cout << "Try again" << endl;
        cout << "Enter the name of the new class: ";
        getline(cin, new_class.name);
    }
    //course insertion should be right here
    string choice;
    system("cls");
    Inscreen(log);
    cout << "1.Add student into class by hand." << endl;
    cout << "2.Use a CSV file." << endl;
    cout << "Your option: ";
    getline(cin, choice);
    int classc = convert(choice);
    while (classc != 1 && classc != 2) {
        cout << "Invalid Input. Try again." << endl;
        cout << "Your option: ";
        getline(cin, choice);
        classc = convert(choice);
    }
    if (classc == 1) {
        Inscreen(log);
        AddStudent(new_class,log);
        new_class.save2File();
    }
    else {
        system("cls");
        Inscreen(log);
        cout << "To Quickly input, you must prepare a text file name: ""QuickInput.txt"" " << endl;
        system("pause");
        QuickInput(new_class);
        new_class.save2File();
    }
    cout << "New class has been created successfully";
}


void GotoClass(Class& new_class, AS log)
{
    Inscreen(log);
    cout << "Enter the name of the class: ";
    //cin.ignore(1000, '\n');
    getline(cin, new_class.name);
    while (new_class.checkClass() == false) {
        cout << new_class.name << " do not existed on database." << endl;
        cout << "Try again" << endl;
        cout << "Enter the name of the class: ";
        getline(cin, new_class.name);
    }
    //course insertion should be right here
    string choice;
    system("cls");
    Inscreen(log);
    cout << "1.Add student into class by hand." << endl;
    cout << "2.Use a CSV file." << endl;
    cout << "Your option: ";
    getline(cin, choice);
    int classc = convert(choice);
    while (classc != 1 && classc != 2) {
        cout << "Invalid Input. Try again." << endl;
        cout << "Your option: ";
        getline(cin, choice);
        classc = convert(choice);
    }
    if (classc == 1) {
        Inscreen(log);
        AddStudent(new_class, log);
        new_class.save2FileE();
    }
    else {
        system("cls");
        Inscreen(log);
        cout << "To Quickly input, you must prepare a text file name: ""QuickInput.txt"" " << endl;
        system("pause");
        QuickInput(new_class);
        new_class.save2FileE();
    }
    cout << "New class has been created successfully";
}