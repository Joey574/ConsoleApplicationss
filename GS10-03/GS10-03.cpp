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
	vector <double> cosineTable;
	vector <double> sineTable;
	
	for (int i = 0; i < 360; i++)
	{
		cosineTable.assign(i, cos(i * M_PI / 180.0));
		sineTable.assign(i, sin(i * M_PI / 180.0));
		cout << "hello\n";
	}

	while (1)
	{
		system("CLS");
		printf("Enter the angle you want the sine and cosine of: ");
		cin >> input;
		cout << "Cosine: " << cosineTable.at(input) << "\nSine: " << sineTable.at(input) << endl;
		printf("Press SPACE to exit or any other key to repeat\n");

		input2 = _getch();
		if (input2 == " ")
		{
			break;
		}
		continue;
	}
	return 0;
}

