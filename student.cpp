#include <fstream>
#include <string>
#include "student.h"
#include "const.h"

using namespace std;

bool login(student& s, int ID, string pass)
{
    ifstream fin("student.txt", ios_base::in);
    char temp;
    while (fin.get(temp))
    {
        if (temp != ' ')
        {
            fin.ignore(1000, '\n');
            continue;
        }
        fin >> s.ID; fin.ignore();
        if (s.ID == ID)
        {
            s.pass = new char[slen];
            getline(fin, s.pass, ',');
            if (s.pass == pass)
            {
                getline(fin, s.fname, ',');
                getline(fin, s.lname, ',');
                fin >> s.gender; fin.ignore();
                fin >> s.dob[0]; fin.ignore();
                fin >> s.dob[1]; fin.ignore();
                fin >> s.dob[2]; fin.ignore();
                getline(fin, s.SID);

                fin >> s.No;
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
    ifstream fin("student.txt");
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
            fout << s.ID << ',' << s.pass << ',' << s.fname << ',' << s.lname << ',' << s.gender << ',' << s.dob[0] << ',' << s.dob[1] << ',' << s.dob[2] << ',' << s.SID << ',' << s.No << endl;
            break;
        }
    }
    while (fin.getline(temp, 5 * slen)) fout << temp << endl;
    fin.close(); fout.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
}