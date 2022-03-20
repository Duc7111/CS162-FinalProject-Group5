#include <fstream>
#include <string>
#include "student.h"
#include "const.h"

using namespace std;

void student::save2File()
{
    ofstream fout("data\\student.txt", ios_base::app);
    fout << ID << ',' << pass << endl;
    fout.close();
    fout.open("data\\class\\" + clname + "\\student.txt", ios_base::app);
    fout << fname << ',' << lname << ',' << gender << ',' << dob[0] << ',' << dob[1] << ',' << dob[2] << ',' << SID << ',' << No;
    list<course>* temp = colist;
    while(temp)
    {
        fout << ',' << temp->data.ID;
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
                fin.close();
                string dir;
                fin.ignore(1000, '\n');
                getline(fin, dir);
                dir = "data\\class\\" + dir + "\\student.txt";
                fin.open(dir);
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
                getline(fin, s.SID);

                fin >> s.No;
                //course list missing
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
    char temp[5 * slen];
    while (fin.getline(temp, 5 * slen))
    {
        if (temp[0] == '-')
        {
            fout << temp << endl;
            continue;
        }
        int i = 0;
        int ID = 0;
        while (temp[++i] != ',') ID = ID * 10 + temp[i] - '0';
        if (ID != s.ID) fout << temp << endl;
        else
        {
            fout << s.ID << ',' << s.pass << ',' << s.clname << endl;
            break;
        }
    }
    while (fin.getline(temp, 5 * slen)) fout << temp << endl;
    fin.close(); fout.close();
    remove("data\\student.txt");
    rename("temp.txt", "data\\student.txt");
}