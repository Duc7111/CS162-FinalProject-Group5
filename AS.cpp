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
    if(dob[1] > 12) return false;
    if(dob[1] == 2)
    {
        //check leap year
    }    
    // Not finished
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

}

bool login(AS &as, char* username, char* pass)
{
    ifstream fin("AS.txt", ios_base::in);
    char temp[slen];
    while(fin.getline(temp, slen, ','))
    {
        if(temp == username)
        {
            as.username = temp;
            fin.getline(temp, slen, ',');
            if(temp == pass)
            {
                as.pass = temp;
                fin.getline(as.fname, slen, ',');
                fin.getline(as.lname, slen, ',');
                fin >> as.gender; fin.ignore();
                fin >> as.dob[0]; fin.ignore();
                fin >> as.dob[1]; fin.ignore();
                fin >> as.dob[2]; fin.ignore();
                fin >> as.SID;
                return true;
            }
            return false;
        }
    }
    return false;
}