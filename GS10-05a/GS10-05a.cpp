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
#include <cwchar>
#include <algorithm> // needed for vector sort

using namespace std;
using namespace std::this_thread; // needed for sleep for
using namespace std::chrono; // needed for sleep for

int main()
{
	vector<vector<int>> a
	{
		{9, 5, 7},
		{10, 2, 5},
		{12, 67, 4}	
	};

	vector<vector<int>> b
	{
		{9, 23, 35},
		{18, 26, 67},
		{15, 43, 24}
	};

	vector<vector<int>> c;

	vector<int> test;

	for (int x = 0; x < 3; x++)
	{
		vector <int> temp = {0, 0, 0};
		for (int i = 0; i < 3; i++)
		{
			for (int p = 0; p < 3; p++)
			{
				temp[i] += a[x][p] * b[p][i];
			}
		}
		c.push_back(temp);
	}
	

	for (int i = 0; i < c.size(); i++)
	{
		for (int p = 0; p < c[i].size(); p++)
		{
			cout << c[i][p] << "\t";
		}
		cout << endl;
	}

	return 0;
}

