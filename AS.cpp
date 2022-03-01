#include <fstream>
#include <string>

#include "AS.h"

using namespace std;

int checkDob(int dob[3])
{
    if(dob[1] > 12) return false;
    if(dob[1] == 2)
    {
        //check leap year
    }    
    // Not finished
}

int checkAS(char* username) // 0: emty input, 1: existed, 2: not existed
{
    if(username == "") return 0;
    ifstream fin("AS.txt", ios_base::in);
    char temp[200];
    while(fin.getline(temp, 200, ','))
    {
        if(temp == username)
        {
            fin.close();
            return 1;
        }
        fin.ignore(1000, '\n');
    }
    return 2;
    // BUG
}

void save2File(const AS &as)
{
    ofstream fout("AS.txt", ios_base::out| ios_base::app);
    fout << as.username << ',' << as.pass << ',' << as.fname << ',' << as.lname << ',' << as.gender << ',' << as.dob[0] << ',' << as.dob[1] << ',' << as.dob[2] << ',' << as.SID << endl;

}

bool login(AS &as, char* username, char* pass)
{
    ifstream fin("AS.txt", ios_base::in);
    char temp[200];
    while(fin.getline(temp, 200, ','))
    {
        if(temp == username)
        {
            as.username = temp;
            fin.getline(temp, 200, ',');
            if(temp == pass)
            {
                as.pass = temp;
                fin.getline(as.fname, 200, ',');
                fin.getline(as.lname, 200, ',');
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