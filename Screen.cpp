#include<iostream>
#include<cstring>

#include "const.h"
#include "console.h"
#include "Screen.h"
#include "AS.h"
#include "student.h"

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
	char* temp = new char[slen];
	cout << "Please submit your username (Your username must be a new one): ";
	cin.ignore(1000, '\n');
	cin.get(temp, slen, '\n');
	while (checkAS(temp)) {
		system("cls");
		SignupScreen();
		cout << "Your username: " << temp << " already existed." << endl << "Try again" << endl;
		cout << "Please submit your username (Your username must be a new one) : ";
		cin.ignore(1000, '\n');
		cin.get(temp, slen, '\n');
	}
	AS now;
	now.username = temp;
	cout << "Your username is accepted." << endl << "Now, submit your password: ";
	now.pass = new char[slen];
	cin.ignore(1000, '\n');
	cin.get(now.pass, slen, '\n');
	char pass[slen];
	cout << "Confirm your password again: ";
	cin.ignore(1000, '\n');
	cin.get(pass, slen, '\n');
	if (strcmp(now.pass, pass) != 0) {
		cout << "Your password is not correct." << endl;
		cout << "Confirm your password again: ";
		cin.ignore(1000, '\n');
		cin.get(pass, slen, '\n');
	}
	system("cls");
	SignupScreen();
	cout << "Your account created successfully." << endl;
	cout << "Now please fill in your information:" << endl;
	cout << "Your first name: ";
	now.fname = new char[slen];
	cin.ignore(1000, '\n');
	cin.get(now.fname, slen, '\n');
	cout << "Your last name: ";
	now.lname = new char[slen];
	cin.ignore(1000, '\n');
	cin.get(now.lname, slen, '\n');
	cout << "Your gender (0:Female, other: male): ";
	cin >> now.gender;
	cout << "Your birth: " << endl;
	cout << "Day: ";
	cin >> now.dob[0];
	cout << "Month: ";
	cin >> now.dob[1];
	cout << "Year: ";
	cin >> now.dob[2];
	while (checkDob(now.dob) == false) {
		cout << "Invalid Date" << endl;
		cout << "Your birth: " << endl;
		cout << "Day: ";
		cin >> now.dob[0];
		cout << "Month: ";
		cin >> now.dob[1];
		cout << "Year: ";
		cin >> now.dob[2];
	}
	cout << "Social Id: ";
	cin >> now.SID;
	bool option;
	cout << "Confirm your account? (0: No)" << endl;
	cout << "Your option: ";
	cin >> option;
	if (option == 1) {
		save2File(now);
		cout << "Your account successfully sign up in this System." << endl;
		system("pause");
	}
	delete[] now.pass;
	delete[] now.fname;
	delete[] now.lname;

}