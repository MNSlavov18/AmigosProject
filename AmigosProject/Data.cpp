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
