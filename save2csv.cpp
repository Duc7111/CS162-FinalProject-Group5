#include <iostream>

#include "save2csv.h"

void ExportStudentName2CSV(string dir)
{
    //string dir = "data\\course\\";
    ifstream fin(dir + "student.txt");
    ofstream csv_out("Stlist_BackUp.csv");
    string s;
    while (getline(fin, s)) csv_out << s << "\n";
    csv_out.close();
    fin.close();
}

void ExportScoreBoard2CSV(string dir, course CurCourse)
{
    ofstream csv_out(dir + "CourseScoreBoard.csv");

    csv_out << "No" << "," << "ID" << "," << "Full Name" << ","
        << "Midterm" << "," << "Final" << "," << "Other" << "," << "Total";

    int n = 1;
    list<int[5]>* tmp = CurCourse.stlist;

    while (tmp)
    {
        csv_out << n << "," << tmp->data[0] << "," << "abcxyz"
            << "," << tmp->data[1] << "," << tmp->data[2] << "," << tmp->data[3] << "," << tmp->data[4] << endl;
        ++n;
        tmp = tmp->next;
    }

    csv_out.close();
}

void ImportScoreBoard(string dir, course CurCourse) {

    ifstream csv_in(dir + "CourseScoreBoard.csv");

    string content, parts;

    if (csv_in.is_open()) {

        getline(csv_in, content);

        while (getline(csv_in, content)) {

            int* tmp = new int[7]; //No - ID - name - mid - fin - ex - tol
            int i = 0;
            stringstream str(content);

            while (getline(str, parts, ',')) {
                tmp[i] = stoi(parts);
                i++;
            }

            list<int[5]>* new_stlist = new list<int[5]>;
            new_stlist->data[0] = tmp[1];
            new_stlist->data[1] = tmp[2];
            new_stlist->data[2] = tmp[4];
            new_stlist->data[3] = tmp[5];
            new_stlist->data[4] = tmp[6];
            new_stlist->next = NULL;

            list<int[5]>* tmp_stlist = CurCourse.stlist;
            while (tmp_stlist->next != NULL)
                tmp_stlist = tmp_stlist->next;
            tmp_stlist->next = new_stlist;
        }

        CurCourse.save2File();

    }

    csv_in.close();

}

void ViewCourseScoreBoard(string dir, course CurCourse) {

    ifstream csv_in(dir + "CourseScoreBoard.csv");

    string content, parts;

    if (csv_in.is_open()) {

        getline(csv_in, content);

        while (getline(csv_in, content)) {

            int i = 0;
            stringstream str(content);

            while (getline(str, parts, ',')) {
                if (i == 1) cout << "Student's ID: " << stoi(parts) << endl;
                if (i == 2) cout << "Student's name: " << parts << endl;
                if (i == 3) cout << "Midterm score: " << stoi(parts) << endl;
                if (i == 4) cout << "Final score: " << stoi(parts) << endl;
                if (i == 5) cout << "Other score: " << stoi(parts) << endl;
                if (i == 6) cout << "Total score: " << stoi(parts) << endl;
                i++;
            }

            cout << endl;
        }
    }

    csv_in.close();

}
