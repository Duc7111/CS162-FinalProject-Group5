#include<iostream>
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
			AS now;
			now.username = new char[200];
			now.pass = new char[20];
			now.fname = new char[20];
			now.lname = new char[20];
			cin.ignore(10, '\n');
			cin.getline(now.username, 200);
			while (checkAS(now.username) == false) {
				cout << "your username: " << now.username << endl << "Try again" << endl;
				cin.getline(now.username, 30);
			}//lỗi ở phần while: nếu nhập sai lần đầu, mấy lần sau dù có nhập đúng thì hàm check vẫn bị sai
			// nhập ở lần tiếp theo khi nhập sai, chuỗi sẽ đổi, nhưng hàm checkAS vẫn cho ra false.
			// nếu nhập đúng thì chương trình vẫn chạy.
			cin.getline(now.pass, 20);
			cin.getline(now.fname, 20);
			cin.getline(now.lname, 20);
			cin >> now.gender;
			cin >> now.dob[0] >> now.dob[1] >> now.dob[2];
			cin >> now.SID;
			save2File(now);
			delete[]now.username;
			delete[]now.pass;
			delete[]now.fname;
			delete[]now.lname;
			break;
		}
	}
	system("cls");
	return 0;
}