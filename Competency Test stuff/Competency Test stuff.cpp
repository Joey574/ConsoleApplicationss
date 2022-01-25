// Competency Test stuff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h> // Uses functions named after shapes beware for classes
#include <chrono> // needed for sleep for
#include <thread>
#include <math.h>
#include <sstream> // needed for files
#include <fstream> // needed for files
#include <cwchar>
#include <algorithm> // needed for vector sort

using namespace std;

// CT LOOPING
// 1.)
/*
int main()
{
	for (int i = 15, counter = 0; i < 126; i++)
	{
		
		if (i != 25 && i != 30 && i != 35)
		{
			if (counter == 5)
			{
				printf("\n");
				counter = 0;
			}
			cout << i << "\t";
			counter++;
		}
	}
}
*/
// 2.)
/*
int main()
{
	int iNum;

	printf("Enter a positive number: ");
	cin >> iNum;

	while (iNum < 0)
	{
		system("CLS");
		printf("please enter a POSITIVE number: ");
		cin >> iNum;
	}
}
*/
// 3.)
/*
int main()
{
	int iIncrement;
	int iStart;
	int iEnd;

	printf("Please enter a starting value: ");
	cin >> iStart;
	printf("Please enter an ending value: ");
	cin >> iEnd;
	printf("Please enter the increment to change by: ");
	cin >> iIncrement;
	system("CLS");

	do
	{
		iStart += iIncrement;
	} while (iStart <= iEnd);
}
*/

// CT STRINGS
// 1.)
/*
int main()
{
	string sfName = "Joey";
	cout << sfName[2];
	sfName = "Rumplestiltskin";
}
*/
// 2.)
/*
int main()
{
	string sMName = "Lee";

	if (sMName.length() < 5)
	{
		for (int i = 0; i < sMName.length(); i++)
		{
			cout << sMName[i];
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			cout << sMName[i];
		}
	}
	
}
*/
// 3.)
/*
int main()
{
	string sLName = "Soroka";

	for (int i = sLName.length(); i > -1; i--)
	{
		cout << sLName[i];
	}
}
*/

// CT FUNCTIONS
// 1.)
/*
void smF (int a, int b, int c);
*/
// 2.)
/*
int smF(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
*/
// 3.)
/*
string Capitalize(string original)
{
	string output = original;
	toupper(output[0]);

	for (int i = 0; i < output.length(); i++)
	{
		if (output[i] == ' ')
		{
			toupper(output[i + 1]);
		}
	}
	return output;
}
*/