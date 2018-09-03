#pragma once
#include <iostream>
#include <string>

class Date
{
private:
	int day, month, year;
	std::string datestring;
public:
	Date() : day(1), month(1), year(1) {};
	Date(int d, int m, int y) : day(d), month(m), year(y) {};
	bool Import();
	bool ProcessString(const std::string& datestr);

	int GetYear() const { return year; }
	int GetMonth() const { return month; }
	void PrintDate() const;
	std::string GetDateString() const { return datestring; }
};