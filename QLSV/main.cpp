#include <iostream>
#include <stdlib.h>

//#include <vector>
//#include "Date.h"
//#include "Student.h"
#include "QLSV.h"
#include "myLib.h"

int main()
{
	QLSV test;
	int choose;
	char f;
	do
	{
	InitialScreen(choose);
	switch (choose)
	{
		case 1:
		{
			system("cls");
			test.PrintList();
			break;
		}
		case 2:
		{
			int n;
			system("cls");
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
		{
			std::cout << "LEL" << std::endl;
			break;
		}
	}
	std::cout << "Do you want to go to main screen (y/n)? ";
	FlushCin();
	std::cin >> f;
	if (f != 'y')
		break;
	} while (f == 'y');
	//Student test;
	//test.Import();
	//test.PrintStudentInfo();


	system("pause");
	return 1;

}