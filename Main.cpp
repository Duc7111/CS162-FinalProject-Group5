#include<iostream>

#include "const.h"
#include "console.h"
#include "Screen.h"
#include "AS.h"
#include "student.h"

using namespace std;

int main() {
	int choice;
	choice = StartScreen();
	while (choice != 3) {
		if (choice == 1) {
			
			break;
		}
		else {
			char* temp = new char[slen];
			cin.ignore(1000, '\n');
			cin.get(temp, slen, '\n');
			while (checkAS(temp)) {
				cout << "your username: " << temp << endl << "Try again" << endl;
				cin.ignore(1000, '\n');
				cin.get(temp, slen, '\n');
			}
			AS now;
			now.username = temp;

			now.pass = new char[slen];
			cin.ignore(1000, '\n');
			cin.get(now.pass, slen, '\n');

			now.fname = new char[slen];
			cin.ignore(1000, '\n');
			cin.get(now.fname, slen, '\n');

			now.lname = new char[slen];
			cin.ignore(1000, '\n');
			cin.get(now.lname, slen, '\n');

			cin >> now.gender;
			cin >> now.dob[0] >> now.dob[1] >> now.dob[2];
			cin >> now.SID;
			save2File(now);
			destructer(now);
			break;
		}
	}
	system("cls");
	return 0;
}