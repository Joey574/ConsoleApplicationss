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
using namespace this_thread; // needed for sleep for
using namespace chrono; // needed for sleep for

#include "Hyperbola.h"

int main()
{
	hyperbolaCalc h;

	string num;
	string denom;
	string temp;



	printf("Enter numerator (use ^ to signal an exponent): ");

	getline(cin, num);
	
	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] == ' ')
		{

		}
		else if (num[i] == 'x' || num[i] == 'X')
		{ 
			h.setNumVa(true);
			if (num[i + 1] == '^')
			{
				temp = num[i] + 2;
				h.setNumEx(stoi(temp));
			}
		}
		else if (num[i] + 1 != 'x'  && num[i] + 1 != 'X')
		{
			h.setNum(num[i]);
		}
	}
}

