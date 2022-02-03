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
		{1, 2, 3},
		{1, 2, 3}	
	};

	vector<vector<int>> b
	{
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3}
	};

	vector<vector<int>> c;

	for (int i = 0; i < 3; i++)
	{
		vector<int> ans;
		for (int p = 0; p < 3; p++)
		{
			for (int c = 0; c < 3; c++)
			{
				ans.push_back(a[p][c] * b[c][i]);
				cout << ans[c] << endl;
			}
			ans[0] = ans[0] + ans[1] + ans[2];
			cout << ans[0];
			_getch();
		}
	}


	return 0;
}

