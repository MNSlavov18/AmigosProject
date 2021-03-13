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
int getTeacherIndexByID(TEACHERS* teachers, int& teacherCount, int teacherID);
void createTeacher(TEACHERS* teachers, int& teacherCount, int& maxTeacherID, TEACHERS newTeacher);
void updateTeacher(TEACHERS* teachers, int teacherCount, int teacherID, TEACHERS newTeacher);
void deleteTeacher(TEACHERS* teachers, int& teacherCount, int teacherID);
TEACHERS getTeacher(TEACHERS* teachers, int& teacherCount, int teacherID);
int getTeamIndexByID(TEAMS* teams, int& teamsCount, int teamID);
void createTeam(TEAMS* teams, int& teamsCount, int& maxTeamID, TEAMS newTeam);
void updateTeam(TEAMS* teams, int teamsCount, int teamID, TEAMS newTeam);
void deleteTeam(TEAMS* teams, int& teamsCount, int teamID, STUDENTS* students, int& studentCount, TEACHERS* teachers, int& teacherCount);
TEAMS getTeam(TEAMS* teams, int& teamsCount, int teamID);
int getSchoolIndexByID(SCHOOLS* schools, int& schoolCount, int schoolID);
void createSchool(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, SCHOOLS newSchool);
void updateSchool(SCHOOLS* schools, int schoolCount, int schoolID, SCHOOLS newSchool);
void deleteSchool(SCHOOLS* schools, int& schoolCount, int schoolID, STUDENTS* students, int studentCount, TEACHERS* teachers, int teacherCount, TEAMS* teams, int teamCount);
SCHOOLS getSchool(SCHOOLS* schools, int& schoolCount, int schoolID);