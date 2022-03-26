#include<fstream>
#include<direct.h>

#include "AS.h"
#include "semester.h"
#include "schoolyear.h"
#include "Screen.h"
using namespace std;

semester::semester(): name(""), colist(nullptr){}

semester::semester(const string& dir)
{
    
    ifstream fin(dir + "\\data.txt");
    fin >> sdate[0]; fin.ignore(); 
    fin >> sdate[1]; fin.ignore(); 
    fin >> sdate[2]; fin.ignore(); 
    fin >> edate[0]; fin.ignore(); 
    fin >> edate[1]; fin.ignore(); 
    fin >> edate[2]; fin.ignore();
    colist = new list<course>;
    list<course>* temp = colist;
    while(!fin.eof())
    {
        int ID;
        fin >> ID; fin.ignore();
        temp->next = new list<course>;
        temp->next->data = course(ID);
        temp = temp->next;
    }
}

void semester::save2File(string dir)
{
    dir += "\\" + name;
    const char* d = dir.c_str();
    _mkdir(d);
    ofstream fout(dir + "\\data.txt");
    fout << sdate[0] << ',' << sdate[1] << ',' << sdate[2] << ',' << endl;
    fout << edate[0] << ',' << edate[1] << ',' << edate[2] << ',' << endl;
    list<course>* temp = colist;
    while(temp)
    {
        fout << temp->data.ID << endl;
        temp->data.save2File(dir);
        temp = temp->next;
    }
    fout.close();
}

void SemesterExecution(semester& se,AS log)
{
    //int d;
    string choice;
    /*
    cin.ignore(10, '\n');
    getline(cin, choice);
    se.name=choice;
    while (se.name != "1" || se.name != "2" || se.name != "3") {
        cout << "Invalid value. Try again." << endl << "Your choice: ";
        getline(cin, choice);
        se.name = choice;
    }*/
    //cin >> se->data.sn; changed to string name (read semester.h)
    system("cls");

    Inscreen(log);
    cout << "In the next section, please enter the start date and the start date of the semester" << endl;

    cout << "Day: ";
    getline(cin, choice);
    se.sdate[0] = convert(choice);

    cout << "Month: ";
    getline(cin, choice);
    se.sdate[1] = convert(choice);

    cout << "Year: ";
    getline(cin, choice);
    se.sdate[2] = convert(choice);
    while (checkDob(se.sdate) == false) {
        cout << "Invalid value. Try again." << endl;
        cout << "Day: ";
        getline(cin, choice);
        se.sdate[0] = convert(choice);

        cout << "Month: ";
        getline(cin, choice);
        se.sdate[1] = convert(choice);

        cout << "Year: ";
        getline(cin, choice);
        se.sdate[2] = convert(choice);
    }
    system("cls");
    Inscreen(log);
    cout << "In the next section, please enter the start date and the end date of the semester" << endl;
    
    cout << "Day: ";
    getline(cin, choice);
    se.edate[0] = convert(choice);

    cout << "Month: ";
    getline(cin, choice);
    se.edate[1] = convert(choice);

    cout << "Year: ";
    getline(cin, choice);
    se.edate[2] = convert(choice);
    while (checkDob(se.edate) == false) {
        cout << "Invalid value. Try again." << endl;
        cout << "Day: ";
        getline(cin, choice);
        se.edate[0] = convert(choice);

        cout << "Month: ";
        getline(cin, choice);
        se.edate[1] = convert(choice);

        cout << "Year: ";
        getline(cin, choice);
        se.edate[2] = convert(choice);
    }
    system("cls");

    //se->data.save2File();
    //cout << "Your newly executed semester has been saved successfully";
}

void getnamese(semester& se,AS log) {
    Inscreen(log);
    cout << "Please enter which semester you want to execute:" << endl;
    cout << "1. Fall           2. Summer           3. Autumn" << endl;
    cout << "Your choice: ";
    string choice;
    //cin.ignore(10, '\n');
    getline(cin, choice);
    while (choice != "1" && choice != "2" && choice != "3") {
        cout << "Invalid value. Try again." << endl << "Your choice: ";
        getline(cin, choice);
    }
    if (choice == "1")
        se.name = "Fall";
    else if (choice == "2")
        se.name = "Summer";
    else
        se.name = "Autumn";
}