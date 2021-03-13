#pragma once
#include <iostream>

using namespace std;

void createStudentMenu(STUDENTS* students, int& studentCount, int& maxStudentID);
void showStudents(STUDENTS* students, int& studentCount);
int showStudentsNoSchool(STUDENTS* students, int& studentCount);
int showTeachersNoSchool(TEACHERS* teachers, int& teacherCount, TEAMS* teams, int& teamCount);
int showTeamsNoSchool(TEAMS* teams, int& teamCount);
void showStudentsPerRole(STUDENTS* students, int& studentCount, string searchedRole);
void deleteStudentMenu(STUDENTS* students, int& studentCount);
void editStudentMenu(STUDENTS* students, int& studentCount);
bool showStudentMenu(STUDENTS* students, int& studentCount, int& maxStudentID);
void createTeacherMenu(TEACHERS* teachers, int& teacherCount, int& maxTeacherID);
void showTeachers(TEACHERS* teachers, int& teacherCount, TEAMS* teams, int& teamCount);
void deleteTeacherMenu(TEACHERS* teachers, int& teacherCount);
void editTeacherMenu(TEACHERS* teachers, int& teacherCount);
bool showTeacherMenu(TEACHERS* teachers, int& teacherCount, int& maxTeacherID, TEAMS* teams, int& teamCount); void createTeamMenu(TEAMS* teams, int& teamsCount, int& maxTeamID, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount);
void showTeams(TEAMS* teams, int& teamsCount);
void deleteTeamMenu(TEAMS* teams, int& teamsCount, STUDENTS* students, int& studentCount, TEACHERS* teachers, int& teacherCount);
void editTeamMenu(TEAMS* teams, int& teamsCount, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount);
bool showTeamMenu(TEAMS* teams, int& teamCount, int& maxTeamID, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount);
void createSchoolMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount, TEAMS* teams, int& teamCount);
void showSchools(SCHOOLS* schools, int& schoolCount);
void deleteSchoolMenu(SCHOOLS* schools, int& schoolCount, STUDENTS* students, int& studentCount, TEACHERS* teachers, int& teacherCount, TEAMS* teams, int& teamCount);
void editSchoolMenu(SCHOOLS* schools, int& schoolCount, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount, TEAMS* teams, int& teamCount);
bool showSchoolMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount, TEAMS* teams, int& teamCount);
void showteachersNoTeam(TEACHERS* teachers, int& teacherCount);
void showStudentsNoTeam(STUDENTS* students, int& studentCount);
bool showReportsMenu(SCHOOLS* schools, int& schoolCount, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount, TEAMS* teams, int& teamCount);
bool mainMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& teacherCount, int& maxTeacherID, STUDENTS* students, int& studentCount, int& maxStudentID, TEAMS* teams, int& teamCount, int& maxTeamID);