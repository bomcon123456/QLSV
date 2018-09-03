#include <iostream>
#include <stdlib.h>
#include<chrono>
#include<thread>


//#include <vector>
//#include "Date.h"
//#include "Student.h"
#include "QLSV.h"
#include "myLib.h"

int main()
{
	QLSV test;
	std::string filePathTXT = "hs.txt";
	std::string filePathCSV = "hs.csv";
	if (test.ImportFromTXTFile(filePathTXT))
	{
		std::cout << "Successfully automatically imported " << filePathTXT << "." << std::endl;
		if(test.ImportFromCSV(filePathCSV))
			std::cout << "Successfully automatically imported " << filePathCSV << "." << std::endl;
		std::this_thread::sleep_for(std::chrono::nanoseconds(5));
		std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));

	}
	int choose;
	bool flag;
	char f;
	std::string inputstr;
	do
	{
		if (flag = InitialScreen(choose))
		{
			switch (choose)
			{
			case 1:			// Print StudentList
			{
				system("cls");
				test.PrintList();
				break;
			}
			case 2:			// Add Student
			{
				int n;
				system("cls");
				std::cout << "Welcome to add student management function" << std::endl;
				std::cout << "How many student do you want to add: ";
				std::cin >> n;
				for (int i = 0; i < n; i++)
				{
					test.Import(true);
				}
				std::cout << "Currently Student List has " << test.size() << " student." << std::endl;
				break;
			}
			case 3:			// Delete Student
			{
				system("cls");
				test.PrintList();
				int n = 0;
				if (test.size() == 0)
				{
					std::cout << "There isn't any student to fix yet." << std::endl;
					break;
				}
				std::cout << "Which student you want to delete? : ";
				std::cin >> n;
				if (test.DeleteStudent(n))
				{
					std::cout << "Deletion Complete. List currently has " << test.size() << " students." << std::endl;
					test.PrintList();
				}
				break;
			}
			case 4:			// Fix Student
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
				if (fixStu.GetID() == "A00001")
				{
					break;
				}
				test.DeleteStudent(n);
				std::cout << "1. ID" << " (Currently: "<<fixStu.GetID()<<")"<< std::endl;
				std::cout << "2. Last name" << " (Currently: " << fixStu.GetLastName() << ")" << std::endl;
				std::cout << "3. First name" << " (Currently: " << fixStu.GetFirstName() << ")" << std::endl;
				std::cout << "4. Date of Birth" << " (Currently: " << fixStu.GetDoB().GetDateString() << ")" << std::endl;
				std::cout << "5. Class" << " (Currently: " << fixStu.GetClass() << ")" << std::endl;
				std::cout << "6. All" << std::endl;
				std::cout << "Which information you want to fix? : ";
				std::cin >> n;
				switch (n)
				{
				case 1:			// Fix ID
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
				case 2:			// Fix LastName
				{
					fixStu.InputLN();
					test.Check_NewStudentAndSort(fixStu, false);
					std::cout << "Result: " << std::endl;
					test.PrintList();
					break;
				}
				case 3:			// Fix FirstName
				{
					fixStu.InputFN();
					test.Check_NewStudentAndSort(fixStu, false);
					std::cout << "Result: " << std::endl;
					test.PrintList();
					break;
				}
				case 4:			// Fix DoB
				{
					fixStu.InputDOB();
					test.Check_NewStudentAndSort(fixStu, false);
					std::cout << "Result: " << std::endl;
					test.PrintList();
					break;
				}
				case 5:			// Fix Class
				{
					fixStu.InputCL();
					test.Check_NewStudentAndSort(fixStu, false);
					std::cout << "Result: " << std::endl;
					test.PrintList();
					break;
				}
				case 6:			// Fix All
				{
					if (!test.Import(false))
					{
						test.Check_NewStudentAndSort(fixStu, false);
					}
					std::cout << "Result: " << std::endl;
					test.PrintList();
					break;
				}
				default:		// Print Error
				{
					std::cout << "Please input 1-6." << std::endl;
					break;
				}
				}
				break;			// break of switch(i)
			}
			case 5:			// Find Student
			{
				system("cls");
				test.PrintList();
				int n = 0;
				std::string filter;
				if (test.size() == 0)
				{
					std::cout << "There isn't any student to find yet." << std::endl;
					break;
				}
				std::cout << "1. ID" << std::endl;
				std::cout << "2. Last name" << std::endl;
				std::cout << "3. First name" << std::endl;
				std::cout << "4. Birth year" << std::endl;
				std::cout << "5. Birth month" << std::endl;
				std::cout << "Which filter do you want for your search? : ";
				std::cin >> n;
				switch (n)
				{
				case 1:
				{
					std::cout << "Please insert your ID filter: ";
					FlushCin();
					std::getline(std::cin, filter);
					test.Find_IDFilter(filter);
					break;
				}
				case 2:
				{
					std::cout << "Please insert your \"Last Name\" filter: ";
					FlushCin();
					std::getline(std::cin, filter);
					test.Find_LNFilter(filter);
					break;
				}
				case 3:
				{
					std::cout << "Please insert your \"First Name\" filter: ";
					FlushCin();
					std::getline(std::cin, filter);
					test.Find_FNFilter(filter);
					break;
				}
				case 4:
				{
					int yeartofind;
					std::cout << "Please insert your \"Birth Year\" filter (yyyy): ";
					FlushCin();
					std::cin >> yeartofind;
					test.Find_YearFilter(yeartofind);
					break;
				}
				case 5:
				{
					int monthtofind;
					std::cout << "Please insert your \"Birth month\" filter (mm): ";
					FlushCin();
					std::cin >> monthtofind;
					test.Find_MonthFilter(monthtofind);
					break;
				}
				default:
				{
					std::cout << "Please input 1-4." << std::endl;
					break;
				}
				}

				break;
			}
			case 6:			// Export to File
			{
				system("cls");
				std::string filePath;
				std::cout << "Please insert file name to export: ";
				std::cin >> filePath;
				test.ExportToFile(filePath);
				std::cout << "Successfully exported to " << filePath << "." << std::endl;
				break;
			}
			case 7:			// Export to CSV
			{
				system("cls");
				std::string filePath;
				std::cout << "Please insert file name to export: ";
				std::cin >> filePath;
				test.ExportToCSV(filePath);
				std::cout << "Successfully exported to " << filePath << "." << std::endl;
				break;
			}
			case 8:			// Import from File
			{
				system("cls");
				std::string filePath;
				std::cout << "Please insert file name to import from (*.txt): ";
				std::cin >> filePath;
				test.ImportFromTXTFile(filePath);
				break;
			}
			case 9:
			{				
				system("cls");
				std::string filePath;
				std::cout << "Please insert file name to import from (*.csv): ";
				std::cin >> filePath;
				test.ImportFromCSV(filePath);
				break;
			}
			case 10:
			{
				break;
			}
			default:
			{
				std::cout << "Please input 1-10." << std::endl;
				break;
			}
			}
		}

		if (choose == 10)
			break;
	FlushCin();
	std::cout << "Do you want to go to main screen (y/n)? ";
	if (!flag)	std::cin.ignore();
	std::cin >> f;
	choose = 0;
	if (f == 'n' || f == 'N')
	{
		break;
	}
	} while (f=='y' || f=='Y');
	//Student test;
	//test.Import();
	//test.PrintStudentInfo();

	if(choose == 10)
		system("cls");
	system("pause");
	return 1;

}