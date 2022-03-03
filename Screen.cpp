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
	cout << "Please submit your username (Your username must be a new one and only contain letter and number): ";
	cin.ignore(1000, '\n');
	cin.get(temp, slen, '\n');
	while (checkAS(temp)==true||checkspecial(temp)==false) {
		system("cls");
		SignupScreen();
		cout << "Your username: " << temp << " invalid or already existed." << endl << "Try again" << endl;
		cout << "Please submit your username (Your username must be a new one and only contain letter and number) : ";
		cin.ignore(1000, '\n');
		cin.get(temp, slen, '\n');
	}
	AS now;
	now.username = temp;
	cout << "Your username is accepted." << endl << "Now, submit your password: ";
	char* temp2 = new char[slen];
	cin.ignore(1000, '\n');
	cin.get(temp2, slen, '\n');
	while(checkspecial(temp2)==false){
		cout << "Invalid password. Try again." << endl << "Now, submit your password: ";
		cin.ignore(1000, '\n');
		cin.get(temp2, slen, '\n');
	}
	now.pass = temp2;
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
	char* temp3 = new char[slen];
	cin.ignore(1000, '\n');
	cin.get(temp3, slen, '\n');
	while (checkspecial(temp3) == false) {
		cout << "Invalid name. Try again." << endl << "Your first name: ";
		cin.ignore(1000, '\n');
		cin.get(temp3, slen, '\n');
	}
	now.fname = temp3;
	cout << "Your last name: ";
	char* temp4 = new char[slen];
	cin.ignore(1000, '\n');
	cin.get(temp4, slen, '\n');
	while (checkspecial(temp4) == false) {
		cout << "Invalid name. Try again." << endl << "Your last name: ";
		cin.ignore(1000, '\n');
		cin.get(temp4, slen, '\n');
	}
	now.lname = temp4;
	while (true)
	{
		cout << "Your gender (0: Female, 1: Male): ";
		char b[slen];
		cin.ignore(1000, '\n');
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
	now.SID = new char[slen];
	cin.ignore(1000, '\n');
	cin.get(now.SID, slen, '\n');
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
	destructer(now);

}

short loginp1() {
	system("cls");
	SetColor(1);
	cout << "Welcome to sign up section." << endl;
	cout << "_______________________________" << endl << endl << endl;
	SetColor(0);
	cout << "You are:" << endl << "1. Student" << endl << "2. Academic staff" << endl << "3. Return to main menu" << endl;
	short option;
	cin >> option;
	while (option <= 0 || option > 3) {
		cout << "Invalid option. Try again." << endl;
		cout << "Option: ";
		cin >> option;
	}
	return option;
}


bool checkspecial(char* str) {
	int i = 0;
	while(str[i]!='\0')  {
		if (((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))) {
			i++;
		}
		else
			return false;
	}
	return true;
}

int convert(char* str) {
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
		cout << userlog << endl << passlog << endl;
		cout << "Your username: ";
		cin.ignore(100, '\n');
		cin.get(userlog, slen);
		cout << "Your password: ";
		cin.ignore(100, '\n');
		cin.get(passlog, slen);
	}
	destructer(log);
}