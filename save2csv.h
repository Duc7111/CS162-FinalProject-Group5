#include "AS.h"
#include "const.h"
#include "const.h"
#include "Screen.h"
#include "student.h"
#include "console.h"
#include <fstream>
using namespace std;

struct CourseSB {
    int StuNo;
    string StuID;
    string FullName;
    
    double Midterm;
    double Final;
    double Total;
    
    list<double>* OtherMark;

    int OM_AmountCount() {
        int c = 0;
        list<double>* tmp = OtherMark;
        while (tmp != NULL) {
            ++c;
            tmp = tmp->next;
        }
        return c;
    }
};

void ExportStudentName2CSV(string dir);
void ExportScoreBoard2CSV(string dir, list<CourseSB>*& ScoreBoard);
void Import_StudentInfo_ScoreBoard(list<CourseSB>*& ScoreBoard);
