#include<fstream>
#include<direct.h>

#include "semester.h"
#include "schoolyear.h"

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

void SemesterExecution(list<semester>*& se)
{
    //int d;
    cout << "Please enter which semester you want to execute:" << endl;
    cout << "1. Fall           2. Summer           3. Autunn" << endl;
    cout << "your choice: ";
    //cin >> se->data.sn; changed to string name (read semester.h)
    system("cls");

    cout << "In the next section, please enter the start date and the start date of the semester" << endl;
    system("cls"); 

    cout << "Day: ";
    cin >> se->data.sdate[0];
    system("cls");

    cout << "Month: ";
    cin >> se->data.sdate[1];
    system("cls");

    cout << "year: ";
    cin >> se->data.sdate[2];
    system("cls");

    cout << "In the next section, please enter the start date and the end date of the semester" << endl;
    system("cls");

    cout << "Day: ";
    cin >> se->data.edate[0];
    system("cls");

    cout << "Month: ";
    cin >> se->data.edate[1];
    system("cls");

    cout << "year: ";
    cin >> se->data.edate[2];
    system("cls");

    //se->data.save2File();
    cout << "Your newly executed semester has been saved successfully";
}
