#include <iostream>
//#include <vector>
//#include "Date.h"
//#include "Student.h"
#include "QLSV.h"

int main()
{
	QLSV test;
	int choose;
	std::cout << "IS332 Student Manager" << std::endl;
	std::cout << "1. Student list" << std::endl;
	std::cout << "2. Add student" << std::endl;
	std::cout << "3. Delete student" << std::endl;
	std::cout << "4. Find student" << std::endl;
	std::cout << "Your choice: ";
	std::cin >> choose;
	switch (choose)
	{
		case 2:
		{
			int n;
			std::cout << "Welcome to add student management function" << std::endl;
			std::cout << "How many student do you want to add: ";
			std::cin >> n;
			for (int i = 0; i < n; i++)
			{
				test.Import();
			}
			std::cout << "Currently Student List has " << test.size() << " student." << std::endl;
			break;
		}
		default:
			std::cout << "LEL" << std::endl;
			break;
	}

	//Student test;
	//test.Import();
	//test.PrintStudentInfo();


	system("pause");
	return 1;

}