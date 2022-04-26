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
#include "save2csv.h"

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
				while (opst != 6) {
					if (opst == 1) {
						viewstudent(st);
					}
					else if (opst == 2) {
						changepassst(st);
					}
					else if (opst == 3) {
						Inscreenst(st);
						viewClasslist();
						}
					else if (opst == 4) {
						Inscreenst(st);
						viewClassStudent();
					}
					else {
						
						student st1(st.ID);
						st = st1;
						ifstream in;
						in.open("data\\data.txt");
						string savest;
						getline(in, savest);
						in.close();
						semester se1(savest);
						//se1.colist = new list<course>;
						int co1 = SeScreen2st(se1, st);
						while (co1 != 6) {
							if (co1 == 1) {
								ScreenSignCourse(st, se1, savest);
							}
							else if (co1 == 2) {
								ViewCoursese(se1);
							}
							else if (co1 == 3) {
								st.viewCourse();
							}
							else if (co1==4) {
								viewCourseStudent(se1, savest);
								system("pause");
							}
							else {
								viewScoreboard(st, savest);
								system("pause");
							}
							co1 = SeScreen2st(se1,st);
							st = student(st.ID);
							if(co1 == 5) dellist(se1.colist);
						}
					}
					opst = studentscreen1(st);
				}
				choice = StartScreen();
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
										string saveas1 = "data\\schoolyear\\" + year.name + "\\" + se->name;
										*se = semester(saveas1);
										int co1=SeScreen2(*se, log);
										while (co1 != 8) {
											if (co1 == 1) {
												AddCourse2Semester(*se,log);
												se->save2File(save);
											}
											else if (co1 ==2) {
												UpdateCourse(year, *se);
											}
											else if (co1==3) {
												Inscreen(log);
												semester view2(saveas1);
												ViewCourse(year,view2);
											}
											else if (co1 == 4) {//ViewClass
												Inscreen(log);
												viewClasslist();
											}
											else if (co1 == 5) {
												Inscreen(log);
												viewClassStudent();
											}
											else if (co1 == 6) {
												Inscreen(log);
												semester view(saveas1);
												viewCourseStudent(view, saveas1);
												system("pause");
											}
											else {
												int ScoreSc = ScoreScreen(log);
												while (ScoreSc != 4) {
													if (ScoreSc == 1) {
														ExportScreen(year, *se, log, save);
													}
													else if (ScoreSc == 2) {
														ImportScreen(year, *se, log, save);
													}
													else {
														ViewScoreScreen(year, *se, log, save);
													}
													ScoreSc = ScoreScreen(log);
												}
											}
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
				choice = StartScreen();
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