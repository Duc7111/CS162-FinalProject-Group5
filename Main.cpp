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
						while (optmain != 3) {
							if (optmain == 1) {
								system("cls");
								CreateGeneralInfo(year, log);
							}
							else if (optmain==2){
								getschoolyear(year, log);
								string save = "data\\schoolyear\\" + year.name;
								int sedo = getnamese(log);
								if (sedo == 1) {
									year.Fall.name = "Fall";
									SemesterExecution(year.Fall, log);
									year.Fall.save2File(save);
								}
								else if (sedo == 2) {
									year.Summer.name = "Summer";
									SemesterExecution(year.Summer, log);
									year.Summer.save2File(save);
								}
								else {
								year.Autumn.name = "Autumn";
								SemesterExecution(year.Autumn, log);
								year.Autumn.save2File(save);
								}
							}
							else {
								int a = 1;
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