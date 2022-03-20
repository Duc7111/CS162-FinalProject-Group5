#include<fstream>

#include "semester.h"

using namespace std;



void save2File(const semester& s, const string& dir)
{
    ofstream fout(dir + ".txt");
    fout << s.sdate << ',' << s.edate << endl;
    list<course>* temp = s.colist;
    while(temp)
    {
        fout << temp->data.ID << endl;
        temp = temp->next;
    }
}