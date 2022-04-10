#include<fstream>
#include<direct.h>

#include "AS.h"
#include "semester.h"
#include "schoolyear.h"
#include "Screen.h"
#include "course.h"
#include "console.h"



using namespace std;

semester::semester(): name(""), colist(nullptr){}

semester::semester(const string& dir) : semester()
{
    ifstream fin(dir + "\\data.txt");
    if(fin.is_open())
    {
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
}

void semester::save2File(string dir)
{
    if(name == "") return;
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

void semester::setCur(const string& dir)
{
    ofstream fout("data\\data.txt", ios_base::trunc);
    fout << dir;
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

int getnamese(AS log) {
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
    int cse = convert(choice);
    return cse;
}


void AddCourse2Semester(semester& sem)
{
    list<course>* cur = sem.colist;
    if (cur->data.ID == 0)
    {
        cout << "Enter the course ID: ";
        cin >> cur->data.ID;
        if (cur->data.ID == 0) return;
        do
        {
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
            cur->next = new list <course>;
            cur = cur->next;
            cout << "Enter the course ID: ";
            cin >> cur->data.ID;


        } while (cur->data.ID != 0);
        
    }
    else
    {
        while (cur->next != nullptr) cur = cur->next;
        cur->next = new list<course>;
        cur = cur->next;
        cout << "Enter the course ID: ";
        cin >> cur->data.ID;
        if (cur->data.ID == 0) return;
        do
        {
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
            cur->next = new list <course>;
            cur = cur->next;
            cout << "Enter the course ID: ";
            cin >> cur->data.ID;
        } while (cur->data.ID != 0);
        
    }
    list <course> *tmp = sem.colist;
    while (tmp->next->next != nullptr) tmp = tmp->next;
    delete cur;
    tmp->next = nullptr;

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
}

void FindCourse(schoolyear& sy, semester& sem, int& id)
{
    
    int temp;
    cout << "Enter the ID of the course you want to update: ";
    cin >> temp;
    string dir = "data\\schoolyear\\";
    ifstream fin( dir + sy.name + "\\" + sem.name + "\\data.txt");
    id = 0;
    fin.ignore('\n');
    fin.ignore('\n');
    fin.ignore();
    while (id != temp)
    {
        if (fin.eof())
        {
            cout << "invalid ID. Try again: " << endl;
            return FindCourse(sy, sem, id);
        }
        else
        {
            fin >> id;
        }
    }


    fin.close();


}

void UpdateCourse(schoolyear& sy, semester& sem)
{
    int id;
    FindCourse(sy, sem, id);
    string dir = "data\\schoolyear\\";
    string str = to_string(id);
    ifstream fin(dir + sy.name + "\\" + sem.name + "\\" + str + "\\data.txt" , ios_base::in);
    list <course>* tmp = new list<course>;
    getline(fin, tmp->data.name, ',');
    getline(fin, tmp->data.teacher, ',');
    fin >> tmp->data.credits; fin.ignore();
    fin >> tmp->data.s[0]; fin.ignore();
    fin >> tmp->data.s[1]; fin.ignore();
    fin >> tmp->data.ms; fin.ignore();
    fin >> tmp->data.cur; fin.ignore();
    fin.close();
   
    int temp = 1;
    do
    {
        system("cls");
        cout << "Course ID: " << id << endl;
        cout << "Course's name: " << tmp->data.name << endl;
        cout << "Teacher: " << tmp->data.teacher << endl;
        cout << "Number of credits: " << tmp->data.credits << endl;
        cout << "Maximum number of students: " << tmp->data.ms << endl;
        cout << "Current number of students: " << tmp->data.cur << endl;
        PrintSection(tmp->data.s[0], tmp->data.s[1]);
        for (int i = 0; i < 5; i++)
        {
            gotoxy(80, i + 1);
            cout << "(" << i + 1 << ")";
        }
        for (int i = 5; i < 7; i++)
        {
            gotoxy(80, i + 2);
            cout << "(" << i + 1 << ")";
        }
        cout << endl << "Enter the number of the line you want to update: " << endl;
        int choice;
        cin >> choice;
        while (choice <= 0 || choice > 7)
        {
            cout << "Invalid choice. Try again" << endl;
            cout << endl << "Enter the number of the line you want to update: " << endl;
            cin >> choice;
        }
        Update(tmp, choice);
        system("cls");
        cout << "The new course info: " << endl;
        cout << "Course ID: " << id << endl;
        cout << "Course's name: " << tmp->data.name << endl;
        cout << "Teacher: " << tmp->data.teacher << endl;
        cout << "Number of credits: " << tmp->data.credits << endl;
        cout << "Maximum number of students: " << tmp->data.ms << endl;
        cout << "Current number of students: " << tmp->data.cur << endl;
        PrintSection(tmp->data.s[0], tmp->data.s[1]);
        cout << "Enter 1 if you want to update another information, enter 0 if you want to stop: ";
        cin >> temp;
    } while (temp == 1);
    ofstream fout(dir + sy.name + "\\" + sem.name + "\\" + str + "\\data.txt");
    fout << tmp->data.name << ',' << tmp->data.teacher << ',' << tmp->data.credits << ',' << tmp->data.s[0] << ',' << tmp->data.s[1] << ',' << tmp->data.ms << ',' << tmp->data.cur;
    fout.close();
}



void Update(list <course>* tmp, int choice)
{
    switch (choice)
    {
    case 1:
    {
        cout << "Enter the new course name: ";
        cin.ignore();
        getline(cin, tmp->data.name, '\n');
        break;
    }
    case 2:
    {
        cout << "Enter the new teacher name: ";
        cin.ignore();
        getline(cin, tmp->data.teacher, '\n');
        break;
    }case 3:
    {
        cout << "Enter the new number of credits: ";
        cin >> tmp->data.credits;
        break;
    }case 4:
    {
        cout << "Enter the new maximum number of students: ";
        cin >> tmp->data.ms;
        break;
    }case 5:
    {
        cout << "Enter the new current number of student: ";
        cin >> tmp->data.cur;
        break;
    }case 6:
    {
        cout << "Enter the new section: ";
        cin >> tmp->data.s[0];
        while (!CheckSection(tmp->data.s[0]) || tmp->data.s[0] == tmp->data.s[1])
        {
            cout << "Invalid section. Try again" << endl;
            cout << "Enter the new section: ";
            cin >> tmp->data.s[0];
        }

        break;
    }case 7:
    {
        cout << "Enter the new section: ";
        cin >> tmp->data.s[1];
        while (!CheckSection(tmp->data.s[1]) || tmp->data.s[1] == tmp->data.s[0])
        {
            cout << "Invalid section. Try again" << endl;
            cout << "Enter the new section: ";
            cin >> tmp->data.s[1];
        }

        break;
    }
    };
}