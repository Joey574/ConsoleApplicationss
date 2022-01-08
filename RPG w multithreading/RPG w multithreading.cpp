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
using namespace std;
using namespace std::this_thread; // needed for sleep for
using namespace std::chrono; // needed for sleep for

string firstTimeIntroduction();

struct player
{
	string name;
};


int main()
{
	player p;
	string input;

	ifstream save;
	save.open("save.txt");
	if (!save.is_open())
	{
		p.name = firstTimeIntroduction();
	}
	else
	{
		while (1)
		{
			system("CLS");
			printf("It seems like you have a save, would you like to load it?\n1. Yes\n2. No\n");
			cin >> input;
			system("CLS");
			if (input == "1")
			{

			}
			else if (input == "2")
			{
				p.name = firstTimeIntroduction();
			}
			else
			{
				printf("Incorrect input please enter valid input\n");
				Sleep(1000);
				continue;
			}
		}
		
	}

	printf("Menu:\n1: Start Game\n2: High Scores\n3: Help\n4: Credits\n5: Save/Load\n6: Exit\nYou Pick: ");
	cin >> input;
	if (input == "1")
	{

	}
	else if (input == "2")
	{

	}
	else if (input == "3")
	{

	}
	else if (input == "4")
	{

	}
	else if (input == "5")
	{

	}
	else if (input == "6")
	{

	}
	else
	{

	}
	
}

string firstTimeIntroduction()
{
	string input;
	printf("Welcome adventurer! The year is 2130 and the Earth is falling apart...\n");
	_getch();
	system("CLS");
	printf("You and a team of 3 others have been selected to go on a mission that could save the world...\n");
	_getch();
	system("CLS");
	printf("You have been assigned the role of team captain and are tasked with finding a habitable world for the population of the earth...\n");
	_getch();
	system("CLS");
	printf("So what say you captain? What shall your callsign be?\n");
	cin >> input;
	system("CLS");
	return input;
}
