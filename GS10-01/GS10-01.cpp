/*
Author: Joey Soroka
File Name:
Project Name:
Purpose:
Pseudocode:
Maintenance Log:

*/

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
	int input;
	vector <int> vec;

	for (int i = 0; i < 50; i++)
	{
		vec.push_back(i);
	}
	
	while (1)
	{
		system("CLS");
		printf("Enter value to multiply vector by: ");
		cin >> input;

		for (int i = 0; i < vec.size(); i++)
		{
			vec.at(i) = i * input;
		}

		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << endl;
		}

		printf("Press SPACE to exit or any other key to repeat\n");

		char input2 = _getch();
		if (input2 == ' ')
		{
			break;
		}
		continue;
	}

	return 0;
}

