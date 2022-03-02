#include<iostream>
#include<cstring>

#include "const.h"
#include "console.h"
#include "Screen.h"
#include "AS.h"
#include "student.h"

using namespace std;

int main() {
	int choice;
	choice = StartScreen();
	while (choice != 3) {
		if (choice == 1) {

			break;
		}
		else {
			SignupSystem();
			choice = StartScreen();
		}
	}
	system("cls");
	return 0;
}