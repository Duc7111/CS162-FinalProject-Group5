#include "AS.h"
#include "const.h"
#include "const.h"
#include "Screen.h"
#include "student.h"
#include "console.h"
#include <fstream>
using namespace std;

void ExportStudentName2CSV(string dir);
void ExportScoreBoard2CSV(string dir, course CurCourse);
void ImportScoreBoard(string dir, course CurCourse);
void ViewCourseScoreBoard(string dir, course CurCourse);

bool isNum(string s);
