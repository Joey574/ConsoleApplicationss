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
	vector <int> whoKnowWhatThisIs;


	for (int i = 0; i < 50; i++)
	{
		whoKnowWhatThisIs.push_back(i);
	}
	printf("Enter the number you want to multiply by: ");
	cin >> input;
	for (int i = 0; i < 50; i++)
	{
		whoKnowWhatThisIs.at(i) = i * input;
	}
	for (int i = 0; i < 50; i++)
	{
		cout << whoKnowWhatThisIs.at(i) << endl;
	}

	return 0;
}

