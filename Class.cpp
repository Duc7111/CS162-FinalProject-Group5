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

void CreateNC()
{
    Class new_class;
    cout << "Enter the name of the new class: ";
    cin.ignore(1000, '\n');
    getline(cin, new_class.name);
    //course insertion should be right here
    cout << "New class has been created successfully";
}
