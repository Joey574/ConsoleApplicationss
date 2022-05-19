/*
Author: Joey Soroka
File Name: RPG w multithreading.cpp
Project Name: RPG
Purpose:
Pseudocode:
Maintenance Log:
1/8/22:	Started project from scratch
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
#include <algorithm> // needed for vector sort and other cool things

#include "Classes.h"
#include "Structs.h"
#include "Functions.cpp"

using namespace std;

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	vector <systems> t(100);

	gm gm;
	crew temp;
	NPC n;

	for (int i = 0; i < 4; i++)
	{
		gm.mod.push_back(0);
	}

	for (int i = 0; i < 3; i++)
	{
		gm.cr.push_back(temp);
	}

	introArt();

	mainMenu(gm, t, n);

	return 0;
}
