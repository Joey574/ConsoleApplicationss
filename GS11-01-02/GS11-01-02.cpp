/*
Author: Joey Soroka
File Name:
Project Name:
Purpose:
Pseudocode:
Maintenance Log:

*/

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h>
#include <math.h>
#include <fstream>
using namespace std;

int main()
{
	int spaces = 0;
	int tabs = 0;
	int numbers = 0;
	int textLength = 0;
	int newLines = 0;

	ifstream in;
	in.open("test.txt");
	string temp;

	if (!in.is_open())
	{
		printf("File not found");
	}
	while (getline(in, temp))
	{
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == ' ')
			{
				spaces += 1;
			}
			else if (temp[i] == '\t')
			{
				tabs += 1;
			}
			else if (temp[i] >= '0' && temp[i] <= '9')
			{
				numbers += 1;
			}
			
		}
		textLength += temp.length();
		newLines++;
	}

	cout << "Total Characters: " << textLength << endl;
	cout << "Number of Lines: " << newLines << endl;
	cout << "Numbers: " << numbers << endl;
	cout << "Tabs: " << tabs << endl;
	cout << "Spaces: " << spaces << endl;

	return 0;
}

