#pragma once
#include <iostream>
#include <stdlib.h>

void InitialScreen(int& choose)
{
	system("cls");
	std::cout << "IS332 Student Manager" << std::endl;
	std::cout << "1. Student list" << std::endl;
	std::cout << "2. Add student" << std::endl;
	std::cout << "3. Delete student" << std::endl;
	std::cout << "4. Find student" << std::endl;
	std::cout << "Your choice: ";
	std::cin >> choose;
}

void FlushCin()
{
	std::cin.seekg(0, std::ios::end);
	std::cin.clear();
}
