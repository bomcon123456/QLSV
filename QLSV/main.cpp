#include <iostream>
#include <stdlib.h>

#include "QLSV.h"
#include "myLib.h"


int main()
{
	QLSV test;
	AutomaticallyLoad(test);

	int choice;
	bool flag;
	char f;

	do
	{
		if (flag = InitialScreen(choice))
		{
			ProcessUserChoice(choice, test);
		}
		if (choice == 10)
			break;

		FlushCin();
		std::cout << "Do you want to go to main screen (y/n)? ";
		if (!flag)	std::cin.ignore();
		std::cin >> f;
		choice = 0;

		if (f == 'n' || f == 'N')
		{
			break;
		}
	} while (f=='y' || f=='Y');

	if(choice == 10)
		system("cls");

	system("pause");
	return 1;

}