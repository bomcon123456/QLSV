#pragma once
#include <string>
#include <ctype.h>
#include <limits>
#include "Date.h"

class Student
{
private:
	std::string s_ID;
	std::string s_name;
	std::string s_FirstName;
	std::string s_LastName;
	std::string s_class;
	Date s_DOB;
public:
	Student(): s_ID("A0000"), s_FirstName("An"), s_LastName("Nguyen Van"), s_class("IS332") {};
	void Import();

	bool ProcessID();
	bool ProcessName();
	bool ProcessFirstName();
	bool ProcessLastName();
	bool ProcessClass();

	bool CheckStringName(const std::string& p_name);

	void PrintStudentInfo() const;

	void FlushCin();
};