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
using namespace std;



int main() {
	//YearList* t = nullptr;
	dataBase();
	semester se;
	int choice;
	choice = StartScreen();
	while (choice != 3) {
		if (choice == 1) {
			short opt = loginp1();
			if (opt == 1) {
				student st;
				loginSt(st);
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
						while (optmain != 4) {
							if (optmain == 1) {
								int yearC = schoolyearScreen(log);
								getnamese(se, log);
								SemesterExecution(se, log);
								se.save2File("data\\schoolyear\\2021-2022");
								cout << "finish";
								system("pause");
								
								//cin.ignore(10, '\n');
								//CreateYearInfo(t, log);
							}
							else if (optmain == 2) {
							}
							else {
							}
							
							optmain = menuformainAS(log);
						}
						op1 = start(log);
					}
				}
				//destructer(log);
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