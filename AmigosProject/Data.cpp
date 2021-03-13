#include <iostream>
using namespace std;
#pragma once

struct STUDENTS {

	string name;
	string surname;
	string studentClass;
	string role;
	string email;
	int studentID;
	bool hasTeam = false;
	bool hasSchool = false;
};

struct TEACHERS {

	string teacherName;
	string teacherSubname;
	string teacherEmail;
	int teacherID;
	bool hasTeam = false;
	bool hasSchool = false;
};
struct TEAMS
{
	string teamName;
	string teamDescription;
	struct STUDENTS backEnd;
	struct STUDENTS frontEnd;
	struct STUDENTS QA;
	struct STUDENTS master;
	struct TEACHERS teamTeacher;
	int teamID;
	bool hasSchool = false;
};

struct SCHOOLS {

	string schoolName;
	string city;
	string address;
	int schoolID;
	struct STUDENTS studentsInSchool[10];
	struct TEACHERS teachersInSchool[10];
	struct TEAMS teamsInSchool[10];
	int studentsInSchoolNum = 0;
	int teachersInSchoolNum = 0;
	int teamsInSchoolNum = 0;
};

bool checkInteger(string str);
int getIndexById(STUDENTS* students, int count, int ID);
void createStudent(STUDENTS* students, int& studentCount, int& maxStudentID, STUDENTS  newStudent);
void updateStudent(STUDENTS* students, int studentCount, int studentID, STUDENTS  newStudent);
void deleteStudent(STUDENTS* students, int& studentCount, int studentID);
STUDENTS getStudent(STUDENTS* students, int& studentCount, int studentID);
bool checkAvailableStudents(STUDENTS* students, int& studentCount, string searchedRole);