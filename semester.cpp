#include<fstream>
#include<direct.h>

#include "AS.h"
#include "semester.h"
#include "schoolyear.h"
#include "Screen.h"
#include "course.h"


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


void AddCourse2Semester(semester& sem)
{
    list<course>* cur = sem.colist;
    if (cur->data.ID == 0)
    {
        cout << "Enter the course ID: ";
        cin >> cur->data.ID;
        cin.ignore();
        cout << "Enter the course's name: ";
        getline(cin, cur->data.name, '\n');
        cout << "Enter the teacher's name: ";
        getline(cin, cur->data.teacher,'\n');
        cout << "Enter the number of credits: ";
        cin >> cur->data.credits;
        cout << "Enter the maximum number of student: ";
        cin >> cur->data.ms;
        cur->data.cur = 0;
        cout << "Enter the first session that the course will be performed:" << endl;
        cout << "(MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || Section = day*7 + S)" << endl;
        cin >> cur->data.s[0];
        while (!CheckSection(cur->data.s[0]))
        {
            cout << "Invalid section. Try again" << endl;
            cout << "Enter the first session that the course will be performed:" << endl;
            cout << "(MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || Section = day*7 + S)" << endl;
            cin >> cur->data.s[0];
        }
        cout << "Enter the second session that the course will be performed:" << endl;
        cout << "(MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || Section = day*7 + S)" << endl;
        cin >> cur->data.s[1];
        while (!CheckSection(cur->data.s[1]) || cur->data.s[1] == cur->data.s[0])
        {
            cout << "Invalid section. Try again" << endl;
            cout << "Enter the second session that the course will be performed:" << endl;
            cout << "(MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || Section = day*7 + S)" << endl;
            cin >> cur->data.s[1];
        }
        PrintSection(cur->data.s[0], cur->data.s[1]);
    }
    else
    {
        while (cur->next != nullptr) cur = cur->next;
        cur->next = new list<course>;
        cur = cur->next;
        cout << "Enter the course ID: ";
        cin >> cur->data.ID;
        cin.ignore();
        cout << "Enter the course's name: ";
        getline(cin, cur->data.name, '\n');
        cout << "Enter the teacher's name: ";
        getline(cin, cur->data.teacher, '\n');
        cout << "Enter the number of credits: ";
        cin >> cur->data.credits;
        cout << "Enter the maximum number of student: ";
        cin >> cur->data.ms;
        cur->data.cur = 0;
        cout << "Enter the first session that the course will be performed:" << endl;
        cout << "(MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || Section = day*7 + S)" << endl;
        cin >> cur->data.s[0];
        while (!CheckSection(cur->data.s[0]))
        {
            cout << "Invalid section. Try again" << endl;
            cout << "Enter the first session that the course will be performed:" << endl;
            cout << "(MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || Section = day*7 + S)" << endl;
            cin >> cur->data.s[0];
        }
        cout << "Enter the second session that the course will be performed:" << endl;
        cout << "(MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || Section = day*7 + S)" << endl;
        cin >> cur->data.s[1];
        while (!CheckSection(cur->data.s[1]) || cur->data.s[1] == cur->data.s[0])
        {
            cout << "Invalid section. Try again" << endl;
            cout << "Enter the second session that the course will be performed:" << endl;
            cout << "(MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || Section = day*7 + S)" << endl;
            cin >> cur->data.s[1];
        }
        PrintSection(cur->data.s[0], cur->data.s[1]);
    }
    cur->next = nullptr;
}

void ViewCourse(semester& sem)
{
    list<course>* cur = sem.colist;

    if (cur->data.ID == 0)
    {
        cout << "There are no courses" << endl;
        return;
    }
    else
    {
        cout << "Courses list:" << endl;
        PrintCourse(cur);
        cout << endl;
        while (cur->next != nullptr)
        {
            cur = cur->next;
            PrintCourse(cur);
            cout << endl;
            
        }
    }
    delete cur;
}

