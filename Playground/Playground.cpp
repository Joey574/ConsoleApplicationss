/*
Author: Joey Soroka
Project Name: Personal Project
File Name: Playground.cpp
Purpose: playground to test random concepts
Pseudocode: 
Maintenance Log:
9/27/21:	Testing how to check string input in if statements
*/

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
	string input;

	bool loop = true;

	while (loop == true)
	{
		cin >> input;

		if (input == "1")
		{
			printf("1");
		}
		else if (input == "w")
		{
			printf("w");
		}
		else if (input == "`")
		{
			printf("`");
		}
		else if (input == "W")
		{
			printf("W");
		}

		_getch();

		system("CLS");

		cin >> input;

		if (input == "1")
		{
			continue;
		}
		else if (input == "2")
		{
			break;
		}


	}

	return 0;
}
