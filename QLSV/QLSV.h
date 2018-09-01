#pragma once
#include <vector>
#include "Student.h"

class QLSV
{
private:
	std::vector<Student> StudentList;
public:
	QLSV() {};

	void Import();
	unsigned int size();

	bool Check_IDOverlap(const std::string& id);

	Student back();

};