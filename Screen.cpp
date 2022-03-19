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
		cout << "Your username: ";
		cin.ignore(100, '\n');
		cin.get(userlog, slen);
		cout << "Your password: ";
		cin.ignore(100, '\n');
		cin.get(passlog, slen);
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
	cin.ignore(100, '\n');
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
	cin.ignore(1000, '\n');
	cin >> temp2;
	while (temp2!=log.pass) {
		cout << "Wrong password. Try again." << endl << "Now, submit your password: ";
		cin.ignore(1000, '\n');
		cin >> temp2;
	}
	cout << "Your new password: ";
	string temp;
	cin.ignore(1000, '\n');
	cin >> temp;
	while (checkstring(temp) == false) {
		cout << "Invalid password. Try again." << endl << "Now, submit your password: ";
		cin.ignore(1000, '\n');
		cin >> temp;
	}
	cout << "Confirm your password: ";
	string check;
	cin.ignore(1000, '\n');
	cin >> check;
	while (check!=temp) {
		cout << "Wrong password. Try again." << endl << "Confirm your password: ";
		cin.ignore(1000, '\n');
		cin >> temp;
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
	cout << "1. Start of a school year." << endl;
	cout << "2. Start of a semester." << endl;
	cout << "3. End of a semester." << endl;
	cout << "4. Go to menu." << endl;
	char opin[slen];
	cin.ignore(slen, '\n');
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
	cout << "Your choice: ";
	char choice1[slen];
	cin.ignore(1000, '\n');
	cin.get (choice1,slen);
	int yearC = convert(choice1);
	while (yearC != 1 && yearC != 2) {
		cout << "Invalid input. Try again.";
		cin.ignore(slen, '\n');
		cin.get(choice1, slen);
		yearC = convert(choice1);
	}
	return yearC;
}