#include "QLSV.h"

bool myComparision(Student a, Student b) { return (a < b); }

void QLSV::Import()
{
	Student test;
	test.Import();
	if (Check_IDOverlap(test.GetID()))
	{
		StudentList.push_back(test);
		std::cout << "Sucessfully imported " << StudentList.back().GetFirstName() << std::endl;
		SortList();
	}
}

//void QLSV::ImportFromFile(const std::string& filePath)
//{
//	std::stringstream ss;
//	std::string line;
//	std::ifstream file(filePath);
//	while (getline(ss, line))
//	{
//		ss << line;
//		std::cout << line << std::endl;
//	}
//
//	file.close();
//}

void QLSV::PrintList()
{
	for (auto it = StudentList.begin(); it != StudentList.end(); ++it)
	{
		(&(*it))->PrintStudentInfo();
	}
	return;
}

void QLSV::SortList()
{
	std::sort(StudentList.begin(), StudentList.end(), myComparision);
}

unsigned int QLSV::size()
{
	return StudentList.size();
}

bool QLSV::Check_IDOverlap(const std::string& id)
{
	bool flag=true;
	for (std::vector<Student>::iterator it = StudentList.begin(); it != StudentList.end(); ++it)
	{
		Student& iterator = *it;
		if (iterator.GetID() == id)
		{
			flag = false;
		}
	}
	if(!flag)
		std::cout << "This Student ID already in the list." << std::endl;
	return flag;
}

Student QLSV::back()
{
	return StudentList.back();
}
