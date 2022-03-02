#include <iostream>
#include <fstream>
#include <cstring>

#include "AS.h"
#include "const.h"

using namespace std;

void destructer(AS &as)
{
	delete[] as.pass;
	delete[] as.fname;
	delete[] as.lname;
}

bool checkDob(int dob[3])
{
    if(dob[0] <= 0 || dob[1] <= 0 || dob[1] > 12 || dob[2] <= 0) return false;
    if(dob[1] == 2)
    {
        int d = 29;
        if(dob[2] % 4) d = 28;
        else if(!(dob[2] % 100) && dob[2] % 400) d = 28;
        if(dob[0] > d) return false;
        return true;
    }
    if(dob[0] > ml[dob[1] - 1]) return false;
    return true;
}

bool checkAS(char* username) // true: existed, nullptr; false: not exist
{
    if(username[0] == '\0') return true;
    ifstream fin("AS.txt", ios_base::in);
    char temp[slen];
    while(fin.getline(temp, slen, ','))
    {
        if(!strcmp(username, temp))
        {
            fin.close();
            return true;
        }
        fin.ignore(1000, '\n');
    }
    fin.close();
    return false;
}

void save2File(const AS &as)
{
    ofstream fout("AS.txt", ios_base::out| ios_base::app);
    fout << as.username << ',' << as.pass << ',' << as.fname << ',' << as.lname << ',' << as.gender << ',' << as.dob[0] << ',' << as.dob[1] << ',' << as.dob[2] << ',' << as.SID << endl;
    fout.close();
}

bool login(AS &as, char* username, char* pass) // true: login success, false : fail;
{
    ifstream fin("AS.txt", ios_base::in);
    as.username = new char[slen];
    while(fin.getline(as.username, slen, ','))
    {
        if(!strcmp(as.username, username))
        {
            as.pass = new char[slen];
            fin.getline(as.pass, slen, ',');
            if(!strcmp(as.pass, pass))
            {
                as.fname = new char[slen];
                fin.getline(as.fname, slen, ',');

                as.lname = new char[slen];
                fin.getline(as.lname, slen, ',');

                fin >> as.gender; fin.ignore();
                fin >> as.dob[0]; fin.ignore();
                fin >> as.dob[1]; fin.ignore();
                fin >> as.dob[2]; fin.ignore();
                fin >> as.SID;
                fin.close();
                return true;
            }
            fin.close();
            destructer(as);
            return false;
        }
    }
    fin.close();
    destructer(as);
    return false;
}