#include <iostream>
#include <string>
#include <iomanip> 
#include "Data.h"
#include "Presentation.h"

bool checkInteger(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}

int getIndexById(STUDENTS* students, int count, int ID)
{

	for (int j = 0; j < count; j++)
	{
		if (students[j].studentID == ID)
		{
			return j;
		}

	}
	return -1;
}

void createStudent(STUDENTS* students, int& studentCount, int& maxStudentID, STUDENTS newStudent)

{
	newStudent.studentID = maxStudentID++;
	students[studentCount] = newStudent;
	studentCount++;
}

void updateStudent(STUDENTS* students, int studentCount, int studentID, STUDENTS newStudent)
{

	int index = getIndexById(students, studentCount, studentID);

	students[index] = newStudent;

}

void deleteStudent(STUDENTS* students, int& studentCount, int studentID)
{

	int index = getIndexById(students, studentCount, studentID);

	for (int j = index; j < studentCount - 1; j++)
	{
		students[j] = students[j + 1];
	}

	studentCount--;

}

STUDENTS getStudent(STUDENTS* students, int& studentCount, int studentID)
{

	int index = getIndexById(students, studentCount, studentID);

	return students[index];

}

bool checkAvailableStudents(STUDENTS* students, int& studentCount, string searchedRole)
{
	int studentsWithRole = 0;
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].role == searchedRole and students[i].hasTeam == false)
		{
			studentsWithRole++;
		}
	}
	if (studentsWithRole == 0)
	{
		cout << "there are no available students with this role." << endl;
		return false;
	}
	else
	{
		return true;
	}
}

int getTeacherIndexByID(TEACHERS* teachers, int& teacherCount, int teacherID)
{

	for (int j = 0; j < teacherCount; j++)
	{
		if (teachers[j].teacherID == teacherID)
		{
			return j;
		}

	}
	return -1;
}

void createTeacher(TEACHERS* teachers, int& teacherCount, int& maxTeacherID, TEACHERS newTeacher)

{
	newTeacher.teacherID = maxTeacherID++;
	teachers[teacherCount] = newTeacher;
	teacherCount++;
}

void updateTeacher(TEACHERS* teachers, int teacherCount, int teacherID, TEACHERS newTeacher)
{

	int index = getTeacherIndexByID(teachers, teacherCount, teacherID);

	teachers[index] = newTeacher;

}

void deleteTeacher(TEACHERS* teachers, int& teacherCount, int teacherID)
{
	int index = getTeacherIndexByID(teachers, teacherCount, teacherID);

	for (int j = index; j < teacherCount - 1; j++)
	{
		teachers[j] = teachers[j + 1];
	}
	teacherCount--;
}

TEACHERS getTeacher(TEACHERS* teachers, int& teacherCount, int teacherID)
{
	int index = getTeacherIndexByID(teachers, teacherCount, teacherID);
	return teachers[index];
}

int getTeamIndexByID(TEAMS* teams, int& teamsCount, int teamID)
{
	for (int j = 0; j < teamsCount; j++)
	{
		if (teams[j].teamID == teamID)
		{
			return j;
		}
	}
	return -1;
}

void createTeam(TEAMS* teams, int& teamsCount, int& maxTeamID, TEAMS newTeam)

{
	newTeam.teamID = maxTeamID++;
	teams[teamsCount] = newTeam;
	teamsCount++;
}

void updateTeam(TEAMS* teams, int teamsCount, int teamID, TEAMS newTeam)
{
	int index = getTeamIndexByID(teams, teamsCount, teamID);
	teams[index] = newTeam;
}

void deleteTeam(TEAMS* teams, int& teamsCount, int teamID, STUDENTS* students, int& studentCount, TEACHERS* teachers, int& teacherCount)
{
	int index = getTeamIndexByID(teams, teamsCount, teamID);
	TEAMS team = getTeam(teams, teamsCount, teamID);
	STUDENTS backend = getStudent(students, studentCount, team.backEnd.studentID);
	backend.hasTeam = false;
	updateStudent(students, studentCount, team.backEnd.studentID, backend);

	STUDENTS frontend = getStudent(students, studentCount, team.frontEnd.studentID);
	frontend.hasTeam = false;
	updateStudent(students, studentCount, team.frontEnd.studentID, frontend);

	STUDENTS master = getStudent(students, studentCount, team.master.studentID);
	master.hasTeam = false;
	updateStudent(students, studentCount, team.master.studentID, master);

	STUDENTS qa = getStudent(students, studentCount, team.QA.studentID);
	qa.hasTeam = false;
	updateStudent(students, studentCount, team.QA.studentID, qa);

	TEACHERS teach = getTeacher(teachers, teacherCount, team.teamTeacher.teacherID);
	teach.hasTeam = false;
	updateTeacher(teachers, teacherCount, team.teamTeacher.teacherID, teach);
	for (int j = index; j < teamsCount - 1; j++)
	{
		teams[j] = teams[j + 1];
	}
	teamsCount--;
}

TEAMS getTeam(TEAMS* teams, int& teamsCount, int teamID)
{
	int index = getTeamIndexByID(teams, teamsCount, teamID);
	return teams[index];
}

void createTeamMenu(TEAMS* teams, int& teamCount, int& maxTeamID, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount)
{
	system("CLS");
	TEAMS addTeam;
	cout << " Team Name  ";
	cin >> addTeam.teamName;

	cout << "Team descritpion ";
	cin >> addTeam.teamDescription;
	if (checkAvailableStudents(students, studentCount, "backend")
		and checkAvailableStudents(students, studentCount, "frontend")
		and checkAvailableStudents(students, studentCount, "QA")
		and checkAvailableStudents(students, studentCount, "master")
		and teacherCount != 0)
	{
		cout << "Which back-end developer is in the team?" << endl;
		showStudentsPerRole(students, studentCount, "backend");
		int backEndID;
		cin >> backEndID;
		STUDENTS backend = getStudent(students, studentCount, backEndID);
		backend.hasTeam = true;
		updateStudent(students, studentCount, backEndID, backend);
		addTeam.backEnd = backend;

		cout << "Which front-end developer is in the team?" << endl;
		showStudentsPerRole(students, studentCount, "frontend");
		int frontEndID;
		cin >> frontEndID;
		STUDENTS frontend = getStudent(students, studentCount, frontEndID);
		frontend.hasTeam = true;
		updateStudent(students, studentCount, frontEndID, frontend);
		addTeam.frontEnd = frontend;

		cout << "Which quality engineer is in the team?" << endl;
		showStudentsPerRole(students, studentCount, "QA");
		int QAID;
		cin >> QAID;
		STUDENTS qa = getStudent(students, studentCount, QAID);
		qa.hasTeam = true;
		updateStudent(students, studentCount, QAID, qa);
		addTeam.QA = qa;

		cout << "Which scrum master is in the team?" << endl;
		showStudentsPerRole(students, studentCount, "master");
		int masterID;
		cin >> masterID;
		STUDENTS master = getStudent(students, studentCount, masterID);
		master.hasTeam = true;
		updateStudent(students, studentCount, masterID, master);
		addTeam.master = master;

		cout << "Which teacher is in the team?";
		showTeachers(teachers, teacherCount, teams, teamCount);
		int TeacherID;
		cin >> TeacherID;
		TEACHERS teacher = getTeacher(teachers, teacherCount, TeacherID);
		teacher.hasTeam = true;
		updateTeacher(teachers, teacherCount, TeacherID, teacher);
		addTeam.teamTeacher = teacher;
		system("CLS");
		createTeam(teams, teamCount, maxTeamID, addTeam);
	}
	else
	{
		cout << "+-------------------------+" << endl;
		cout << "|Team cound not be created|" << endl;
		cout << "+-------------------------+" << endl;
	}
}

int getSchoolIndexByID(SCHOOLS* schools, int& schoolCount, int schoolID)
{
	for (int j = 0; j < schoolCount; j++)
	{
		if (schools[j].schoolID == schoolID)
		{
			return j;
		}

	}
	return -1;
}

void createSchool(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, SCHOOLS newSchool)
{
	newSchool.schoolID = maxSchoolID++;
	schools[schoolCount] = newSchool;
	schoolCount++;
}

void updateSchool(SCHOOLS* schools, int schoolCount, int schoolID, SCHOOLS newSchool)
{

	int index = getSchoolIndexByID(schools, schoolCount, schoolID);

	schools[index] = newSchool;

}

void deleteSchool(SCHOOLS* schools, int& schoolCount, int schoolID, STUDENTS* students, int studentCount, TEACHERS* teachers, int teacherCount, TEAMS* teams, int teamCount)
{

	int index = getSchoolIndexByID(schools, schoolCount, schoolID);
	SCHOOLS del = getSchool(schools, schoolCount, schoolID);
	for (int i = 0; i < del.studentsInSchoolNum; i++)
	{
		STUDENTS removeStudents = getStudent(students, studentCount, del.studentsInSchool[i].studentID);
		removeStudents.hasSchool = false;
		updateStudent(students, studentCount, del.studentsInSchool[i].studentID, removeStudents);
	}
	for (int i = 0; i < del.teachersInSchoolNum; i++)
	{
		TEACHERS removeTeachers = getTeacher(teachers, teacherCount, del.teachersInSchool[i].teacherID);
		removeTeachers.hasSchool = false;
		updateTeacher(teachers, teacherCount, del.teachersInSchool[i].teacherID, removeTeachers);
	}
	for (int i = 0; i < del.teamsInSchoolNum; i++)
	{
		TEAMS removeTeams = getTeam(teams, teacherCount, del.teamsInSchool[i].teamID);
		removeTeams.hasSchool = false;
		updateTeam(teams, teamCount, del.teamsInSchool[i].teamID, removeTeams);
	}
	for (int j = index; j < schoolCount - 1; j++)
	{
		schools[j] = schools[j + 1];
	}

	schoolCount--;

}

SCHOOLS getSchool(SCHOOLS* schools, int& schoolCount, int schoolID)
{

	int index = getSchoolIndexByID(schools, schoolCount, schoolID);

	return schools[index];

}

void addPeopleMenu(SCHOOLS* schools, int& schoolCount, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount, TEAMS* teams, int& teamCount, int editedId)
{
	system("CLS");
	cout << "+----------------+" << endl;
	cout << "|--- ADD MENU ---|" << endl;
	cout << "+----------------+" << endl;
	cout << "|1. students     |" << endl;
	cout << "|2. teachers     |" << endl;
	cout << "|3. teams        |" << endl;
	cout << "+----------------+" << endl;
	string levelChoice;
	int choice;
	cin >> levelChoice;
	if (checkInteger(levelChoice) == false)
	{
		do {
			system("CLS");
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|The value you entered was not an integer. Please enter a whole number|" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cin >> levelChoice;
			checkInteger(levelChoice);
		} while (checkInteger(levelChoice) == false);
	}
	choice = stoi(levelChoice);
	int availableStudents;
	int availableTeachers;
	int availableTeams;
	switch (choice)
	{
	case 1:
		system("CLS");
		availableStudents = showStudentsNoSchool(students, studentCount);
		if (availableStudents > 0)
		{
			system("CLS");
			SCHOOLS addPeople = getSchool(schools, schoolCount, editedId);
			int studentId;
			cout << "which ID?";
			cin >> studentId;
			STUDENTS tt = getStudent(students, studentCount, studentId);
			tt.hasSchool = true;
			updateStudent(students, studentCount, studentId, tt);
			addPeople.studentsInSchool[addPeople.studentsInSchoolNum] = tt;
			addPeople.studentsInSchoolNum = 1 + addPeople.studentsInSchoolNum;
			updateSchool(schools, schoolCount, editedId, addPeople);
		}
		break;
	case 2:
		system("CLS");
		availableTeachers = showTeachersNoSchool(teachers, teacherCount, teams, teamCount);
		if (availableTeachers > 0)
		{
			int editedId2;
			SCHOOLS addTeachers = getSchool(schools, schoolCount, editedId);
			cout << "which ID?";
			cin >> editedId2;
			TEACHERS tt = getTeacher(teachers, teacherCount, editedId2);
			tt.hasSchool = true;
			updateTeacher(teachers, teacherCount, editedId2, tt);
			addTeachers.teachersInSchool[addTeachers.teachersInSchoolNum] = tt;
			addTeachers.teachersInSchoolNum = 1 + addTeachers.teachersInSchoolNum;
			updateSchool(schools, schoolCount, editedId, addTeachers);
		}
		break;
	case 3:
		system("CLS");
		availableTeams = showTeamsNoSchool(teams, teamCount);
		if (availableTeams > 0)
		{
			system("CLS");
			int editedId3;
			SCHOOLS addPeople = getSchool(schools, schoolCount, editedId);
			cout << "which ID?";
			cin >> editedId3;
			TEAMS tt = getTeam(teams, teamCount, editedId3);
			tt.hasSchool = true;
			updateTeam(teams, teamCount, editedId3, tt);
			addPeople.teamsInSchool[addPeople.teamsInSchoolNum] = tt;
			addPeople.teamsInSchoolNum = 1 + addPeople.teamsInSchoolNum;
			updateSchool(schools, schoolCount, editedId, addPeople);
		}
		break;
	}
}