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

semester::semester(const string& dir)
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
            int ID = 0;
            fin >> ID;
            if(ID == 0) break; 
            fin.ignore();
            temp->next = new list<course>;
            temp->next->data = course(ID);
            temp = temp->next;
        }
        temp = colist;
        colist = colist->next;
        delete temp;
    }
    else
    {
        name = "";
        colist = nullptr;
    }
    fin.close();
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


void AddCourse2Semester(semester& sem, AS log)
{
    string num;
    Inscreen(log);
    list<course>* cur = sem.colist;
    if (cur->data.ID == 0)
    {
        cout << "Enter the course ID (Input 0 to stop): ";
        string id;
        getline(cin, id);
        cur->data.ID=convert(id);
        while (cur->data.ID < 0) {
            cout << "Invalid Input. Try again." << endl;
            cout << "Enter the course ID (Input 0 to stop): ";
            getline(cin, id);
            cur->data.ID = convert(id);
        }
        if (cur->data.ID == 0) return;
        do
        {
            //cin.ignore();
            cout << "Enter the course's name: ";
            getline(cin, cur->data.name, '\n');
            cout << "Enter the teacher's name: ";
            getline(cin, cur->data.teacher, '\n');
            cout << "Enter the number of credits: ";
           
            getline(cin, num);
            cur->data.credits = convert(num);
            while (cur->data.credits < 0) {
                cout << "Invalid Input. Try again." << endl;
                cout << "Enter the number of credits: ";
                getline(cin, num);
                cur->data.credits = convert(num);
            }
            cout << "Enter the maximum number of student: ";
            getline(cin, num);
            cur->data.ms = convert(num);
            while (cur->data.ms < 0) {
                cout << "Invalid Input. Try again." << endl;
                cout << "Enter the maximum number of student: ";
                getline(cin, num);
                cur->data.ms = convert(num);
            }
            //cin >> cur->data.ms;
            cur->data.cur = 0;
            cout << "Enter the first session that the course will be performed:" << endl;
            cout << "(MON = 0, TUE = 1, ..., S1 = 1, S2 = 2 || Section = day*7 + S)" << endl;
            cin >> cur->data.s[0];
            while (!CheckSection(cur->data.s[0]))
            {
                cout << "Invalid section. Try again" << endl;
                cout << "Enter the first session that the course will be performed:" << endl;
                cout << "(MON = 0, TUE = 1, ..., SUN = 6; S1 = 1, S2 = 2, S3 = 3 , S4 = 4 || Section = day*7 + S)" << endl;
                cin >> cur->data.s[0];
            }
            cout << "Enter the second session that the course will be performed:" << endl;
            cout << "(MON = 0, TUE = 1, ..., SUN = 6; S1 = 1, S2 = 2, S3 = 3 , S4 = 4 || Section = day*7 + S)" << endl;
            cin >> cur->data.s[1];
            while (!CheckSection(cur->data.s[1]) || cur->data.s[1] == cur->data.s[0])
            {
                cout << "Invalid section. Try again" << endl;
                cout << "Enter the second session that the course will be performed:" << endl;
                cout << "(MON = 0, TUE = 1, ..., SUN = 6; S1 = 1, S2 = 2, S3 = 3 , S4 = 4 || Section = day*7 + S)" << endl;
                cin >> cur->data.s[1];
            }
            PrintSection(cur->data.s[0], cur->data.s[1]);
            cur->next = new list <course>;
            cur = cur->next;
            Inscreen(log);
            cout << "Enter the course ID: ";
            cin.ignore(10,'\n');
            getline(cin, id);
            cur->data.ID = convert(id);
            while (cur->data.ID < 0) {
                cout << "Invalid Input. Try again." << endl;
                cout << "Enter the course ID(Input 0 to stop): ";
                getline(cin, id);
                cur->data.ID = convert(id);
            }


        } while (cur->data.ID != 0);
        
    }
    else
    {
        while (cur->next != nullptr) cur = cur->next;
        cur->next = new list<course>;
        cur = cur->next;
        cout << "Enter the course ID: ";
        string id;
        getline(cin, id);
        cur->data.ID = convert(id);
        while (cur->data.ID < 0) {
            cout << "Invalid Input. Try again." << endl;
            cout << "Enter the course ID: ";
            getline(cin, id);
            cur->data.ID = convert(id);
        }
        if (cur->data.ID == 0) return;
        do
        {
            //cin.ignore();
            cout << "Enter the course's name: ";
            getline(cin, cur->data.name, '\n');
            cout << "Enter the teacher's name: ";
            getline(cin, cur->data.teacher, '\n');
            cout << "Enter the number of credits: ";

            getline(cin, num);
            cur->data.credits = convert(num);
            while (cur->data.credits < 0) {
                cout << "Invalid Input. Try again." << endl;
                cout << "Enter the number of credits: ";
                getline(cin, num);
                cur->data.credits = convert(num);
            }
            cout << "Enter the maximum number of student: ";
            getline(cin, num);
            cur->data.ms = convert(num);
            while (cur->data.ms < 0) {
                cout << "Invalid Input. Try again." << endl;
                cout << "Enter the maximum number of student: ";
                getline(cin, num);
                cur->data.ms = convert(num);
            }
            cur->data.cur = 0;
            cout << "Enter the first session that the course will be performed:" << endl;
            cout << "(MON = 0, TUE = 1, ..., SUN = 6; S1 = 1, S2 = 2, S3 = 3 , S4 = 4 || Section = day*7 + S)" << endl;
            cin >> cur->data.s[0];
            while (!CheckSection(cur->data.s[0]))
            {
                cout << "Invalid section. Try again" << endl;
                cout << "Enter the first session that the course will be performed:" << endl;
                cout << "(MON = 0, TUE = 1, ..., SUN = 6; S1 = 1, S2 = 2, S3 = 3 , S4 = 4 || Section = day*7 + S)" << endl;
                cin >> cur->data.s[0];
            }
            cout << "Enter the second session that the course will be performed:" << endl;
            cout << "(MON = 0, TUE = 1, ..., SUN = 6; S1 = 1, S2 = 2, S3 = 3 , S4 = 4 || Section = day*7 + S)" << endl;
            cin >> cur->data.s[1];
            while (!CheckSection(cur->data.s[1]) || cur->data.s[1] == cur->data.s[0])
            {
                cout << "Invalid section. Try again" << endl;
                cout << "Enter the second session that the course will be performed:" << endl;
                cout << "(MON = 0, TUE = 1, ..., SUN = 6; S1 = 1, S2 = 2, S3 = 3 , S4 = 4 || Section = day*7 + S)" << endl;
                cin >> cur->data.s[1];
            }
            PrintSection(cur->data.s[0], cur->data.s[1]);
            cur->next = new list <course>;
            cur = cur->next;
            cout << "Enter the course ID(Input 0 to stop): ";
            cin >> cur->data.ID;
        } while (cur->data.ID != 0);
        
    }
    list <course> *tmp = sem.colist;
    while (tmp->next->next != nullptr) tmp = tmp->next;
    delete cur;
    tmp->next = nullptr;
}

void ViewCourse(schoolyear & sy, semester& sem)
{
    LoadCourses(sy, sem);
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

void ViewCoursese(semester& sem) {// Semester Existed
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
    
    string str;
    int temp;

    cout << "Enter the ID of the course: ";
    getline(cin, str);
    temp = convert(str);
    string dir = "data\\schoolyear\\";
    ifstream fin(dir + sy.name + "\\" + sem.name + "\\data.txt");
    id = 0;
    fin.ignore(100,'\n');
    fin.ignore(100,'\n');
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

bool FindCoursest(semester& sem,int & id)
{
    string str;
    int temp;
    cout << "Enter the ID of the course you want to register: ";
    getline(cin, str);
    temp = convert(str);
    list<course>* colist=sem.colist;
    while (colist != nullptr) {
        if (colist->data.ID == temp) {
            id = colist->data.ID;
            return true;
        }
        else {
            colist = colist->next;
        }
    }
    return false;
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
        system("pause");
        //cout << "Enter 1 if you want to update another information, enter 0 if you want to stop: ";
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





void LoadCourses(schoolyear& sy, semester& sem)
{
    list<course>* cur = sem.colist;
    int id = 0;
    string dir = "data\\schoolyear\\";
    ifstream fin(dir + sy.name + "\\" + sem.name + "\\data.txt");
    if (!fin.is_open()) return;
    fin.ignore(100, '\n');
    fin.ignore(100, '\n');
    while (!fin.eof())
    {
        fin >> id;
        if (id == 0) return;
        cur->data.ID = id;
        string str = to_string(id);
        ifstream fin1(dir + sy.name + "\\" + sem.name + "\\" + str + "\\data.txt", ios_base::in);
        getline(fin1, cur->data.name, ',');
        getline(fin1, cur->data.teacher, ',');
        fin1 >> cur->data.credits; fin1.ignore();
        fin1 >> cur->data.s[0]; fin1.ignore();
        fin1 >> cur->data.s[1]; fin1.ignore();
        fin1 >> cur->data.ms; fin1.ignore();
        fin1 >> cur->data.cur; fin1.ignore();
        fin1.close();
        cur->next = new list<course>;
        cur = cur->next;
    }
    fin.close();
    list <course>* tmp = sem.colist;
    while (tmp->next->next != nullptr) tmp = tmp->next;
    delete cur;
    tmp->next = nullptr;
    list <course>* tmp2 = sem.colist;
    while (tmp2->next->next != nullptr) tmp2 = tmp2->next;
    delete tmp;
    tmp2->next = nullptr;
    

}

void viewCourseStudent(schoolyear& sy, semester& sem)
{
    int id;
    FindCourse(sy, sem, id);
    string dir = "data\\schoolyear\\";
    string str = to_string(id);
    ifstream fin(dir + sy.name + "\\" + sem.name + "\\" + str + "\\data.txt", ios_base::in);
    list<int>* studentid = new list<int>;
    list<int>* cur = studentid;
    fin.ignore(1000,'\n');
    while (!fin.eof())
    {
        fin >> cur->data;
        cur->next = new list<int>;
        cur = cur->next;
        fin.ignore(1000,'\n');
    }
    fin.close();
    cur->next = nullptr;
    FindStudent(studentid);
}

void FindStudent(list<int>* studentid)
{
    list<int>* cur = studentid;
    int tmp = studentid->data;
    if (tmp == 0) return;
    ifstream fin("data\\class\\class.txt");
    string str;
    while (!fin.eof())
    {
        getline(fin, str, '\n');
        ifstream fin1("data\\class\\" + str + ".txt");
        int result;
        fin1 >> result;

        while (result != tmp)
        {
            if (fin1.eof()) break;
            fin1.ignore(1000, '\n');
            fin1 >> result;
        }
        if (result == tmp)
        {
            student st;
            st.ID = tmp;
            fin1.ignore();
            getline(fin1, st.fname, ',');
            getline(fin1, st.lname, ',');
            fin1 >> st.gender; fin1.ignore();
            fin1 >> st.dob[0]; fin1.ignore();
            fin1 >> st.dob[1]; fin1.ignore();
            fin1 >> st.dob[2]; fin1.ignore();
            getline(fin1, st.SID, ',');
            fin1 >> st.No;
            cout << "ID: " << st.ID << endl;
            cout << "Fullname: " << st.fname << " " << st.lname << endl;
            cout << "Gender: ";
            if (st.gender == 1) cout << "Male" << endl;
            else cout << "Female" << endl;
            cout << "D.O.B: " << st.dob[0] << "/" << st.dob[1] << "/" << st.dob[2] << endl;
            cout << "SID: " << st.SID << endl;
            cout << '\n';
            break;
        }
        fin1.close();
        
    }
    fin.close();
    
    if (studentid->next != nullptr) return FindStudent(studentid->next);
}

