#pragma once
#include <string>
#include <ctype.h>
#include <ctype.h>
#include "Date.h"

class Student
{
private:
	std::string s_ID;
	std::string s_FirstName;
	std::string s_LastName;
	std::string s_class;
	Date s_DOB;
public:
	Student(): s_ID("A0000"), s_FirstName("An"), s_LastName("Nguyen Van"), s_class("IS332") {};
	void Import();

	bool ProcessID(const std::string& p_id);
	bool ProcessFirstName(const std::string& p_name);
	bool ProcessLastName(const std::string& p_name);
	bool ProcessClass(const std::string& p_class);

	bool InputID();
	bool InputFN();
	bool InputLN();
	bool InputCL();


	bool CheckStringName(const std::string& p_name);
	const std::string& GetFirstName() const { return s_FirstName; };
	const std::string& GetLastName() const { return s_LastName; };
	const std::string& GetClass() const { return s_class; };
	const Date& GetDoB() const { return s_DOB; };
	const std::string& GetID() const { return s_ID; };
	const std::string& ExportStudentInfo() const { std::string result = GetID() + " " /*+ GetLastName() + " " + GetFirstName() + " " + GetDoB().GetDateString() + " " + GetClass()*/; return result; }

	bool operator<(const Student& b);

	void PrintStudentInfo() const;

	void FlushCin();
};