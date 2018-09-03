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
	std::cout << "7. Import from file" << std::endl;
	std::cout << "Your choice: ";
	FlushCin();
	std::cin >> choose;
	if (choose < 1 || choose >7)
	{
		return false;
	}
	return true;
}

