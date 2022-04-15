#include <fstream>
#include <string>
#include <iomanip>

#include "course.h"
#include "student.h"
#include "const.h"

using namespace std;

student::student() : colist(nullptr){}

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
                    while(!fin.eof() && fin.get() != '\n')
                    {
                        ++conum;
                        int ID;
                        fin >> ID;
                        temp->next = new list<course>;
                        temp->data = course(ID);
                        if(temp->data.ID == 0 || !temp->data.checkStudent(ID)) 
                        {
                            delete temp->next;
                            temp->next = nullptr;
                        }
                        else temp = temp->next;
                    }
                    return;
                }
            }
        }
        else fin.ignore(1000, '\n');
    }
}

bool student::createAcc()
{
    ifstream fin("data\\student.txt");
    int id;
    while(!fin.eof())
    {
        fin >> id;
        if(id == ID) return false;
        else fin.ignore(1000, '\n');
    }
    fin.close();
    ofstream fout("data\\student.txt", ios_base::app);
    fout << ID << ',' << pass << ',' << clname << endl;
}

void student::save2File()
{
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
            fout << temp;
        }
    }
    while(!fin.eof())
    {
        getline(fin, temp);
        fout << temp;
    }
    fin.close();
    fout.close();
    const char* d = ("data\\class\\" + clname + ".txt").c_str();
    remove(d);
    rename("temp", d);
}

bool student::addCourse(const course& co)
{
    if(conum == 5) return false;
    if(conum == 0)
    {
        colist = new list<course>(co);
        ++conum;
        return true;
    }
    list<course>* temp = colist;
    while(temp->next)
    {
        if(co.s[0] == temp->next->data.s[0] || co.s[0] == temp->next->data.s[1] || 
           co.s[1] == temp->next->data.s[0] || co.s[1] == temp->next->data.s[1] ) return false;
    }
    ++conum;
    temp->next = new list<course>(co);
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
    cout << setw(7) << "ID" << setw(20) << "Name" << setw(12) << "Session 1" << setw(12) << "Session 2" << endl;
    while(temp)
    {
        cout << setw(7) << temp->data.ID << setw(20) << temp->data.name << setw(6) << day[temp->data.s[0]/7] << ' ' << t[temp->data.s[0]%7] << setw(6) << day[temp->data.s[1]/7] << ' ' << t[temp->data.s[1]%7];
        temp = temp->next;
    }
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
                while(fin.get() == ',')
                {
                    temp->next = new list<course>;
                    temp = temp->next;
                    fin >> temp->data.ID;
                    
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