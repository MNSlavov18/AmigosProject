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