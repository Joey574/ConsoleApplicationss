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
using namespace std;
using namespace std::this_thread; // needed for sleep for
using namespace std::chrono; // needed for sleep for

#include "Player.h"

void Introduction(struct player &p, struct ship &s);

int main()
{
	player player;
	ship ship[4];
	module module[1];
	string input; 
	string temp;

	fstream saveFile;
	fstream highScores;

	while (1)
	{
		system("CLS");
		printf("Menu:\n1: Start Game\n2: High Scores\n3: Help\n4: Credits\n5: Save/Load\n6: Exit\nInput: ");
		cin >> input;
		system("CLS");

		if (input == "1") // start game
		{
			Introduction(player, ship[4]);
		}
		else if (input == "2") // high scores
		{
			highScores.open("highScores.txt");

			if (!highScores.is_open())
			{
				printf("File not found");
			}

			while (getline(highScores, temp))
			{

			}

			highScores.close();
		}
		else if (input == "3") // help
		{

		}
		else if (input == "4") // credits
		{
			printf("Author:\nJoey Soroka\n\nProgramming Support:\nEric Pace\nSlater Swart\nIssac Morine\nTucker\n\nCreative Support:\nIssac Morine\n");
			_getch();
		}
		else if (input == "5") // save / load
		{

			printf("Menu:\n1: Save\n2: Load\nInput: ");
			cin >> input;
			if (input == "1") // save
			{
				saveFile.open("save.txt");


			}
			else if (input == "2") // load
			{
				saveFile.open("save.txt");

				if (!saveFile.is_open())
				{
					printf("File not found");
				}

				while (getline(saveFile, temp))
				{

				}

				saveFile.close();
			}
		
		}
		else if (input == "6") // exit
		{
			return 0;
		}
		else
		{
			printf("Invalid input");
			Sleep(200);
			printf(".");
			Sleep(200);
			printf(".");
			Sleep(200);
			printf(".");
			Sleep(500);
			continue;
		}
	}
	
	
	return 0;
}

void Introduction(struct player &p, struct ship& s)
{
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
	cin >> p.name;
	system("CLS");
	cout << "Captain " << p.name << ", you shall be in charge of a voyager class starship, what do you wish to call it?";
	cin >> s.name;
	system("CLS");

}