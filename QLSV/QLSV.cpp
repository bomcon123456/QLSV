#include "QLSV.h"

bool myComparision(Student a, Student b) { return (a < b); }

void QLSV::Import()
{
	Student test;
	while(!test.InputID());
	Check_ImportNewStudentAndSort(test,true);
	//test.Import();
	//if (Check_IDNotOverlap(test.GetID()))
	//{
	//	StudentList.push_back(test);
	//	std::cout << "Sucessfully imported " << StudentList.back().GetFirstName() << std::endl;
	//	SortList();
	//}
}

void QLSV::Check_ImportNewStudentAndSort(Student &test,bool bPrint)
{
	if (Check_IDNotOverlap(test.GetID()))
	{
		test.Import();
		StudentList.push_back(test);
		if(bPrint)
			std::cout << "Sucessfully imported " << StudentList.back().GetFirstName() << std::endl;
		SortList();
	}
}

void QLSV::Check_NewStudentAndSort(Student &test, bool bPrint)
{
	if (Check_IDNotOverlap(test.GetID()))
	{
		StudentList.push_back(test);
		if(bPrint)
			std::cout << "Sucessfully imported " << StudentList.back().GetFirstName() << std::endl;
		SortList();
	}
}

void QLSV::PrintList()
{
	//for (auto it = StudentList.begin(); it != StudentList.end(); ++it)
	//{
	//	(&(*it))->PrintStudentInfo();
	//}
	//return;
	//MSV----Last name----First Name ----Birthday-----Class----
	int index = 1;
	VariadicTable<int, std::string, std::string, std::string, std::string, std::string> vt({ "Index", "ID", "Last name", "First name", "DoB", "Class" });
	for (auto it = StudentList.begin(); it != StudentList.end(); ++it)
	{
		Student stu = *it;
		std::string id, ln, fn, dob, cl;
		id = stu.GetID();
		ln = stu.GetLastName();
		fn = stu.GetFirstName();
		dob = stu.GetDoB().GetDateString();
		cl = stu.GetClass();
		//	vt.addRow({ stu.GetID(), stu.GetLastName(), stu.GetFirstName(), stu.GetDoB(), stu.GetClass() });
		vt.addRow({ index, id, ln, fn, dob, cl });
		index++;
	}

	vt.print(std::cout);
}

Student QLSV::GetStudent(int index)
{
	if (index <= size())
	{
		return StudentList[index-1];
	}
	std::cout << "Invalid position to fix." << std::endl;
	return Student();
	
}

bool QLSV::DeleteStudent(int index)
{
	if (index <= size())
	{
		StudentList.erase(StudentList.begin() + (index - 1));
		return true;
	}
	else
	{
		std::cout << "Invalid position to delete." << std::endl;
		return false;
	}
}

void QLSV::SortList()
{
	std::sort(StudentList.begin(), StudentList.end(), myComparision);
}

size_t QLSV::size()
{
	return StudentList.size();
}

bool QLSV::Check_IDNotOverlap(const std::string& id)
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

void QLSV::ExportToFile(const std::string& filePath)
{
	std::ofstream myfile(filePath);
	for (std::vector<Student>::iterator it = StudentList.begin(); it != StudentList.end(); ++it)
	{
		Student stu = *it;
		myfile << stu.GetID() << "\n" << stu.GetLastName() << "\n" << stu.GetFirstName() 
			<< "\n" << stu.GetDoB().GetDateString() << "\n" << stu.GetClass();
		myfile << "\n";
	}
	myfile.close();
}

void QLSV::ImportFromFile(const std::string& filePath)
{
	std::stringstream ss;
	std::string line;
	std::ifstream file;
	file.open(filePath);
	if (file.is_open())
	{
		int i=0;
		std::string id, ln, fn, dob, cl;
		while (((getline(file,line))))
		{
			switch (i)
			{
			case 0:
			{
				std::cout << "ID: " << line << std::endl;
				id = line;
				break;
			}
			case 1:
			{
				std::cout << "LN: " << line << std::endl;
				ln = line;
				break;
			}
			case 2:
			{
				std::cout << "FN: " << line << std::endl;
				fn = line;
				break;
			}
			case 3:
			{
				std::cout << "DoB: " << line << std::endl;
				dob = line;
				break;
			}
			case 4:
			{
				std::cout << "CL: " << line << std::endl;
				cl = line;
				break;
			}
			}
			if (i < 4)
				++i;
			else
			{
				Student importStu(id, ln, fn, dob, cl);
				Check_NewStudentAndSort(importStu, true);
				i = 0;
			}
		}
		file.close();
	}
	return;
}

Student QLSV::back()
{
	return StudentList.back();
}
