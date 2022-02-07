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
#include <windows.h> // Uses functions named after shapes beware for classes
#include <chrono> // needed for sleep for
#include <thread>
#include <math.h>
#include <sstream> // needed for files
#include <fstream> // needed for files
using namespace std;
using namespace std::this_thread; // needed for sleep for
using namespace std::chrono; // needed for sleep for

bool loading = true;
vector <double> cosineTable;
vector <double> sineTable;

DWORD WINAPI InputThread(LPVOID data);

int main()
{
	int input;
	string input2;

	
	srand((unsigned)time(NULL));
	HANDLE threadHandle;
	DWORD threadID;

	threadHandle = CreateThread(NULL, 0, InputThread, (LPVOID)1, 0, &threadID);

	while (loading == true)
	{
		system("CLS");
		printf("Loading.");
		sleep_for(250000000ns);
		if (!loading)
		{
			break;
		}
		printf(".");
		sleep_for(250000000ns);
		if (!loading)
		{
			break;
		}
		printf(".");
		sleep_for(250000000ns);
		if (!loading)
		{
			break;
		}
	}
	system("CLS");


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


DWORD WINAPI InputThread(LPVOID data)
{
	for (int i = 0; i < 360; i++)
	{
		cosineTable.push_back(cos(i * M_PI / 180.0));
		sineTable.push_back(sin(i * M_PI / 180.0));
	}
	loading = false;

	return 0;
}
