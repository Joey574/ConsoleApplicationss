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
	int input;
	string input2;
	vector <vector<int>> multiplacationTable;
	srand(0);
	srand((unsigned)time(NULL));

	for (int i = 1; i < 13; i++)
	{
		vector<int> temp;
		for (int p = 1; p < 13; p++)
		{
			temp.push_back(i * p);
		}
		multiplacationTable.push_back(temp);
	}

	while (1)
	{
		
		int r = 0 + rand() % (11 - 0 + 1);
		int c = 0 + rand() % (11 - 0 + 1);

		system("CLS");
		cout << "Enter the answer below\n" << r + 1 << " X " << c + 1 << endl;
		cin >> input;
		if (input == multiplacationTable[r][c])
		{
			printf("Correct! Good job!\n");
		}
		else
		{
			printf("Incorrect.\n");
		}
		printf("Try again? y/n\n");
		input2 = _getch();
		if (input2 == "y")
		{
			continue;
		}
		else if (input2 == "n")
		{
			break;
		}
	}


	return 0;
}
	

