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
	semester* se;
	Class cl;
	cl.stlist = new list<student>;
	dataBase();
	schoolyear year;
	schoolyear cur;
	int choice;
	choice = StartScreen();
	while (choice != 3) {
		if (choice == 1) {
			short opt = loginp1();
			if (opt == 1) {
				student st;
				loginSt(st);
				int opst = studentscreen1(st);
				while (opst != 5) {
					if (opst == 1) {
						viewstudent(st);
					}
					else if (opst == 2) {
						changepassst(st);
					}
					else if (opst == 3) {
						 }
					else {
						/*getschoolyearst(year,st);
						int seme = getnamesest(st);
						if (seme == 1) {
							se = &year.Fall;
							se->name = "Fall";
						}
						else if (seme == 2) {
							se = &year.Summer;
							se->name = "Summer";
						}
						else {
							se = &year.Autumn;
							se->name = "Autumn";
						}*/
						ifstream in;
						in.open("data\\data.txt");
						string savest;
						getline(in, savest);
						in.close();
						semester se1(savest);
						
						se1.colist = new list<course>;
						int co1 = SeScreen2st(se1, st);
						while (co1 != 4) {
							if (co1 == 1) {
								ViewCoursese(se1);
								int id;
								//FindCourse(se1,id)
								while (FindCoursest(se1, id) == false) {
									cout << "That course do not available!!!" << " Try again." << endl;
								}
								string str = to_string(id);
								ifstream fin(savest + "\\" + str + "\\data.txt", ios_base::in);
								course tmp(id);

								
								
								if (st.addCourse(tmp) == true) {
									cout << "Register this course successfully!!\n";
									st.change();
									tmp.cur++;
									list<int[5]>* cur = new list<int[5]>;
									cur->data[0] = st.ID;
									cur->next = tmp.stlist;
									tmp.stlist = cur;
									tmp.save2File(savest);
									system("pause");
								}
								else {
									cout << "Register this course fail!!\n";
									system("pause");
								}
				
							}
							else if (co1 == 2) {
								ViewCourse(year, se1);
							}
							else {

							}
							dellist(se1.colist);
							co1 = SeScreen2st(se1,st);
						}
					}
					opst = studentscreen1(st);
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
								getschoolyear(year, log);
								int sechoice=SeScreen(log);
								while (sechoice != 3) {
									if (sechoice == 1) {
										semesterscreen(log, year);
									}
									else if (sechoice==2) {
										int seme=getnamese(log);
										if (seme == 1) {
											se = &year.Fall;
											se->name = "Fall";
										}
										else if(seme==2) {
											se = &year.Summer;
											se->name = "Summer";
										}
										else {
											se = &year.Autumn;
											se->name = "Autumn";
										}
										se->colist = new list<course>;
										string save = "data\\schoolyear\\" + year.name;
										int co1=SeScreen2(*se, log);
										while (co1 != 4) {
											if (co1 == 1) {
												AddCourse2Semester(*se,log);
											}
											else if (co1 ==2) {
												UpdateCourse(year, *se);
											}
											else {
												Inscreen(log);
												ViewCourse(year,*se);
											}
											se->save2File(save);
											co1 = SeScreen2(*se, log);
										}
										list<course>* del = se->colist;
										dellist(del);
									}
									sechoice = SeScreen(log);
								}
							}
							else if (optmain == 3 ) {
								CreateNC(cl,log);
							}
							else {
								GotoClass(cl, log);
							}
							cin.ignore(10, '\n');
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
	dellist(cl.stlist);
	
	system("cls");
	return 0;
}