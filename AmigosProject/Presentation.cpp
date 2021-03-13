#include <iostream>
#include <string>
#include <iomanip> 
#include "Data.h"
#include "Presentation.h"

void createStudentMenu(STUDENTS* students, int& studentCount, int& maxStudentID)
{
	system("CLS");
	STUDENTS addStudent;
	cout << "+---------------------------------+" << endl;
	cout << "|What is the student's first name?|" << endl;
	cout << "+---------------------------------+" << endl;
	cin >> addStudent.name;

	cout << "+----------------------------------+" << endl;
	cout << "|What is the student's second name?|" << endl;
	cout << "+----------------------------------+" << endl;
	cin >> addStudent.surname;

	cout << "+----------------------------+" << endl;
	cout << "|What is the student's class?|" << endl;
	cout << "+----------------------------+" << endl;
	cin >> addStudent.studentClass;

	cout << " +-------------------------+  " << endl;
	cout << " |What is the student's role|  " << endl;
	cout << " |--------------------------|  " << endl;
	cout << " |-backend                  |  " << endl;
	cout << " |-frontend                 |  " << endl;
	cout << " |-QA                       |  " << endl;
	cout << " |-master                   |  " << endl;
	cout << " +--------------------------+  " << endl;
	cin >> addStudent.role;
	if (addStudent.role.compare("backend") != 0 and addStudent.role.compare("frontend") != 0
		and addStudent.role.compare("QA") != 0 and addStudent.role.compare("master") != 0)
	{
		do {
			cout << "Please enter one of the four roles above" << endl;
			cin >> addStudent.role;
		} while (addStudent.role.compare("backend") != 0 and addStudent.role.compare("frontend") != 0
			and addStudent.role.compare("QA") != 0 and addStudent.role.compare("master") != 0);
	}

	cout << "+----------------------------+" << endl;
	cout << "|What is the student's email?|" << endl;
	cout << "+----------------------------+" << endl;
	cin >> addStudent.email;
	system("CLS");
	createStudent(students, studentCount, maxStudentID, addStudent);
}

void showStudents(STUDENTS* students, int& studentCount)
{
	system("CLS");
	if (studentCount > 0)
	{
		cout << "Here are all the students so far : " << endl;
		for (int j = 0; j < studentCount; j++)
		{
			cout << "ID : ";
			cout << students[j].studentID << " | Name : "
				<< students[j].name << " | surname : "
				<< students[j].surname << " | class: "
				<< students[j].studentClass << " | role: "
				<< students[j].role << " | email: "
				<< students[j].email << endl;
		}
		cout << endl;
	}
	else
	{

		cout << "There are no students inserted yet. " << endl << endl
			<< "You can insert some using the |Add student| button of the menu." << endl << endl;
	}
}


int showStudentsNoSchool(STUDENTS* students, int& studentCount)
{
	int availableStudents = 0;
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].hasSchool == false)
		{
			availableStudents++;
			cout << "ID : ";
			cout << students[i].studentID << " | Name : "
				<< students[i].name << " | surname : "
				<< students[i].surname << " | class: "
				<< students[i].studentClass << " | role: "
				<< students[i].role << " | email: "
				<< students[i].email << endl;
		}
	}
	cout << endl;
	if (availableStudents == 0)
	{
		cout << "No students without school found" << endl << endl;
		return 0;
	}
	else
	{
		return availableStudents;
	}
}

void showStudentsPerRole(STUDENTS* students, int& studentCount, string searchedRole)
{
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].role == searchedRole and students[i].hasTeam == false)
		{
			cout << "ID : ";
			cout << students[i].studentID << " | Name : "
				<< students[i].name << " | surname : "
				<< students[i].surname << " | class: "
				<< students[i].studentClass << " | email: "
				<< students[i].email << endl;
		}
		cout << endl;
	}
	cout << endl;
}

void deleteStudentMenu(STUDENTS* students, int& studentCount)
{
	system("CLS");
	if (studentCount > 0)
	{

		int deleteGameId;
		cout << "+----------------------------------------------+" << endl;
		cout << "|Enter the Id of the student you want to delete|" << endl;
		cout << "+----------------------------------------------+" << endl;
		cin >> deleteGameId;

		deleteStudent(students, studentCount, deleteGameId);

	}
	else
	{
		cout << "There are no students inserted yet. " << endl << endl
			<< "You can insert some using the |Add a student| button of the menu." << endl << endl;
	}

}

void editStudentMenu(STUDENTS* students, int& studentCount)
{
	system("CLS");
	if (studentCount > 0)
	{
		int editedId;
		cout << "Enter the ID of the student you want to change : ";
		cin >> editedId;
		STUDENTS editStudent = getStudent(students, studentCount, editedId);
		cout << "+-----------+" << endl;
		cout << "|-EDIT MENU-|" << endl;
		cout << "+-----------+" << endl;
		cout << "|1.name     |" << endl;
		cout << "|2.surname  |" << endl;
		cout << "|3.class    |" << endl;
		cout << "|4.role     |" << endl;
		cout << "|5.email    |" << endl;
		cout << "+-----------+" << endl;
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
		switch (choice)
		{
		case 1:
			cout << " +-------------------------------+  " << endl;
			cout << " |Choose a new student first name|  " << endl;
			cout << " +-------------------------------+  " << endl;
			cin >> editStudent.name;
			updateStudent(students, studentCount, editedId, editStudent);
			break;

		case 2:
			cout << " +----------------------------+  " << endl;
			cout << " |Choose a new student surname|  " << endl;
			cout << " +----------------------------+  " << endl;
			cin >> editStudent.surname;
			updateStudent(students, studentCount, editedId, editStudent);
			break;

		case 3:
			cout << " +--------------------------+  " << endl;
			cout << " |Choose a new student class|  " << endl;
			cout << " +--------------------------+  " << endl;
			cin >> editStudent.studentClass;
			updateStudent(students, studentCount, editedId, editStudent);
			break;
		case 4:
			cout << " +-------------------------+  " << endl;
			cout << " |Choose a new student role|  " << endl;
			cout << " |-------------------------|  " << endl;
			cout << " |-backend                 |  " << endl;
			cout << " |-frontend                |  " << endl;
			cout << " |-QA                      |  " << endl;
			cout << " |-master                  |  " << endl;
			cout << " +-------------------------+  " << endl;
			cin >> editStudent.role;
			updateStudent(students, studentCount, editedId, editStudent);
			break;
		case 5:
			cout << " +--------------------------+  " << endl;
			cout << " |Choose a new student email|  " << endl;
			cout << " +--------------------------+  " << endl;
			cin >> editStudent.email;
			updateStudent(students, studentCount, editedId, editStudent);
			break;
		default:
			cout << "The number you choose was not valid!" << endl;
			break;
		}
	}
	else
	{
		cout << "There are no students inserted yet. " << endl << endl
			<< "You can insert some using the |Add a student| button of the menu." << endl << endl;
	}
}

bool showStudentMenu(STUDENTS* students, int& studentCount, int& maxStudentID)
{
	cout << "+--------------------+" << endl;
	cout << "|--- STUDENT MENU ---|" << endl;
	cout << "|--------------------|" << endl;
	cout << "|1. Show all students|" << endl;
	cout << "|2. Add a student    |" << endl;
	cout << "|3. Edit a student   |" << endl;
	cout << "|4. Delete a student |" << endl;
	cout << "|5. Exit menu        |" << endl;
	cout << "+--------------------+" << endl;
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
	switch (choice)
	{
	case 1:
		showStudents(students, studentCount);
		break;

	case 2:
		createStudentMenu(students, studentCount, maxStudentID);
		break;

	case 3:
		editStudentMenu(students, studentCount);
		break;

	case 4:
		deleteStudentMenu(students, studentCount);
		break;
	case 5:
		return false;
	default: break;
		cout << "The number you choose was not valid!" << endl;
	}
	return true;
}
void createTeacherMenu(TEACHERS* teachers, int& teacherCount, int& maxTeacherID)
{
	system("CLS");
	TEACHERS addTeacher;
	cout << " +-------------------------------+  " << endl;
	cout << " |Whats the teacher's first name?|  " << endl;
	cout << " +-------------------------------+  " << endl;
	cin >> addTeacher.teacherName;

	cout << " +--------------------------------+  " << endl;
	cout << " |Whats the teacher's second name?|  " << endl;
	cout << " +--------------------------------+  " << endl;
	cin >> addTeacher.teacherSubname;

	cout << " +--------------------------+  " << endl;
	cout << " |Whats the teacher's email?|  " << endl;
	cout << " +--------------------------+  " << endl;
	cin >> addTeacher.teacherEmail;
	system("CLS");
	createTeacher(teachers, teacherCount, maxTeacherID, addTeacher);
}

void showTeachers(TEACHERS* teachers, int& teacherCount, TEAMS* teams, int& teamCount)
{
	system("CLS");
	if (teacherCount > 0)
	{
		cout << "Here are all the teachers so far : " << endl;
	}
	else
	{
		cout << "There are no teachers inserted yet. " << endl << endl
			<< "You can insert some using the |Add a teacher| button of the menu." << endl << endl;
	}

	for (int j = 0; j < teacherCount; j++)
	{
		cout << "ID : ";
		cout << teachers[j].teacherID << " | Name : "
			<< teachers[j].teacherName << " | Subname : "
			<< teachers[j].teacherSubname << " | email: "
			<< teachers[j].teacherEmail;
		for (int i = 0; i < teamCount; i++)
		{
			cout << teamCount;
			cout << "| Teams:" << endl;
			if (teams[i].teamTeacher.teacherName == teachers[j].teacherName)
			{
				teachers[j].hasTeam = true;
				updateTeacher(teachers, teacherCount, teachers[j].teacherID, teachers[j]);
				cout << teams[j].teamName << " | Description : "
					<< teams[j].teamDescription << " | frontend: "
					<< teams[j].frontEnd.name << " | backend: "
					<< teams[j].backEnd.name << " | QA: "
					<< teams[j].QA.name << " | master: "
					<< teams[j].master.name << endl;
			}
		}
		cout << endl;
	}
	cout << endl;
}


int showTeachersNoSchool(TEACHERS* teachers, int& teacherCount, TEAMS* teams, int& teamCount)
{
	int availableTeachers = 0;
	for (int j = 0; j < teacherCount; j++)
	{
		if (teachers[j].hasSchool == false)
		{
			availableTeachers++;
			cout << "ID : ";
			cout << teachers[j].teacherID << " | Name : "
				<< teachers[j].teacherName << " | Subname : "
				<< teachers[j].teacherSubname << " | email: "
				<< teachers[j].teacherEmail;
			for (int i = 0; i < teamCount; i++)
			{
				cout << "Teams:" << endl;
				if (teams[i].teamTeacher.teacherName == teachers[j].teacherName)
				{
					teachers[j].hasTeam = true;
					updateTeacher(teachers, teacherCount, teachers[j].teacherID, teachers[j]);
					cout << teams[j].teamName << " | Description : "
						<< teams[j].teamDescription << " | frontend: "
						<< teams[j].frontEnd.name << " | backend: "
						<< teams[j].backEnd.name << " | QA: "
						<< teams[j].QA.name << " | master: "
						<< teams[j].master.name << endl;
				}
			}
			cout << endl;
		}
	}
	cout << endl;
	if (availableTeachers == 0)
	{
		cout << "No teachers without school found" << endl << endl;
		return 0;
	}
	else
	{
		return availableTeachers;
	}
}

void deleteTeacherMenu(TEACHERS* teachers, int& teacherCount)
{
	system("CLS");
	if (teacherCount > 0)
	{

		int deleteGameId;

		cout << "Enter the Id of the teacher you want to delete : ";
		cin >> deleteGameId;

		deleteTeacher(teachers, teacherCount, deleteGameId);

	}
	else
	{
		cout << "There are no teachers inserted yet. " << endl << endl
			<< "You can insert some using the |Add a teacher| button of the menu." << endl << endl;
	}

}

void editTeacherMenu(TEACHERS* teachers, int& teacherCount)
{
	system("CLS");
	if (teacherCount > 0)
	{
		int editedId;
		cout << "Enter the ID of the teacher you want to change : ";
		cin >> editedId;

		TEACHERS editTeacher = getTeacher(teachers, teacherCount, editedId);
		cout << "+----------+" << endl;
		cout << "|1. name   |" << endl;
		cout << "|2. subname|" << endl;
		cout << "|3. Email  |" << endl;
		cout << "+----------+" << endl;
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
		switch (choice)
		{

		case 1:
			cout << " Choose a new teacher name : ";
			cin >> editTeacher.teacherName;
			updateTeacher(teachers, teacherCount, editedId, editTeacher);
			break;

		case 2:
			cout << "Choose a new teacher subname: ";
			cin >> editTeacher.teacherSubname;
			updateTeacher(teachers, teacherCount, editedId, editTeacher);
			break;
		case 3:
			cout << "Choose  a new teacher email : ";
			cin >> editTeacher.teacherEmail;
			updateTeacher(teachers, teacherCount, editedId, editTeacher);
			break;
		default:
			cout << "The number you choose was not valid!" << endl;
			break;
		}
	}
	else
	{
		cout << "There are no teachers inserted yet. " << endl << endl
			<< "You can insert some using the |Add a teacher| button of the menu." << endl << endl;
	}
}
bool showTeacherMenu(TEACHERS* teachers, int& teacherCount, int& maxTeacherID, TEAMS* teams, int& teamCount)
{
	cout << "+-------------------+" << endl;
	cout << "|-- TEACHER  MENU --|" << endl;
	cout << "+-------------------+" << endl;
	cout << "|1.Show all teachers|" << endl;
	cout << "|2.Add a teacher    |" << endl;
	cout << "|3.Edit a teacher   |" << endl;
	cout << "|4.Delete a teacher |" << endl;
	cout << "|5.Exit Menu        |" << endl;
	cout << "+-------------------+" << endl;

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
	switch (choice)
	{
	case 1:
		showTeachers(teachers, teacherCount, teams, teamCount);
		break;

	case 2:
		createTeacherMenu(teachers, teacherCount, maxTeacherID);
		break;

	case 3:
		editTeacherMenu(teachers, teacherCount);
		break;

	case 4:
		deleteTeacherMenu(teachers, teacherCount);
		break;
	case 5:
		return false;
	default: break;
		cout << "The number you choose was not valid!" << endl;
	}
	return true;
}

void showTeams(TEAMS* teams, int& teamsCount)
{
	system("CLS");
	if (teamsCount > 0)
	{
		cout << "Here are all the teams so far : " << endl;
	}
	else
	{
		cout << "There are no teams inserted yet. " << endl << endl
			<< "You can insert some using the |Add a team| button of the menu." << endl << endl;
	}

	for (int j = 0; j < teamsCount; j++)
	{
		cout << "ID : ";
		cout << teams[j].teamID << " | Name : "
			<< teams[j].teamName << " | Description : "
			<< teams[j].teamDescription << " | teacher: "
			<< teams[j].teamTeacher.teacherName << " | frontend: "
			<< teams[j].frontEnd.name << " | backend: "
			<< teams[j].backEnd.name << " | QA: "
			<< teams[j].QA.name << " | master: "
			<< teams[j].master.name << endl;
	}
	cout << endl;
}

void deleteTeamMenu(TEAMS* teams, int& teamsCount, STUDENTS* students, int& studentCount, TEACHERS* teachers, int& teacherCount)
{
	system("CLS");
	if (teamsCount > 0)
	{

		int deleteTeamID;

		cout << "Enter the Id of the team you want to delete : ";
		cin >> deleteTeamID;
		deleteTeam(teams, teamsCount, deleteTeamID, students, studentCount, teachers, teacherCount);
	}
	else
	{
		cout << "There are no teams inserted yet. " << endl << endl
			<< "You can insert some using the |Add a team| button of the menu." << endl << endl;
	}

}

int showTeamsNoSchool(TEAMS* teams, int& teamCount)
{
	int availableTeams = 0;
	for (int j = 0; j < teamCount; j++)
	{
		if (teams[j].hasSchool == false)
		{
			availableTeams++;
			cout << "ID : ";
			cout << teams[j].teamID << " | Name : "
				<< teams[j].teamName << " | Description : "
				<< teams[j].teamDescription << " | teacher: "
				<< teams[j].teamTeacher.teacherName << " | frontend: "
				<< teams[j].frontEnd.name << " | backend: "
				<< teams[j].backEnd.name << " | QA: "
				<< teams[j].QA.name << " | master: "
				<< teams[j].master.name << endl;
		}
	}
	if (availableTeams == 0)
	{
		cout << "No teams without school found" << endl << endl;
		return 0;
	}
	else
	{
		return availableTeams;
	}
}



void editTeamMenu(TEAMS* teams, int& teamCount, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount)
{
	system("CLS");
	if (teamCount > 0)
	{
		int editedId;
		cout << "Enter the ID of the team you want to change : ";
		cin >> editedId;
		TEAMS editName = getTeam(teams, teamCount, editedId);
		cout << "+--------------+" << endl;
		cout << "|--EDIT MENU-- |" << endl;
		cout << "+--------------+" << endl;
		cout << "|1. name       |" << endl;
		cout << "|2. description|" << endl;
		cout << "|3.frontend    |" << endl;
		cout << "|4.backend     |" << endl;
		cout << "|5.QA          |" << endl;
		cout << "|6.master      |" << endl;
		cout << "|7.teacher     |" << endl;
		cout << "+--------------+" << endl;
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
		switch (choice)
		{

		case 1:
			system("CLS");
			cout << " Choose a new team name : ";
			cin >> editName.teamName;
			updateTeam(teams, teamCount, editedId, editName);
			break;

		case 2:
			system("CLS");
			cout << "Choose a new team description: ";
			cin >> editName.teamDescription;
			updateTeam(teams, teamCount, editedId, editName);
			break;
		case 3:
			if (checkAvailableStudents(students, studentCount, "frontend"))
			{
				system("CLS");
				showStudentsPerRole(students, studentCount, "frontend");
				editName.frontEnd.hasTeam = false;
				updateStudent(students, studentCount, editName.frontEnd.studentID, editName.frontEnd);
				cout << "which ID?";
				int frontEndID;
				cin >> frontEndID;
				STUDENTS frontend = getStudent(students, studentCount, frontEndID);
				frontend.hasTeam = true;
				updateStudent(students, studentCount, frontEndID, frontend);
				editName.frontEnd = frontend;
				updateTeam(teams, teamCount, editedId, editName);
			}
			break;
		case 4:
			if (checkAvailableStudents(students, studentCount, "backend"))
			{
				system("CLS");
				cout << "Which back-end developer is in the team?";
				showStudentsPerRole(students, studentCount, "backend");
				editName.backEnd.hasTeam = false;
				updateStudent(students, studentCount, editName.backEnd.studentID, editName.backEnd);
				cout << "which ID?";
				int backEndID;
				cin >> backEndID;
				STUDENTS backend = getStudent(students, studentCount, backEndID);
				backend.hasTeam = true;
				updateStudent(students, studentCount, backEndID, backend);
				editName.backEnd = backend;
				updateTeam(teams, teamCount, editedId, editName);
			}
			break;
		case 5:
			if (checkAvailableStudents(students, studentCount, "QA"))
			{
				system("CLS");
				cout << "Which quality engineer is in the team?";
				showStudentsPerRole(students, studentCount, "QA");
				editName.QA.hasTeam = false;
				updateStudent(students, studentCount, editName.QA.studentID, editName.QA);
				cout << "which ID?";
				int QAID;
				cin >> QAID;
				STUDENTS qa = getStudent(students, studentCount, QAID);
				qa.hasTeam = true;
				updateStudent(students, studentCount, QAID, qa);
				editName.QA = qa;
				updateTeam(teams, teamCount, editedId, editName);
			}
			break;
		case 6:
			if (checkAvailableStudents(students, studentCount, "master"))
			{
				system("CLS");
				cout << "Which scrum master is in the team?";
				showStudentsPerRole(students, studentCount, "master");
				editName.master.hasTeam = false;
				updateStudent(students, studentCount, editName.master.studentID, editName.master);
				cout << "which ID?";
				int masterID;
				cin >> masterID;
				STUDENTS master = getStudent(students, studentCount, masterID);
				master.hasTeam = true;
				updateStudent(students, studentCount, masterID, master);
				editName.master = master;
				updateTeam(teams, teamCount, editedId, editName);
			}
			break;
		case 7:
			system("CLS");
			cout << "Which teacher is in the team?";
			showTeachers(teachers, teacherCount, teams, teamCount);
			cout << "which ID?";
			int TeacherID;
			cin >> TeacherID;
			TEACHERS teach = getTeacher(teachers, teacherCount, TeacherID);
			teach.hasTeam = true;
			updateTeacher(teachers, teacherCount, TeacherID, teach);
			editName.teamTeacher = teach;
			updateTeam(teams, teamCount, editedId, editName);
			break;

		}
	}
	else
	{
		system("CLS");
		cout << "There are no teams inserted yet. " << endl << endl
			<< "You can insert some using the |Add a team| button of the menu." << endl << endl;
	}
}
bool showTeamMenu(TEAMS* teams, int& teamCount, int& maxTeamID, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount)
{

	cout << "+-----------------+" << endl;
	cout << "|--- TEAM MENU ---|" << endl;
	cout << "+-----------------+" << endl;
	cout << "|1.Show all teams |" << endl;
	cout << "|2.Add a team     |" << endl;
	cout << "|3.Edit a team    |" << endl;
	cout << "|4.Delete a team  |" << endl;
	cout << "|5.Exit Menu      |" << endl;
	cout << "+-----------------+" << endl;

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

	switch (choice)
	{
	case 1:
		showTeams(teams, teamCount);
		break;

	case 2:
		createTeamMenu(teams, teamCount, maxTeamID, teachers, teacherCount, students, studentCount);
		break;

	case 3:
		editTeamMenu(teams, teamCount, teachers, teacherCount, students, studentCount);
		break;
	case 4:
		deleteTeamMenu(teams, teamCount, students, studentCount, teachers, teacherCount);
		break;
	case 5:
		return false;

	default: break;
		system("CLS");
		cout << "The number you choose was not valid!" << endl;
	}

	return true;
}

void createSchoolMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount, TEAMS* teams, int& teamCount)
{
	system("CLS");
	SCHOOLS addSchool;

	cout << " name  ";
	cin >> addSchool.schoolName;

	cout << "city ";
	cin >> addSchool.city;

	cout << "address";
	cin >> addSchool.address;
	system("CLS");
	int availableStudents = showStudentsNoSchool(students, studentCount);
	if (availableStudents > 0)
	{
		cout << "how many of them study in this school?";
		cin >> addSchool.studentsInSchoolNum;
		if (addSchool.studentsInSchoolNum < 0 or addSchool.studentsInSchoolNum > availableStudents)
		{
			do {
				cout << "invalid number, try again" << endl;
				cin >> addSchool.studentsInSchoolNum;
			} while (addSchool.studentsInSchoolNum < 0 or addSchool.studentsInSchoolNum > availableStudents);
		}
		showStudentsNoSchool(students, studentCount);
		for (int i = 0; i < addSchool.studentsInSchoolNum; i++)
		{
			cout << "which ID?";
			int editedId;
			cin >> editedId;
			STUDENTS tt = getStudent(students, studentCount, editedId);
			tt.hasSchool = true;
			updateStudent(students, studentCount, editedId, tt);
			addSchool.studentsInSchool[i] = tt;
		}
	}
	system("CLS");
	int availableTeachers = showTeachersNoSchool(teachers, teacherCount, teams, teamCount);
	if (availableTeachers > 0)
	{
		cout << "how many of them teach in this school?";
		cin >> addSchool.teachersInSchoolNum;
		if (addSchool.teachersInSchoolNum < 0 or addSchool.teachersInSchoolNum > availableStudents)
		{
			do {
				cout << "invalid number, try again" << endl;
				cin >> addSchool.teachersInSchoolNum;
			} while (addSchool.teachersInSchoolNum < 0 or addSchool.teachersInSchoolNum > availableStudents);
		}
		for (int i = 0; i < addSchool.teachersInSchoolNum; i++)
		{
			cout << "which ID?";
			int editedId2;
			cin >> editedId2;

			TEACHERS tt = getTeacher(teachers, teacherCount, editedId2);
			tt.hasSchool = true;
			updateTeacher(teachers, teacherCount, editedId2, tt);
			addSchool.teachersInSchool[i] = tt;
		}
	}
	system("CLS");
	int availableTeams = showTeamsNoSchool(teams, teamCount);
	if (availableTeams > 0)
	{
		cout << "how many teams learn in this school?";
		cin >> addSchool.teamsInSchoolNum;
		for (int i = 0; i < addSchool.teamsInSchoolNum; i++)
		{
			cout << "which ID?";
			int editedId3;
			cin >> editedId3;

			TEAMS tt = getTeam(teams, teamCount, editedId3);
			tt.hasSchool = true;
			updateTeam(teams, teamCount, editedId3, tt);
			addSchool.teamsInSchool[i] = tt;
		}
	}
	system("CLS");
	createSchool(schools, schoolCount, maxSchoolID, addSchool);
}


void showSchools(SCHOOLS* schools, int& schoolCount)
{
	system("CLS");
	if (schoolCount > 0)
	{
		cout << "Here are all the schools so far : " << endl;
	}
	else
	{
		cout << "There are no schools inserted yet. " << endl << endl
			<< "You can insert some using the |Add a school| button of the menu." << endl << endl;
	}
	for (int j = 0; j < schoolCount; j++)
	{
		cout << "ID : ";
		cout << schools[j].schoolID << " | Name : "
			<< schools[j].schoolName << " | City : "
			<< schools[j].city << " | address: "
			<< schools[j].address << " | teachers :";
		cout << endl;
		cout << "+--------+" << endl;
		cout << "|Students|" << endl;
		cout << "+--------+" << endl;
		cout << endl;
		for (int i = 0; i < schools[j].studentsInSchoolNum; i++)
		{
			cout << "ID : ";
			cout << schools[j].studentsInSchool[i].studentID << " | Name : "
				<< schools[j].studentsInSchool[i].name << " | surname : "
				<< schools[j].studentsInSchool[i].surname << " | class: "
				<< schools[j].studentsInSchool[i].studentClass << " | role: "
				<< schools[j].studentsInSchool[i].role << " | email: "
				<< schools[j].studentsInSchool[i].email;
			cout << endl;
		}
		cout << endl;
		cout << "+--------+" << endl;
		cout << "|Teachers|" << endl;
		cout << "+--------+" << endl;
		cout << endl;
		for (int i = 0; i < schools[j].teachersInSchoolNum; i++)
		{
			cout << "ID : ";
			cout << schools[j].teachersInSchool[i].teacherID << " | Name : "
				<< schools[j].teachersInSchool[i].teacherName << " | Subname : "
				<< schools[j].teachersInSchool[i].teacherSubname << " | email: "
				<< schools[j].teachersInSchool[i].teacherEmail;
			cout << endl;
		}
		cout << endl;
		cout << "+--------+" << endl;
		cout << "| Teams  |" << endl;
		cout << "+--------+" << endl;
		cout << endl;
		for (int i = 0; i < schools[j].teamsInSchoolNum; i++)
		{
			cout << "ID : ";
			cout << schools[j].teamsInSchool[i].teamID << " | Name : "
				<< schools[j].teamsInSchool[i].teamName << " | Description : "
				<< schools[j].teamsInSchool[i].teamDescription << " | teacher: "
				<< schools[j].teamsInSchool[i].teamTeacher.teacherName;
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

void deleteSchoolMenu(SCHOOLS* schools, int& schoolCount, STUDENTS* students, int& studentCount, TEACHERS* teachers, int& teacherCount, TEAMS* teams, int& teamCount)
{
	system("CLS");
	if (schoolCount > 0)
	{
		int deleteSchoolID;
		cout << "Enter the Id of the school you want to delete : ";
		cin >> deleteSchoolID;
		deleteSchool(schools, schoolCount, deleteSchoolID, students, studentCount, teachers, teacherCount, teams, teamCount);
	}
	else
	{
		cout << "There are no schools inserted yet. " << endl << endl
			<< "You can insert some using the |Add a school| button of the menu." << endl << endl;
	}
}

void editSchoolMenu(SCHOOLS* schools, int& schoolCount, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount, TEAMS* teams, int& teamCount)
{
	system("CLS");
	if (schoolCount > 0)
	{
		int editedId;
		cout << "Enter the ID of the school you want to change : ";
		cin >> editedId;

		SCHOOLS editSchool = getSchool(schools, schoolCount, editedId);
		cout << "+--------------+" << endl;
		cout << "|1.edit name   |" << endl;
		cout << "|2.edit city   |" << endl;
		cout << "|3.edit address|" << endl;
		cout << "|4.Add people  |" << endl;
		cout << "+--------------+" << endl;
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
		switch (choice)
		{
		case 1:
			system("CLS");
			cout << " Choose a new school name : ";
			cin >> editSchool.schoolName;
			updateSchool(schools, schoolCount, editedId, editSchool);
			break;

		case 2:
			system("CLS");
			cout << "Choose a new school city: ";
			cin >> editSchool.city;
			updateSchool(schools, schoolCount, editedId, editSchool);
			break;

		case 3:
			system("CLS");
			cout << "Choose  a new school address : ";
			cin >> editSchool.address;
			updateSchool(schools, schoolCount, editedId, editSchool);
			break;
		case 4:
			addPeopleMenu(schools, schoolCount, teachers, teacherCount, students, studentCount, teams, teamCount, editedId);
			break;
		default:
			cout << "The number you choose was not valid!" << endl;
			break;
		}
	}
	else
	{
		cout << "There are no schools inserted yet. " << endl << endl
			<< "You can insert some using the |Add a school| button of the menu." << endl << endl;
	}
}
bool showSchoolMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount, TEAMS* teams, int& teamCount)
{
	cout << "+-------------------+" << endl;
	cout << "|--- SCHOOL MENU ---|" << endl;
	cout << "+-------------------+" << endl;
	cout << "|1. Show all schools|" << endl;
	cout << "|2. Add a school    |" << endl;
	cout << "|3. Edit a school   |" << endl;
	cout << "|4. Delete a school |" << endl;
	cout << "|5. Exit menu       |" << endl;
	cout << "+-------------------+" << endl;
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
	switch (choice)
	{
	case 1:
		showSchools(schools, schoolCount);
		break;

	case 2:
		createSchoolMenu(schools, schoolCount, maxSchoolID, teachers, teacherCount, students, studentCount, teams, teamCount);
		break;

	case 3:
		editSchoolMenu(schools, schoolCount, teachers, teacherCount, students, studentCount, teams, teamCount);
		break;

	case 4:
		deleteSchoolMenu(schools, schoolCount, students, studentCount, teachers, teacherCount, teams, teamCount);
		break;
	case 5:
		return false;

	default: break;
		cout << "The number you choose was not valid!" << endl;
	}
	return true;
}

void showStudentsNoTeam(STUDENTS* students, int& studentCount)
{
	system("CLS");
	if (studentCount > 0)
	{
		for (int j = 0; j < studentCount; j++)
		{
			if (students[j].hasTeam == false)
			{
				cout << "ID : ";
				cout << students[j].studentID << " | Name : "
					<< students[j].name << " | surname : "
					<< students[j].surname << " | class: "
					<< students[j].studentClass << " | role: "
					<< students[j].role << " | email: "
					<< students[j].email << endl;
			}
		}
		cout << endl;
	}
	else
	{
		cout << "There are no students inserted yet. " << endl << endl
			<< "You can insert some using the |Add student| button of the menu." << endl << endl;
	}
}
void showteachersNoTeam(TEACHERS* teachers, int& teacherCount)
{
	system("CLS");
	if (teacherCount > 0)
	{
		for (int j = 0; j < teacherCount; j++)
		{
			if (teachers[j].hasTeam == false)
			{
				cout << "ID : ";
				cout << teachers[j].teacherID << " | Name : "
					<< teachers[j].teacherName << " | Subname : "
					<< teachers[j].teacherSubname << " | email: "
					<< teachers[j].teacherEmail << endl;
			}
		}
		cout << endl;
	}
	else
	{
		cout << "There are no teachers inserted yet" << endl << endl;
		cout << "You can insert some using the |Add teacher| button of the menu." << endl << endl;
	}
}

bool showReportsMenu(SCHOOLS* schools, int& schoolCount, TEACHERS* teachers, int& teacherCount, STUDENTS* students, int& studentCount, TEAMS* teams, int& teamCount)
{
	cout << " --- REPORTS MENU ---" << endl;
	cout << "1. Students without teams" << endl;
	cout << "2. Teachers without a team" << endl;
	cout << "3. Students without a school" << endl;
	cout << "4. Teachers without a school" << endl;
	cout << "5. Teams without a school" << endl;
	cout << "6. Exit menu" << endl;
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
	switch (choice)
	{
	case 1:
		system("CLS");
		showStudentsNoTeam(students, studentCount);
		break;
	case 2:
		system("CLS");
		showteachersNoTeam(teachers, teacherCount);
		break;
	case 3:
		system("CLS");
		showStudentsNoSchool(students, studentCount);
		break;
	case 4:
		system("CLS");
		showTeachersNoSchool(teachers, teacherCount, teams, teamCount);
		break;
	case 5:
		system("CLS");
		showTeamsNoSchool(teams, teamCount);
		break;
	case 6:
		return false;
		break;
	}
	return true;
}

bool mainMenu(SCHOOLS* schools, int& schoolCount, int& maxSchoolID, TEACHERS* teachers, int& teacherCount, int& maxTeacherID, STUDENTS* students, int& studentCount, int& maxStudentID, TEAMS* teams, int& teamCount, int& maxTeamID)
{
	system("CLS");
	cout << "+-------------------+" << endl;
	cout << "|--- MAIN   MENU ---|" << endl;
	cout << "+-------------------+" << endl;
	cout << "|1. students        |" << endl;
	cout << "|2. teachers        |" << endl;
	cout << "|3. teams           |" << endl;
	cout << "|4. schools         |" << endl;
	cout << "|5. show the reports|" << endl;
	cout << "|6. exit            |" << endl;
	cout << "+-------------------+" << endl;
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
	bool doShowMenu;
	switch (choice)
	{
	case 1:
		system("CLS");
		do {
			doShowMenu = showStudentMenu(students, studentCount, maxStudentID);
		} while (doShowMenu);
		break;
	case 2:
		system("CLS");
		do {
			doShowMenu = showTeacherMenu(teachers, teacherCount, maxTeacherID, teams, teamCount);
		} while (doShowMenu);
		break;

	case 3:
		system("CLS");
		do {
			doShowMenu = showTeamMenu(teams, teamCount, maxTeamID, teachers, teacherCount, students, studentCount);
		} while (doShowMenu);
		break;

	case 4:
		system("CLS");
		do {
			doShowMenu = showSchoolMenu(schools, schoolCount, maxSchoolID, teachers, teacherCount, students, studentCount, teams, teamCount);
		} while (doShowMenu);
		break;
	case 5:
		system("CLS");
		do {
			doShowMenu = showReportsMenu(schools, schoolCount, teachers, teacherCount, students, studentCount, teams, teamCount);
		} while (doShowMenu);
		break;
	case 6:
		return false;

	default:
		break;
		cout << "The number you choose was not valid!" << endl;
	}

	return true;
}
