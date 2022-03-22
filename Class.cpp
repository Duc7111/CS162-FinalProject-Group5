#include <fstream>

#include "Class.h"

using namespace std;

void Class::save2File()
{
    ofstream fout("data\\class\\class.txt", ios_base::app);
    fout << name << endl;
    fout.close();
    fout.open("data\\class\\" + name + ".txt", ios_base::trunc);
    fout.close();
    list<student>* temp = stlist;
    while(temp)
    {
        temp->data.save2File();
        temp = temp->next;
    }
}