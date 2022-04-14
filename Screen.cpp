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

int StartScreen() {
	SetBGColor(15);
	system("cls");
	SetColor(1);
	gotoxy(7, 0);
	cout << "Welcome to Course Registration System";
	gotoxy(12, 1);
	cout << "Made by Group 5-APCS21";
	gotoxy(0, 2);
	cout << "__________________________________________________";
	gotoxy(0, 4);
	SetColor(0);
	cout << "Option:" << endl;
	cout << "1.Sign in" << endl;// login a exist account
	cout << "2.Sign up for academic staff" << endl;// create a new account for as
	cout << "3.Exit out of system" << endl;
	cout << "Your option: ";
	int choice;
	cin >> choice;
	while (choice <= 0 || choice >= 4) {
		choice = StartScreen();
	}
	return choice;
}

void SignupScreen() {
	SetColor(1);
	cout << "Welcome to sign up section." << endl;
	cout << "_______________________________" << endl << endl << endl;
	SetColor(0);
}

void SignupSystem() {
	system("cls");
	SignupScreen();
	string temp;
	cout << "Please submit your username (Your username must be a new one and only contain letter and number): ";
	cin.ignore(1000, '\n');
	getline(cin, temp);
	while (checkAS(temp) == true || checkspecial(temp) == false) {
		system("cls");
		SignupScreen();
		cout << "Your username: " << temp << " invalid or already existed." << endl << "Try again" << endl;
		cout << "Please submit your username (Your username must be a new one and only contain letter and number) : ";
		cin.ignore(1000, '\n');
		getline(cin, temp);
	}
	AS now;
	now.username = temp;
	cout << "Your username is accepted." << endl << "Now, submit your password: ";
	//cin.ignore(1000, '\n');
	getline(cin, temp);
	while (checkspecial(temp) == false) {
		cout << "Invalid password. Try again." << endl << "Now, submit your password: ";
		//cin.ignore(1000, '\n');
		getline(cin, temp);
	}
	now.pass = temp;
	string pass;
	cout << "Confirm your password again: ";
	//cin.ignore(1000, '\n');
	getline(cin, pass);
	if (pass != now.pass) {
		cout << "Your password is not correct." << endl;
		cout << "Confirm your password again: ";
		//cin.ignore(1000, '\n');
		getline(cin, pass);
	}
	system("cls");
	SignupScreen();
	cout << "Your account created successfully." << endl;
	cout << "Now please fill in your information:" << endl;
	cout << "Your first name: ";
	//cin.ignore(1000, '\n');
	getline(cin, temp);
	while (checkspecial(temp) == false) {
		cout << "Invalid name. Try again." << endl << "Your first name: ";
		//cin.ignore(1000, '\n');
		getline(cin, temp);
	}
	now.fname = temp;
	cout << "Your last name: ";
	//cin.ignore(1000, '\n');
	getline(cin, temp);
	while (checkspecial(temp) == false) {
		cout << "Invalid name. Try again." << endl << "Your last name: ";
		//cin.ignore(1000, '\n');
		getline(cin, temp);
	}
	now.lname = temp;
	while (true)
	{
		cout << "Your gender (0: Female, 1: Male): ";
		char b[slen];
		//cin.ignore(1000, '\n');
		cin.get(b, slen, '\n');
		if (b[1] != '\0') cout << "Invalid input" << endl;
		else if (b[0] == '0')
		{
			now.gender = 0;
			break;
		}
		else if (b[0] == '1')
		{
			now.gender = 1;
			break;
		}
		else cout << "Invaid input" << endl;
	}
	char date[10];
	cout << "Your birth: " << endl;
	cout << "Day: ";
	cin.ignore(10, '\n');
	cin.get(date, 10);
	now.dob[0] = convert(date);
	cout << "Month: ";
	cin.ignore(10, '\n');
	cin.get(date, 10);
	now.dob[1] = convert(date);
	cout << "Year: ";
	cin.ignore(10, '\n');
	cin.get(date, 10);
	now.dob[2] = convert(date);
	while (checkDob(now.dob) == false) {
		cout << "Invalid Date" << endl;
		cout << "Your birth: " << endl;
		cout << "Day: ";
		cin.ignore(10, '\n');
		cin.get(date, 10);
		now.dob[0] = convert(date);
		cout << "Month: ";
		cin.ignore(10, '\n');
		cin.get(date, 10);
		now.dob[1] = convert(date);
		cout << "Year: ";
		cin.ignore(10, '\n');
		cin.get(date, 10);
		now.dob[2] = convert(date);
	}
	cout << "Social Id: ";
	cin.ignore(1000, '\n');
	cin >> now.SID;
	while (checkstring(now.SID) == false) {
		cout << "Invalid data. Try again. " << endl;
		cout << "Social Id: ";
		cin >> now.SID;
	}
	while (true)
	{
		cout << "Confirm your account? (0: No, 1: Yes)" << endl;
		cout << "Your option: ";
		char b[slen];
		cin.ignore(1000, '\n');
		cin.get(b, slen, '\n');
		if (b[1] != '\0') cout << "Invalid input" << endl;
		else if (b[0] == '1')
		{
			save2File(now);
			cout << "Your account successfully sign up in this System." << endl;
			system("pause");
			break;
		}
		else if (b[0] == '0')
		{
			break;
		}
		else cout << "Invaid input" << endl;
	}
}

short loginp1() {
	system("cls");
	SetColor(1);
	cout << "Welcome to sign up section." << endl;
	cout << "_______________________________" << endl << endl << endl;
	SetColor(0);
	cout << "You are:" << endl << "1. Student" << endl << "2. Academic staff" << endl << "3. Return to main menu" << endl;
	gotoxy(9, 4);
	short option;
	cin >> option;
	gotoxy(0, 10);
	while (option <= 0 || option > 3) {
		cout << "Invalid option. Try again." << endl;
		cout << "Option: ";
		cin >> option;
	}
	return option;
}


bool checkspecial(string str) {
	int i = 0;
	while (str[i] != '\0') {
		if (((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))) {
			i++;
		}
		else
			return false;
	}
	return true;
}

bool checkstring(string str) {
	int i = 0;
	while (str[i] != '\0') {
		if (((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))) {
			i++;
		}
		else
			return false;
	}
	return true;
}

int convert(string str) {
	int t = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 48 && str[i] <= 57) {
			t = t * 10 + (str[i] - 48);
		}
		else
			return -1;
	}
	return t;
}

void loginas(AS& log) {
	string userlog;
	string passlog;
	cout << "Your username: ";
	cin.ignore(100, '\n');
	getline(cin,userlog);
	cout << "Your password: ";
	getline(cin, passlog);
	while (loginforAS(log, userlog, passlog) == false) {
		cout << "Wrong or invalid username or password. Try again\n";
		cout << "Your username: ";
		getline(cin, userlog);
		cout << "Your password: ";
		getline(cin, passlog);
	}
}

int start(AS log) {
	system("cls");
	gotoxy(7, 0);
	cout << "Welcome to Course Registration System";
	gotoxy(12, 1);
	cout << "Made by Group 5-APCS21";
	gotoxy(0, 2);
	cout << "__________________________________________________";
	gotoxy(60, 0);
	cout << "Welcome " << log.lname;
	gotoxy(0, 5);
	SetColor(0);
	cout << "Option:" << endl;
	cout << "1.View your profile." << endl;
	cout << "2.Change password." << endl;
	cout << "3.Go to main section." << endl;
	cout << "4.Log out of system." << endl;
	cout << "Your option: ";
	//cin.ignore(100, '\n');
	char opin[slen];
	cin.get(opin, slen);
	int in = convert(opin);
	while (in < 0 || in >= 5) {
		cout << "Invalid option. Try again." << endl;
		cout << "Your option: ";
		cin.ignore(100, '\n');
		cin.get(opin, slen);
		in = convert(opin);
	}
	return in;
}

void viewprofile(AS log) {
	system("cls");
	gotoxy(7, 0);
	cout << "Welcome to Course Registration System";
	gotoxy(12, 1);
	cout << "Made by Group 5-APCS21";
	gotoxy(0, 2);
	cout << "__________________________________________________";
	gotoxy(60, 0);
	cout << "Welcome " << log.lname;
	gotoxy(0, 5);
	cout << "Your name: " << log.fname << " " << log.lname << "       ";
	cout << "DOB: " << log.dob[0] << "/" << log.dob[1] << "/" << log.dob[2] << endl;
	if (log.gender == true)
		cout << "Gender: Male" << endl;
	else
		cout << "Gender: Female" << endl;
	cout << "Social ID: " << log.SID << endl;
	system("pause");
}

void changepass(AS& log) {
	system("cls");
	gotoxy(7, 0);
	cout << "Welcome to Course Registration System";
	gotoxy(12, 1);
	cout << "Made by Group 5-APCS21";
	gotoxy(0, 2);
	cout << "__________________________________________________";
	gotoxy(60, 0);
	cout << "Welcome " << log.lname;
	gotoxy(0, 5);
	cout << "Your password: ";
	string temp2;
	//cin.ignore(1000, '\n');
	getline(cin, temp2);
	while (temp2!=log.pass) {
		cout << "Wrong password. Try again." << endl << "Now, submit your password: ";
		//cin.ignore(1000, '\n');
		getline(cin, temp2);
	}
	cout << "Your new password: ";
	string temp;
	//cin.ignore(1000, '\n');
	getline(cin, temp);
	while (checkstring(temp) == false) {
		cout << "Invalid password. Try again." << endl << "Now, submit your password: ";
		getline(cin, temp);
	}
	cout << "Confirm your password: ";
	string check;
	getline(cin, check);
	while (check!=temp) {
		cout << "Wrong password. Try again." << endl << "Confirm your password: ";
		getline(cin, check);
	}
	log.pass = temp;
	cout << "Your password changed successfully.\n";
	changeAS(log);
	system("pause");
}

int menuformainAS(AS log) {
	SetColor(1);
	system("cls");
	gotoxy(7, 0);
	cout << "Welcome to Course Registration System";
	gotoxy(12, 1);
	cout << "Made by Group 5-APCS21";
	gotoxy(0, 2);
	cout << "__________________________________________________";
	gotoxy(60, 0);
	cout << "Welcome " << log.lname;
	gotoxy(0, 5);
	cout << "What section of this school year? (Note: You should finish the last section before go to the next one)" << endl;
	SetColor(0);
	cout << "1. Create a new school year." << endl;
	cout << "2. Continue on an existed school year." << endl;
	cout << "3. Create a new class." << endl;
	cout << "4. Continue on an existed class." << endl;
	cout << "5. Go to menu." << endl;
	string opin;
	//cin.ignore(slen, '\n');
	getline(cin, opin);
	int in = convert(opin);
	while (in < 0 || in >= 6) {
		cout << "Invalid option. Try again." << endl;
		cout << "Your option: ";
		getline(cin, opin);
		in = convert(opin);
	}
	return in;
}

void Inscreen(AS log) {
	SetColor(1);
	system("cls");
	gotoxy(7, 0);
	cout << "Welcome to Course Registration System";
	gotoxy(12, 1);
	cout << "Made by Group 5-APCS21";
	gotoxy(0, 2);
	cout << "__________________________________________________";
	gotoxy(60, 0);
	cout << "Welcome " << log.lname;
	gotoxy(0, 5);
	SetColor(0);
}

int schoolyearScreen(AS log) {
	Inscreen(log);
	cout << "Your activity: " << endl;
	cout << "1. Create a new school year. " << endl;
	cout << "2. New school year is already availabled" << endl;
	cout << "3. Go back to main menu" << endl;
	cout << "Your choice: ";
	string choice1;
	getline(cin, choice1);
	int yearC = convert(choice1);
	while (yearC != 1 && yearC != 2 && yearC != 3) {
		cout << "Invalid input. Try again.";
		getline(cin, choice1);
		yearC = convert(choice1);
	}
	return yearC;
}

void loginSt(student& s) {
	string userlog;
	string passlog;
	cout << "Your username: ";
	cin.ignore(10, '\n');
	getline(cin, userlog);
	int ID = convert(userlog);
	cout << "Your password (default password: Your Social ID): ";
	getline(cin, passlog);
	while (login(s, ID, passlog) == false) {
		cout << "Wrong or invalid username or password. Try again\n";
		cout << "Your username: ";
		getline(cin, userlog);
		ID = convert(userlog);
		cout << "Your password: ";
		getline(cin, passlog);
	}
}

void semesterscreen(AS log, schoolyear& year) {
	//getschoolyear(year, log);
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

void Inscreenst(student st) {
	SetColor(1);
	system("cls");
	gotoxy(7, 0);
	cout << "Welcome to Course Registration System";
	gotoxy(12, 1);
	cout << "Made by Group 5-APCS21";
	gotoxy(0, 2);
	cout << "__________________________________________________";
	gotoxy(60, 0);
	cout << "Welcome " << st.lname;
	gotoxy(0, 5);
	SetColor(0);

}

int studentscreen1(student& st) {
	Inscreenst(st);
	cout << "Option:" << endl;
	cout << "1.View your profile." << endl;
	cout << "2.Change password." << endl;
	cout << "3.View Student in your class." << endl;
	cout << "4.Go to main section." << endl;
	cout << "5.Log out of system." << endl;
	cout << "Your option: ";
	//cin.ignore(100, '\n');
	string opin;
	getline(cin, opin);
	int in = convert(opin);
	while (in < 0 || in >= 6) {
		cout << "Invalid option. Try again." << endl;
		cout << "Your option: ";
		getline(cin, opin);
		in = convert(opin);
	}
	return in;
}

void viewstudent(student log) {
	Inscreenst(log);
	cout << "Your name: " << log.fname << " " << log.lname << "       ";
	cout << "DOB: " << log.dob[0] << "/" << log.dob[1] << "/" << log.dob[2] << endl;
	if (log.gender == true)
		cout << "Gender: Male" << endl;
	else
		cout << "Gender: Female" << endl;
	cout << "Social ID: " << log.SID << endl;
	system("pause");
}

void changepassst(student& st) {
	Inscreenst(st);
	cout << "Your password: ";
	string temp2;
	//cin.ignore(1000, '\n');
	getline(cin, temp2);
	while (temp2 != st.pass) {
		cout << "Wrong password. Try again." << endl << "Now, submit your password: ";
		//cin.ignore(1000, '\n');
		getline(cin, temp2);
	}
	cout << "Your new password: ";
	string temp;
	//cin.ignore(1000, '\n');
	getline(cin, temp);
	while (checkstring(temp) == false) {
		cout << "Invalid password. Try again." << endl << "Now, submit your password: ";
		//cin.ignore(1000, '\n');
		getline(cin, temp);
	}
	cout << "Confirm your password: ";
	string check;
	getline(cin, check);
	while (check != temp) {
		cout << "Wrong password. Try again." << endl << "Confirm your password: ";
		getline(cin, check);
	}
	st.pass = temp;
	cout << "Your password changed successfully.\n";
	changeStudent(st);
	system("pause");
}

int SeScreen(AS log) {
	Inscreen(log);
	cout << "1. Create a new semester.\n";
	cout << "2. Continue on an existed semester.\n";
	cout << "3. Go back to last section.\n";
	cout << "Option: ";
	string opin;
	getline(cin, opin);
	int in = convert(opin);
	while (in < 0 || in >= 4) {
		cout << "Invalid option. Try again." << endl;
		cout << "Your option: ";
		getline(cin, opin);
		in = convert(opin);
	}
	return in;
}

int SeScreen2(semester& se, AS log) {
	Inscreen(log);
	cout << "Semester: " << se.name << endl;
	cout << "1. Add course to this semester." << endl;
	cout << "2. Update information for a course." << endl;
	cout << "3. View all course on this semester." << endl;
	cout << "4. Go back to last section.\n";
	cout << "Option: ";
	string opin;
	getline(cin, opin);
	int in = convert(opin);
	while (in < 0 || in >= 5) {
		cout << "Invalid option. Try again." << endl;
		cout << "Your option: ";
		getline(cin, opin);
		in = convert(opin);
	}
	return in;
}

int getnamesest(student st) {
	Inscreenst(st);
	cout << "Please enter which semester you want to execute:" << endl;
	cout << "1. Fall           2. Summer           3. Autumn" << endl;
	cout << "Your choice: ";
	string choice;
	//cin.ignore(10, '\n');
	getline(cin, choice);
	while (choice != "1" && choice != "2" && choice != "3") {
		cout << "Invalid value. Try again." << endl << "Your choice: ";
		getline(cin, choice);
	}
	int cse = convert(choice);
	return cse;
}

int SeScreen2st(semester& se, student st) {
	Inscreenst(st);
	cout << "Semester: " << se.name << endl;
	cout << "1. Register course in this semester." << endl;	
	cout << "2. View all course on this semester." << endl;
	cout << "3. Go to a course you register." << endl;
	cout << "4. Go back to last section.\n";
	cout << "Option: ";
	string opin;
	getline(cin, opin);
	int in = convert(opin);
	while (in < 0 || in >= 5) {
		cout << "Invalid option. Try again." << endl;
		cout << "Your option: ";
		getline(cin, opin);
		in = convert(opin);
	}
	return in;
}