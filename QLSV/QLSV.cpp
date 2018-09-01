#include "QLSV.h"

void QLSV::Import()
{
	Student test;
	test.Import();
	if (Check_IDOverlap(test.GetID()))
	{
		StudentList.push_back(test);
		std::cout << "Sucessfully imported " << StudentList.back().GetFirstName() << std::endl;
	}
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
