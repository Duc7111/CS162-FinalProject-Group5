#include<iostream>
#include<cstring>

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
			short opt = loginp1(); 
			if (opt == 1) {
				break;
			}
			else if (opt == 2) {
				AS log;
				char userlog[slen];
				char passlog[slen];
				cout << "Your username: ";
				cin.ignore(100, '\n');
				cin.get(userlog, slen);
				cout << "Your password: ";
				cin.ignore(100, '\n');
				cin.get(passlog, slen);
				while (login(log, userlog, passlog) == false) {
					cout << "Wrong or invalid username or password. Try again\n";
					cout << userlog << endl << passlog << endl;
					cout << "Your username: ";
					cin.ignore(100, '\n');
					cin.get(userlog, slen);
					cout << "Your password: ";
					cin.ignore(100, '\n');
					cin.get(passlog, slen);
				}
				destructer(log);
				break;
			}// sửa ngay đây
			else {
				choice = StartScreen();
			}
		}
		else {
			SignupSystem();
			choice = StartScreen();
		}
	}
	system("cls");
	return 0;
}