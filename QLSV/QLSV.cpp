#include "QLSV.h"

bool myComparision(Student a, Student b) { return (a < b); }

bool QLSV::Import(bool bPrint)
{
	Student test;
	while(!test.InputID());
	return Check_ImportNewStudentAndSort(test, bPrint);
	//test.Import();
	//if (Check_IDNotOverlap(test.GetID()))
	//{
	//	StudentList.push_back(test);
	//	std::cout << "Sucessfully imported " << StudentList.back().GetFirstName() << std::endl;
	//	SortList();
	//}
}

bool QLSV::Check_ImportNewStudentAndSort(Student &test,bool bPrint)
{
	if (Check_IDNotOverlap(test.GetID()))
	{
		test.Import();
		StudentList.push_back(test);
		if (bPrint)
			std::cout << "Sucessfully imported " << StudentList.back().GetFirstName() << std::endl;
		SortList();
		return true;
	}
	else
		return false;
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
	if ((size_t)index <= size())
	{
		return StudentList[index-1];
	}
	std::cout << "Invalid position to fix." << std::endl;
	return Student();
	
}

bool QLSV::DeleteStudent(int index)
{
	if ((size_t)index <= size())
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

void QLSV::Find_IDFilter(const std::string& filter)
{
	unsigned int counter=0;
	for (auto it = StudentList.begin(); it != StudentList.end(); ++it)
	{
		Student stu = *it;
		if (stu.GetID().find(filter) != std::string::npos)
		{
			stu.PrintStudentInfo();
			counter++;
		}
	}
	if (counter == 0)
	{
		std::cout << "Can't find any student with that filter." << std::endl;
	}
}

void QLSV::Find_FNFilter(const std::string& filter)
{
	unsigned int counter = 0;
	for (auto it = StudentList.begin(); it != StudentList.end(); ++it)
	{
		Student stu = *it;
		if (stu.GetFirstName().find(filter) != std::string::npos)
		{
			stu.PrintStudentInfo();
			counter++;
		}
	}
	if (counter == 0)
	{
		std::cout << "Can't find any student with that filter." << std::endl;
	}
}

void QLSV::Find_LNFilter(const std::string& filter)
{
	unsigned int counter = 0;
	for (auto it = StudentList.begin(); it != StudentList.end(); ++it)
	{
		Student stu = *it;
		if (stu.GetLastName().find(filter) != std::string::npos)
		{
			stu.PrintStudentInfo();
			counter++;
		}
	}
	if (counter == 0)
	{
		std::cout << "Can't find any student with that filter." << std::endl;
	}
}

void QLSV::Find_YearFilter(const int& filter)
{
	unsigned int counter = 0;
	for (auto it = StudentList.begin(); it != StudentList.end(); ++it)
	{
		Student stu = *it;
		if (stu.GetDoB().GetYear() == filter)
		{
			stu.PrintStudentInfo();
			counter++;
		}
	}
	if (counter == 0)
	{
		std::cout << "Can't find any student with that filter." << std::endl;
	}
}

void QLSV::Find_MonthFilter(const int& filter)
{
	unsigned int counter = 0;
	for (auto it = StudentList.begin(); it != StudentList.end(); ++it)
	{
		Student stu = *it;
		if (stu.GetDoB().GetMonth() == filter)
		{
			stu.PrintStudentInfo();
			counter++;
		}
	}
	if (counter == 0)
	{
		std::cout << "Can't find any student with that filter." << std::endl;
	}
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

void QLSV::ExportToCSV(const std::string& filePath)
{
	std::ofstream myfile(filePath);
	for (std::vector<Student>::iterator it = StudentList.begin(); it != StudentList.end(); ++it)
	{
		Student stu = *it;
		myfile << stu.GetID() << "," << stu.GetLastName() << "," << stu.GetFirstName()
			<< "," << stu.GetDoB().GetDateString() << "," << stu.GetClass();
		myfile << "\n";
	}
	myfile.close();
}

bool QLSV::ImportFromTXTFile(const std::string& filePath)
{
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
			//	std::cout << "ID: " << line << std::endl;
				id = line;
				break;
			}
			case 1:
			{
			//	std::cout << "LN: " << line << std::endl;
				ln = line;
				break;
			}
			case 2:
			{
			//	std::cout << "FN: " << line << std::endl;
				fn = line;
				break;
			}
			case 3:
			{
			//	std::cout << "DoB: " << line << std::endl;
				dob = line;
				break;
			}
			case 4:
			{
			//	std::cout << "CL: " << line << std::endl;
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
		return true;
	}
	else
		return false;
}

bool QLSV::ImportFromCSV(const std::string & filePath)
{
	std::string line;
	std::ifstream file;
	std::string id, ln, fn, dob, cl;
	int i = 0;
	file.open(filePath);
	if (!file.is_open())
	{
		std::cout << "File is not suitable, can't read." << std::endl;
		return false;
	}
	while (!std::getline(file,line,',').eof())
	{
		if (int pos = line.find_last_of('\n') != std::string::npos)
		{
			cl = line.substr(0, 4);
			Student importStu(id, ln, fn, dob, cl);
			Check_NewStudentAndSort(importStu, true);
			id = line.substr(5);
		}
		switch (i)
		{
		case 0:
		{
			id = line;
			break;
		}
		case 1:
		{
			ln = line;
			break;
		}
		case 2:
		{
			fn = line;
			break;
		}
		case 3:
		{
			dob = line;
			break;
		}
		default:
			break;
		}
		if (i < 4)
		{
			++i;
		}
		else
		{
			i = 1;
		}
	}
	std::getline(file, line);
	cl = line.substr(0,4);
	Student importStu(id, ln, fn, dob, cl);
	Check_NewStudentAndSort(importStu, true);

	file.close();
	return true;
}

Student QLSV::back()
{
	return StudentList.back();
}

size_t QLSV::size()
{
	return StudentList.size();
}
