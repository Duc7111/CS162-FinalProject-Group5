#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "AS.h"
#include "const.h"

using namespace std;

bool checkDob(int dob[3]) //Check if dob is a valid date
{
    if (dob[0] <= 0 || dob[1] <= 0 || dob[1] > 12 || dob[2] <= 0) return false;
    if (dob[1] == 2)
    {
        int d = 29;
        if (dob[2] % 4) d = 28;
        else if (!(dob[2] % 100) && dob[2] % 400) d = 28;
        if (dob[0] > d) return false;
        return true;
    }
    if (dob[0] > ml[dob[1] - 1]) return false;
    return true;
}

bool checkAS(string username) // true: existed, nullptr; false: not exist
{
    if (username[0] == '\0') return true;
    ifstream fin("data\\AS.txt", ios_base::in);
    string temp;
    while (getline(fin, temp, ','))
    {
        if (temp == username)
        {
            fin.close();
            return true;
        }
        fin.ignore(1000, '\n');
    }
    fin.close();
    return false;
}

void save2File(const AS& as) //add an AS to file
{
    ofstream fout("data\\AS.txt", ios_base::out | ios_base::app);
    fout << as.username << ',' << as.pass << ',' << as.fname << ',' << as.lname << ',' << as.gender << ',' << as.dob[0] << ',' << as.dob[1] << ',' << as.dob[2] << ',' << as.SID << endl;
    fout.close();
}

bool login(AS& as, string username, string pass) // true: login success, false : fail;
{
    ifstream fin("data\\AS.txt", ios_base::in);
    while (getline(fin, as.username, ','))
    {
        if (username == as.username)
        {
            getline(fin, as.pass, ',');
            if (pass == as.pass)
            {
                getline(fin, as.fname, ',');
                getline(fin, as.lname, ',');
                fin >> as.gender; fin.ignore();
                fin >> as.dob[0]; fin.ignore();
                fin >> as.dob[1]; fin.ignore();
                fin >> as.dob[2]; fin.ignore();
                getline(fin, as.SID);
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

void changeAS(AS& as) // change info of an AS in file
{
    ifstream fin("data\\AS.txt");
    ofstream fout("temp.txt");
    string temp;
    while (getline(fin, temp))
    {
        int i = 0;
        while (as.username[i] != '\0' && as.username[i] == temp[i]) ++i;
        if (as.username[i] == '\0' && temp[i] == ',')
        {
            fout << as.username << ',' << as.pass << ',' << as.fname << ',' << as.lname << ',' << as.gender << ',' << as.dob[0] << ',' << as.dob[1] << ',' << as.dob[2] << ',' << as.SID << endl;
            break;
        }
        else fout << temp << endl;
    }
    while (getline(fin, temp)) fout << temp << endl;
    fin.close(), fout.close();
    remove("data\\AS.txt");
    rename("temp.txt", "data\\AS.txt");
}