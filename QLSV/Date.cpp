#include "Date.h"
#include <cstdlib>

bool Date::Import()
{
	std::string input;
	std::cout << "Please enter date of birth (dd/mm/yyyy): ";
	std::cin >> input;
	return ProcessString(input);
}

bool Date::ProcessString(const std::string& datestr)
{
	std::string string = datestr;
	if (datestr.length() != 10 || datestr[2] != datestr[5] || datestr[2] != '/')
	{
		std::cout << "Please input like the pattern you see." << std::endl;
		return false;
	}
	int d = atoi(string.substr(0, 2).c_str());
	int m = atoi(string.substr(3, 2).c_str());
	int y = atoi(string.substr(6, 4).c_str());
	if (m < 1 || m>12)
	{
		std::cout << "Please input like the pattern you see." << std::endl;
		return false;
	}
	int threshold = 0;

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		threshold = 31;
	}
	else if (m == 2)
	{
		threshold = 28;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		threshold = 28;
	}

	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0) && m == 2)
	{
		threshold = 29;
	}

	if (d > threshold || d < 1)
	{
		std::cout << "Please input like the pattern you see." << std::endl;
		return false;
	}

	day = d;
	month = m;
	year = y;
	datestring = datestr;

	return true;
}

void Date::PrintDate() const
{
	std::cout << datestring << std::endl;
}

