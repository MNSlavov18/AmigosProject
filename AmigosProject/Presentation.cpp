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