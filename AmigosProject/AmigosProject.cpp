#include <iostream>
#include <string>
#include <iomanip> 
#include "Data.h"
#include "Presentation.h"
using namespace std;

int main()
{
    int* studentCount = new int(0);
    int* maxStudentID = new int(1);
    STUDENTS  students[10];
    int* teacherCount = new int(0);
    int* maxTeacherID = new int(1);
    TEACHERS  teachers[10];
    int* schoolCount = new int(0);
    int* maxSchoolID = new int(1);
    SCHOOLS  schools[10];
    int* TeamCount = new int(0);
    int* maxTeamID = new int(1);
    TEAMS teams[10];
    bool doShowMenu;

    do {
        doShowMenu = mainMenu(schools, *schoolCount, *maxSchoolID, teachers, *teacherCount, *maxTeacherID, students, *studentCount, *maxStudentID, teams, *TeamCount, *maxTeamID);
    } while (doShowMenu);

}