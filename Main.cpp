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
				loginas(log);
				int op1=start(log);
				while (op1 != 3) {
					if (op1 == 1) {
						viewprofile(log);
						op1 = start(log);
					}
					else {
						changepass(log);
						op1 = start(log);
					}
				}
				destructer(log);
				break;
			}
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