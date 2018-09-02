#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "vendor/VariadicTable.h"

class QLSV
{
private:
	std::vector<Student> StudentList;
public:
	QLSV() {};

	void Import();
	//void ImportFromFile(const std::string& filePath);
	void PrintList();

	void SortList();

	bool Check_IDOverlap(const std::string& id);

	// return shit.
	Student back();
	unsigned int size();

};