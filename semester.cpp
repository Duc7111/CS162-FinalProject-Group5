#include<fstream>
#include<direct.h>

#include "semester.h"

using namespace std;

semester::semester():sn(0), colist(nullptr){}

semester::semester(const string& dir)
{
    sn = dir[dir.length() - 1] - '0';
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
    string name = "semester" + ('0' + sn);
    ofstream fout(dir + "\\semester.txt", ios_base::app);
    fout << name << endl;
    fout.close();
    dir += "\\" + name;
    const char* d = dir.c_str();
    _mkdir(d);
    fout.open(dir + "\\data.txt");
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