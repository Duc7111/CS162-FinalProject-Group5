#include <fstream>
#include <string>
#include <iomanip>

#include "course.h"
#include "student.h"
#include "const.h"

using namespace std;


student::student() : colist(nullptr) {}

student::student(int id)
{
    ifstream fin("data\\student.txt");
    while(!fin.eof())
    {
        fin >> ID;
        if(ID == id)
        {
            fin.ignore();
            getline(fin, pass, ',');
            getline(fin, clname);
            fin.close();
            fin.open("data\\class\\" + clname + ".txt");
            if(!fin.is_open())
            {
                cout << "Cannot open data\\class\\" << clname << ".txt";
                return;
            }
            while(!fin.eof())
            {
            
                fin >> id;
                if(ID == id)
                {
                    fin.ignore();
                    getline(fin, fname, ',');
                    getline(fin, lname, ',');
                    fin >> gender; fin.ignore();
                    fin >> dob[0]; fin.ignore();
                    fin >> dob[1]; fin.ignore();
                    fin >> dob[2]; fin.ignore();
                    getline(fin, SID, ',');
                    fin >> No;
                    conum = 0;
                    colist = new list<course>;
                    list<course>* temp = colist;
                    while(!fin.eof() && fin.get() == ',')
                    {
                        ++conum;
                        int ID1;
                        fin >> ID1;
                        temp->next = new list<course>;
                        temp->data = course(ID1);
                        if(temp->data.ID == 0 || !temp->data.checkStudent(ID)) 
                        {
                            delete temp->next;
                            temp->next = nullptr;
                        }
                        else temp = temp->next;
                    }
                    return;
                }
                else fin.ignore(1000, '\n');
            }
        }
        else fin.ignore(1000, '\n');
    }
}

bool student::createAcc()
{
    ofstream fout("data\\student.txt", ios_base::app);
    ifstream fin("data\\student.txt");
    int id;
    while(!fin.eof())
    {
        fin >> id;
        if(id == ID) return false;
        else fin.ignore(1000, '\n');
    }
    fin.close();
    fout << ID << ',' << pass << ',' << clname << endl;
    fout.close();
}

void student::save2File()
{
    if(clname == "") return;
    ofstream fout("data\\class\\" + clname + ".txt", ios_base::app);
    fout << ID << ',' << fname << ',' << lname << ',' << gender << ',' << dob[0] << ',' << dob[1] << ',' << dob[2] << ',' << SID << ',' << No;
    list<course>* temp = colist;
    while(temp)
    {
        fout << ',' << temp->data.ID;
        temp = temp->next;
    }
    fout << endl;
    fout.close();
}

void student::change()
{
    ifstream fin("data\\class\\" + clname + ".txt");
    ofstream fout("temp.txt");
    string temp;
    while(!fin.eof())
    {
        int id;
        fin >> id;
        if(id == ID)
        {
            fout << ID << ',' << fname << ',' << lname << ',' << gender << ',' << dob[0] << ',' << dob[1] << ',' << dob[2] << ',' << SID << ',' << No;
            list<course>* temp = colist;
            while(temp)
            {
                if(temp->data.ID!=0)
                    fout << ',' << temp->data.ID;
                temp = temp->next;
            }
            fout << endl;
            fin.ignore(1000, '\n');
            break;
        }
        else
        {
            fout << id;
            getline(fin, temp);
            fout << temp << endl;
        }
    }
    while(!fin.eof())
    {
        getline(fin, temp);
        if(temp == "") break;
        fout << temp << endl;
    }
    fin.close();
    fout.close();

    string dir = "data\\class\\" + clname + ".txt";
    const char* d = dir.c_str();

    remove(d);
    rename("temp.txt", d);
}

bool student::addCourse(const course& co)
{
    if(co.ID == 0) return false;
    if(conum == 5) return false;
    if(conum == 0)
    {
        if (co.cur >= co.ms) return false;
        colist = new list<course>(co);
        colist->next = nullptr;
        ++conum;
        return true;
    }
    list<course>* temp = colist;
    while(temp != nullptr)
    {
        if(co.s[0] == temp->data.s[0] || co.s[0] == temp->data.s[1] || 
           co.s[1] == temp->data.s[0] || co.s[1] == temp->data.s[1] || co.cur >= co.ms) return false;
        temp = temp->next;
    }
    temp = colist;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    ++conum;
    temp->next = new list<course>(co);
    temp = temp->next;
    temp->next = nullptr;
    return true;
}

bool student::removeCourse(int ID)
{
    list<course>* temp = colist;
    if(colist && colist->data.ID == ID) 
    {
        colist = colist->next;
        delete temp;
        return true;
    }
    while(temp->next)
    {
        if(temp->next->data.ID == ID)
        {
            list<course>* t = temp->next;
            temp->next = t->next;
            delete t;
            return true;
        }
    }
    return false;
}

void student::viewCourse()
{
    list<course>* temp = colist;
    
    while (temp != nullptr && temp->data.ID != 0)
    {
        cout << "ID: " << temp->data.ID << endl;
        cout << "Name: " << temp->data.name << endl;
        cout << "Session: "  << day[temp->data.s[0] / 7] << ' ' << t[temp->data.s[0] % 7] << " " << day[temp->data.s[1] / 7] << ' ' << t[temp->data.s[1] % 7] << endl << endl;
        temp = temp->next;
    }
    system("pause");
}

bool login(student& s, int ID, string pass)
{
    ifstream fin("data\\student.txt", ios_base::in);
    while (!fin.eof())
    {
        fin >> s.ID; fin.ignore();
        if (s.ID == ID)
        {
            getline(fin, s.pass, ',');
            if (s.pass == pass)
            {
                string clname;
                //fin.ignore(1000, '\n');
                getline(fin, clname);
                fin.close();
                fin.open("data\\class\\" + clname + ".txt");
                while(!fin.eof())
                {
                    fin >> ID; fin.ignore();
                    if(ID == s.ID) break;
                    else fin.ignore(1000, '\n');
                }
                getline(fin, s.fname, ',');
                getline(fin, s.lname, ',');
                fin >> s.gender; fin.ignore();
                fin >> s.dob[0]; fin.ignore();
                fin >> s.dob[1]; fin.ignore();
                fin >> s.dob[2]; fin.ignore();
                getline(fin, s.SID, ',');
                s.clname = clname;
                fin >> s.No;
                s.colist = new list<course>;
                list<course>* temp = s.colist;
                while(!fin.eof() && fin.get() == ',')
                {
                    ++s.conum;
                    int ID;
                    fin >> ID;
                    temp->next = new list<course>;
                    temp->data = course(ID);
                    if(temp->data.ID == 0 || !temp->data.checkStudent(s.ID)) 
                    {
                        delete temp->next;
                        temp->next = nullptr;
                    }
                    else temp = temp->next;
                }
                fin.close();
                return true;
            }
            fin.close();
            return false;
        }
        else fin.ignore(1000, '\n');
    }
    fin.close();
    return false;
}

void changeStudent(student& s)
{
    ifstream fin("data\\student.txt");
    ofstream fout("temp.txt");
    string temp;
    int id;
    while (!fin.eof())
    {
        fin >> id;
        if(id == s.ID)
        {
            fout << s.ID << s.pass << s.clname << endl;
            break;
        }
        getline(fin, temp);
        fout << id << temp << endl;
    }
    while (getline(fin, temp)) fout << temp << endl;
    fin.close(); fout.close();
    remove("data\\student.txt");
    rename("temp.txt", "data\\student.txt");
}


void viewScoreboard(student& st, string savest)
{
    ifstream fin(savest + "\\data.txt");
    if (!fin.is_open()) return;
    fin.ignore(100, '\n');
    fin.ignore(100, '\n');
    list<int>* courseid = new list <int>;
    list<int>* cur = courseid;
    while (!fin.eof())
    {
        fin >> cur->data;
        cur->next = new list<int>;
        cur = cur->next;
        fin.ignore(1000, '\n');
    }
    fin.close();
    cur->next = nullptr;
    list<int>* tmp = courseid;
    while (tmp->data != 0)
    {
        string id = to_string(tmp->data);
        ifstream fin1(savest + "\\" + id + "\\data.txt");
        int tmpID = 0;
        string coursename;
        fin1.ignore(1000, ',');
        getline(fin1, coursename, ',');
        fin1.ignore(1000, '\n');
        fin1 >> tmpID;
        while (tmpID != st.ID)
        {
            if (fin1.eof()) break;
            fin1.ignore(1000, '\n');
            fin1 >> tmpID;
        }
        if (tmpID == st.ID)
        {
            fin1.ignore();
            int* score = new int[4];
            fin1 >> score[0]; fin1.ignore();
            fin1 >> score[1]; fin1.ignore();
            fin1 >> score[2]; fin1.ignore();
            fin1 >> score[3]; fin1.ignore();
            cout << "Course name: " << coursename << endl;
            cout << "Midterm score: " << score[0] << endl;
            cout << "Final score: " << score[1] << endl;
            cout << "Other score:  " << score[2] << endl;
            cout << "Total score:  " << score[3] << endl;
            cout << '\n';
        }
        fin1.close();
        tmp = tmp->next;
        
    }
    

}