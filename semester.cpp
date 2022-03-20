#include<fstream>
#include<direct.h>

#include "semester.h"

using namespace std;



void semester::save2File(const string& dir)
{
    char s = '0' + sn;
    const char* d = (dir + s).c_str();
    _mkdir(d);
    ofstream fout(dir + s + "\\data.txt");
    fout << sdate << ',' << edate << endl;
    list<course>* temp = colist;
    while(temp)
    {
        fout << temp->data.ID << endl;
        temp = temp->next;
    }
}