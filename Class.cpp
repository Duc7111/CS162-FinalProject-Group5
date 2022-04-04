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

void CreateNC(Class &new_class, AS log)
{
    Inscreen(log);
    cout << "Enter the name of the new class: ";
    //cin.ignore(1000, '\n');
    getline(cin, new_class.name);
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
