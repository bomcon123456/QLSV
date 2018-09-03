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
		case 3:
		{
			system("cls");
			test.PrintList();
			int n=0;
			if (test.size() == 0)
			{
				std::cout << "There isn't any student to fix yet." << std::endl;
				break;
			}
			std::cout << "Which student you want to delete? : ";
			std::cin >> n;
			if(test.DeleteStudent(n))
			{
				std::cout << "Deletion Complete. List currently has " << test.size() << " students." << std::endl;
				test.PrintList();
			}
			break;
		}
		case 4:
		{
			system("cls");
			test.PrintList();
			int n = 0;
			if (test.size() == 0)
			{
				std::cout << "There isn't any student to fix yet." << std::endl;
				break;
			}
			std::cout << "Which student you want to fix information? : ";
			std::cin >> n;
			Student fixStu = test.GetStudent(n);
			test.DeleteStudent(n);
			std::cout << "1. ID" << std::endl;
			std::cout << "2. Last name" << std::endl;
			std::cout << "3. First name" << std::endl;
			std::cout << "4. Date of Birth" << std::endl;
			std::cout << "5. Class" << std::endl;
			std::cout << "6. All" << std::endl;
			std::cout << "Which information you want to fix? : ";
			std::cin >> n;
			switch (n)
			{
			case 1:
			{
				std::string tempID = fixStu.GetID();
				if (fixStu.InputID())
				{
					if (!test.Check_IDNotOverlap(fixStu.GetID()))
					{
						std::cout << "This ID's already in the list, can't add." << std::endl;
						fixStu.ProcessID(tempID);
					}
					test.Check_NewStudentAndSort(fixStu, false);
				}

				std::cout << "Result: " << std::endl;
				test.PrintList();
				break;
			}
			case 2:
			{
				fixStu.InputLN();
				break;
			}
			case 3:
			{
				fixStu.InputFN();
				break;
			}	
			case 4:
			{
				fixStu.InputDOB();
				break;
			}
			case 5:
			{
				fixStu.InputCL();
				break;
			}
			case 6:
			{
				fixStu.Import();
				break;
			}
			default:
			{
				std::cout << "You should not be here." << std::endl;
				break;
			}
			}
			break;
		}
		case 6:
		{
			system("cls");
			std::string filePath;
			std::cout << "Please insert file name to export: ";
			std::cin >> filePath;
			test.ExportToFile(filePath);
			break;
		}
		case 7:
		{
			system("cls");
			std::string filePath;
			std::cout << "Please insert file name to export: ";
			std::cin >> filePath;
			test.ImportFromFile(filePath);
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