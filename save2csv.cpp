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

void ExportScoreBoard2CSV(string dir, list<CourseSB>*& ScoreBoard)
{
    list<CourseSB>* tmp = ScoreBoard;

    ofstream csv_out("SB_TeacherVer.csv");

    csv_out << "No" << "," << "ID" << "," << "Full Name" << ","
        << "Total Mark" << "," << "Final" << "," << "Midterm";

    list<int>* tmp_ = tmp->data.OtherMark;
    for (int i = 0; i < tmp->data.OM_AmountCount(); i++)
        csv_out << "," << "Other Mark " << i + 1;
    csv_out << "\n";

    while (tmp != NULL)
    {
        csv_out << tmp->data.StuNo << "," << tmp->data.StuID << "," << tmp->data.FullName << ","
            << tmp->data.mark[0] << "," << tmp->data.mark[1] << "," << tmp->data.mark[2];

        for (int i = 0; i < tmp->data.OM_AmountCount(); i++)
        {
            csv_out << "," << tmp_->data;
            tmp_ = tmp_->next;
        }

        csv_out << "\n";
        tmp = tmp->next;
    }

    csv_out.close();
}

void Import_StudentInfo_ScoreBoard(list<CourseSB>*& ScoreBoard)
{
    list<CourseSB>* CurStudent = new list<CourseSB>;
    if (ScoreBoard != NULL) CurStudent->data.StuNo = ScoreBoard->data.StuNo + 1;

    cout << "Please enter the student's ID: ";
    getline(cin, CurStudent->data.StuID);
    cout << endl;

    cout << "Please enter the student's full name: ";
    getline(cin, CurStudent->data.FullName);
    cout << endl;

    cout << "Please enter the student's midterm score: ";
    cin >> CurStudent->data.mark[2];
    cout << endl;

    cout << "Please enter the student's final exam score: ";
    cin >> CurStudent->data.mark[1];
    cout << endl;

    cout << "Please enter the student's total mark: ";
    cin >> CurStudent->data.mark[0];
    cout << endl;
}
