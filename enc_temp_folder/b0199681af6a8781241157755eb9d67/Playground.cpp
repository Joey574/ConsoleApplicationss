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
 #include <windows.h>
#include <string>
#include <vector>

using namespace std;

void escapeTesting()
{
	
	_getch();

	char input = _getch();

	if (input ==  VK_ESCAPE)
	{
		printf("escape key detected\n");

		_getch();

		if (input == VK_ESCAPE)
		{
			printf("somethings up");
		}
		else
		{
			printf("WOOHOO IT WORKS");
		}
			

	}


}

void vectorTesting()
{
	vector <int> testing;

	testing.assign(1, 10);

	int i = 1;

	cout << testing[i] << endl;
}

int main()
{
	vectorTesting();
	
	_getch();

	return 0;
}
