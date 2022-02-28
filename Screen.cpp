#include <iostream>
#include "Console.h"

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
	cout << "2.Sign up" << endl;// create a new account
	cout << "3.Exit out of system" << endl;
	cout << "Your option: ";
	int choice;
	cin >> choice;
	if (choice <= 0 || choice >= 4)
		return 0;
	else
		return choice;
}