#include "Student.h"

bool myIsDigit(const std::string& teststr);

void Student::Import()
{
	while (!ProcessID());
	while (!ProcessFirstName());
	while (!ProcessLastName());
	while (!s_DOB.Import());
	while (!ProcessClass());
	return;
}

bool Student::ProcessID()
{
	std::string id;
	std::cout << "Please enter Student's ID: ";
	FlushCin();
	std::cin >> id;
	if (id.length() != 6 || id[0] != 'A')
	{
		std::cout << "Wrong Student ID Pattern." << std::endl;
		return false;
	}
	for (int i = 1; i <= 5; i++)
	{
		if (!isdigit(id[i]))
		{
			std::cout << "Wrong Student ID Pattern." << std::endl;
			return false;
		};
	}
	 
	s_ID = id;
	return true;
}

bool Student::ProcessFirstName()
{
	std::string p_name;
	std::cout << "Please enter Student's First name: ";
	FlushCin();
	std::getline(std::cin, p_name);
	if (!CheckStringName(p_name))
		return false;
	s_FirstName = p_name;
	return true;
}

bool Student::ProcessLastName()
{
	std::string p_name;
	std::cout << "Please enter Student's Last name: ";
	FlushCin();
	std::getline(std::cin, p_name);
	if (!CheckStringName(p_name))
		return false;
	s_LastName = p_name;
	return true;
}

bool Student::ProcessClass()
{
	std::string p_class;
	std::cout << "Please enter Student's class:";
	FlushCin();
	std::cin >> p_class;
	if (p_class.length()!=4 || myIsDigit(p_class.substr(0,2)) || !myIsDigit(p_class.substr(2,2)))
	{
		std::cout << "Wrong Class Pattern" << std::endl;
		return false;
	}

	s_class = p_class;
	return true;
}

void Student::PrintStudentInfo() const
{
	std::cout << "Student name:" << s_LastName << " " << s_FirstName << std::endl;
	std::cout << "Student ID:" << s_ID << std::endl;
	std::cout << "Student DoB:"; 
	s_DOB.PrintDate();
	std::cout << "Student Class:" << s_class << std::endl;
}

void Student::FlushCin()
{
	std::cin.seekg(0, std::ios::end);
	std::cin.clear();
}

////////////////////////////////////////////// CHECK
bool myIsDigit(const std::string& teststr)
{
	bool flag = false;
	for (size_t i = 0; i < teststr.length(); i++)
	{
		if (isdigit(teststr[i]))
			flag = true;
		else
			flag = false;
	}
	return flag;
}

bool Student::CheckStringName(const std::string& p_name)
{
	bool flag;
	for (int i=0;i<p_name.size();i++)
	{
		if (isdigit(p_name[i]))
		{
			std::cout << "Name should not have number." << std::endl;
			return false;
		}
		if ((p_name[i] >= 65 && p_name[i] <= 90) || (p_name[i] >= 97 && p_name[i] <= 122) || p_name[i] == 32)
		{
			flag = true;
		}
		else
		{
			std::cout << "Name should not have weird character." << std::endl;
			return false;
		}
	}
	return flag;
}