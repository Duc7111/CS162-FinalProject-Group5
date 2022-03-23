#include <direct.h>
#include "course.h"

using namespace std;

course::course(): ms(50), cur(0){};

course::course(int id)
{

    ifstream fin("data\\course.txt");
    while(!fin.eof())
    {
        fin >> ID;
        if(ID == id) break;
        else fin.ignore(1000, '\n');
    }
    fin.ignore();
    string dir;
    getline(fin, dir);
    fin.close();
    fin.open(dir);
    getline(fin, name, ',');
    getline(fin, teacher, ',');
    fin >> credits; fin.ignore();
    fin >> ms; fin.ignore();
    fin >> cur; fin.ignore();
    stlist = new list<int[5]>;
    list<int[5]>* temp = stlist;
    for(int i = 0; i < cur; ++i)
    {
        temp->next = new list<int[5]>;
        temp = temp->next;
        fin >> temp->data[0]; fin.ignore();
        fin >> temp->data[1]; fin.ignore();
        fin >> temp->data[2]; fin.ignore();
        fin >> temp->data[3]; fin.ignore();
        fin >> temp->data[4]; fin.ignore();
    }
    temp = stlist;
    stlist = stlist->next;
    delete temp;
}

void course::save2File(string dir)
{
    dir += "\\" + to_string(ID) + ".txt";
    ofstream fout("data\\course.txt", ios_base::app);
    fout << ID << ',' << dir;
    fout.close(); 
    const char* d = dir.c_str();
    _mkdir(d);
    fout.open(dir);
    fout << name << ',' << teacher << ',' << credits << ',' << s[0] << ',' << s[1] << ',' << ms << ',' << cur;
    list<int[5]>* temp = stlist;
    while(temp)
    {
        fout << temp->data[0] << ',' << temp->data[1] << ',' << temp->data[2] << ',' << temp->data[3] << temp->data[4] << endl;
        temp = temp->next;
    }
    fout.close();
}
/*
void PreCourseRegisttration(CourseRegister& CR)
{
    cout << "Enter Course ID: "
    cin >> CR.RegCourse.ID;
    system("cls");

    cout << "In the next section, please enter the start date and the start date of the semester" << endl;
    system("cls");

    cout << "day: ";
    cin >> CR.sdate[0];
    system("cls");

    cout << "month: ";
    cin >> CR.sdate[1];
    system("cls");

    cout << "year: ";
    cin >> CR.sdate[2]
    system("cls");

    cout << "In the next section, please enter the start date and the end date of the semester" << endl;
    system("cls");

    cout << "day: ";
    cin >> CR.edate[0];
    system("cls");

    cout << "month: ";
    cin >> CR.edate[1];
    system("cls");

    cout << "year: ";
    cin >> CR.edate[2];
    system("cls");

    se->data.save2File();
    cout << "Your newly executed semester has been saved successfully";
}
*/
