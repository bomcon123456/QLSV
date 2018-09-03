#pragma once
#include <iostream>
#include <stdlib.h>
void FlushCin()
{
	std::cin.seekg(0, std::ios::end);
	std::cin.clear();
}


bool InitialScreen(int& choose)
{
	system("cls");
	std::cout << "IS332 Student Manager" << std::endl;
	std::cout << "1. Student list" << std::endl;
	std::cout << "2. Add student" << std::endl;
	std::cout << "3. Delete student" << std::endl;
	std::cout << "4. Fix student information" << std::endl;
	std::cout << "5. Find student" << std::endl;
	std::cout << "6. Export to file" << std::endl;
	std::cout << "7. Export to CSV file" << std::endl;
	std::cout << "8. Import from text file" << std::endl;
	std::cout << "9. Import from CSV file" << std::endl;
	std::cout << "10. Exit." << std::endl;
	std::cout << "Your choice: ";
	FlushCin();
	std::cin >> choose;
	if (std::cin.fail())
	{
		return false;
	}

	return true;
}

