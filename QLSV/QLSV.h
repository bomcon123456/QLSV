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
	void PrintList();

	void SortList();
	bool Check_IDNotOverlap(const std::string& id);

	void ImportFromFile(const std::string& filePath);
	void ExportToFile(const std::string& filePath);

	// return shit.
	Student back();
	size_t size();

};