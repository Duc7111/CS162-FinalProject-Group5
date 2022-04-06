#include<iostream>
#include<cstring>

#include "const.h"
#include "console.h"
#include "Screen.h"
#include "AS.h"
#include "student.h"
#include "SchoolYear.h"
#include "course.h"
#include "semester.h"
#include "Class.h"
#include "data.h"
#include "addstudent.h"
using namespace std;



int main() {
	//YearList* t = nullptr;
	Class cl;
	cl.stlist = new list<student>;
	dataBase();
	schoolyear year;
	schoolyear cur;
	semester se;
	int choice;
	choice = StartScreen();
	while (choice != 3) {
		if (choice == 1) {
			short opt = loginp1();
			if (opt == 1) {
				student st;
				loginSt(st);
				int opst = studentscreen1(st);
				while (opst != 4) {
					if (opst == 1) {
						viewstudent(st);
						opst = studentscreen1(st);
					}
					else if (opst == 2) {

					}
					else {

					}
				}
				break;
			}
			else if (opt == 2) {
				AS log;
				loginas(log);
				int op1 = start(log);
				while (op1 != 4) {
					if (op1 == 1) {
						viewprofile(log);
						cin.ignore(100, '\n');
						op1 = start(log);
					}
					else if (op1 == 2) {
						changepass(log);
						op1 = start(log);
					}
					else {
						cin.ignore(10, '\n');
						int optmain = menuformainAS(log);
						while (optmain != 5) {
							if (optmain == 1) {
								system("cls");
								CreateGeneralInfo(year, log);
							}
							else if (optmain==2){
								semesterscreen(log, year);
							}
							else if (optmain == 3 ) {
								CreateNC(cl,log);
							}
							optmain = menuformainAS(log);
						}
						op1 = start(log);
					}
				}
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