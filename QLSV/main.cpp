#include <iostream>
#include <vector>
#include "Date.h"
#include "Student.h"

int main()
{
	//int choose;
	//std::cout << "IS332 Student Manager" << std::endl;
	//std::cout << "1. Student list" << std::endl;
	//std::cout << "2. Add student" << std::endl;
	//std::cout << "3. Delete student" << std::endl;
	//std::cout << "4. Find student" << std::endl;
	//std::cin >> choose;
	Student test;
	test.Import();
	test.PrintStudentInfo();

	system("pause");
	return 1;

}