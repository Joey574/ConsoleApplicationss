#pragma once

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
#include "wtypes.h"

using namespace std;

// Function Prototypes

void worldRan(int difficulty, vector <systems>& t);
void gameManager(struct player& p, struct ship& s, struct system& t, bool inGame);

// Useful Functions

void GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;
	// Get a handle to the desktop window
	const HWND hDesktop = GetDesktopWindow();
	// Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	// The top left corner will have coordinates (0,0)
	// and the bottom right corner will have coordinates
	// (horizontal, vertical)
	horizontal = desktop.right;
	vertical = desktop.bottom;
}

void gotoxy(int x, int y) // credit: Miyoshi
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void invalidInput()
{
	printf("Invalid input");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(500);
}

void exploredUpdater(vector<systems>& s)
{
	for (int xy = 0; xy < 100; xy++)
	{
		if (s[xy].current == true)
		{
			s[xy].explored == true;
			if (s[xy].x > 0)
			{
				s[xy - 1].explored = true;
			}
			if (s[xy].x < 9)
			{
				s[xy + 1].explored = true;
			}
			if (s[xy].y > 0)
			{
				s[xy - 10].explored = true;
			}
			if (s[xy].y < 9)
			{
				s[xy + 10].explored = true;
			}
			break;
		}
	}
}

void systemInfo(vector<systems>& s)
{
	for (int xy = 0; xy < 100; xy++)
	{
		if (s[xy].explored == true)
		{
			gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 3);
			printf("       ");
			gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 1);
			cout << "Danger: " << s[xy].dangerLevel;
			gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 2);
			cout << "Supplies:";
			gotoxy((s[xy].x * 10) + 5, (s[xy].y * 6) + 3);
			cout << s[xy].supplies;
		}
		else
		{
			gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 3);
			printf("No Data");
		}
	}
}

// Art Functions

void introArt()
{
	system("CLS");
	printf("                     `. ___");
	printf("                   __,' __`.                _..----....____");
	printf("       __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'");
	printf("  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'");
	printf(",'________________                          \\`-._`-','");
	printf(" `._              ```````````------...___   '-.._'-:");
	printf("    ```--.._      ,.                     ````--...__\\-.");
	printf("            `.--. `-`                       ____    |  |`");
	printf("              `. `.                       ,'`````.  ;  ;`");
	printf("                `._`.        __________   `.      \\'__/`");
	printf("                   `-:._____/______/___/____`.     \\  `");
	printf("                              |       `._    `.    \\");
	printf("                              `._________`-.   `.   `.___");
	printf("                                                 `------'`");
	printf("\n  _________  __           .__   .__                   ");
	printf(" /   _____/_/  |_   ____  |  |  |  |  _____   _______ ");
	printf(" \\_____  \\ \\   __\\_/ __ \\ |  |  |  |  \\__  \\  \\_  __ \\");
	printf(" /        \\ |  |  \\  ___/ |  |__|  |__ / __ \\_ |  | \\/");
	printf("/_______  / |__|   \\___  >|____/|____/(____  / |__|   ");
	printf("        \\/             \\/                  \\/         ");
	printf("__________                                            __           ");
	printf("\\______   \\  ____    _____    ____  _____     ____  _/  |_   ______");
	printf(" |       _/_/ __ \\  /     \\  /    \\ \\__  \\   /    \\ \\   __\\ /  ___/");
	printf(" |    |   \\\\  ___/ |  Y Y  \\|   |  \\ / __ \\_|   |  \\ |  |   \\___ \\ ");
	printf(" |____|_  / \\___  >|__|_|  /|___|  /(____  /|___|  / |__|  /____  >");
	printf("        \\/      \\/       \\/      \\/      \\/      \\/             \\/ ");
	printf("By: Joey Soroka");
	_getch();
}

void menuArt()
{
	int ascX = 25;
	int ascY = 5;

	system("CLS");
	gotoxy(ascX, ascY);
	printf("                                ....");
	gotoxy(ascX, ascY + 1);
	printf("                                /   `.");
	gotoxy(ascX, ascY + 2);
	printf("                               |      `,");
	gotoxy(ascX, ascY + 3);
	printf("		                 -.   ,'		  ");
	gotoxy(ascX, ascY + 4);
	printf("                                   `-/ \\				  ");
	gotoxy(ascX, ascY + 5);
	printf("                                  ,'    ;				  ");
	gotoxy(ascX, ascY + 6);
	printf("                                ,'     /      ____		  ");
	gotoxy(ascX, ascY + 7);
	printf("                        ______,i     __-  ,'''__  `._	  ");
	gotoxy(ascX, ascY + 8);
	printf("                       /        `-,-'  `-+ /''XX`-.. `.	  ");
	gotoxy(ascX, ascY + 9);
	printf("                      /    ,'-._    ``-.i,'XXXXXXXX`.  :  ");
	gotoxy(ascX, ascY + 10);
	printf("                     /  .--  ._ `-,_     \\XXXXXXXXXX/ |	  ");
	gotoxy(ascX, ascY + 11);
	printf("                     |   `.  `.  /XX`..   \\XXXXXXXX| .'	  ");
	gotoxy(ascX, ascY + 12);
	printf("                   ,'|  .i> `. .'XXXXXX/-. -._XXX_/ ,'	  ");
	gotoxy(ascX, ascY + 13);
	printf("                 ,'  ',.:>_.'','XXXXXX/  ,`-. `. _,'\\  _  ");
	gotoxy(ascX, ascY + 14);
	printf("               ,'    /   _ `./XXXXXX,'  / /  `. '.  ,+' `.");
	gotoxy(ascX, ascY + 15);
	printf("             ,'     /   -_` /XXXXXX/  ,',',- , `.<-'    ,'");
	gotoxy(ascX, ascY + 16);
	printf("           ,'      /   :- ;'XXXXXX/  /,',' ,',  ,-.   ,'  ");
	gotoxy(ascX, ascY + 17);
	printf("         ,'       :  ._ `,'XXXXXX/ ,'/,'_,',',-'XX,-,'	  ");
	gotoxy(ascX, ascY + 18);
	printf("       ,'        _ `-.  /XXXXXXX/ /,;',',-','XXX,:`		  ");
	gotoxy(ascX, ascY + 19);
	printf("      `    _,'-,- `-..i`.XXXXX,' /`/,',',-'XX_X'  `,	  ");
	gotoxy(ascX, ascY + 20);
	printf("       `.,'   ,'      \\  `=.X,',' ;',','XX,,'\\\\  ,:		  ");
	gotoxy(ascX, ascY + 21);
	printf("            ,'`.       |,;' `-.  - i,'XXX,'    -' |		  ");
	gotoxy(ascX, ascY + 22);
	printf("          ,'    `    ,' .i     `-,'XXXX,'`.    ,-'		  ");
	gotoxy(ascX, ascY + 23);
	printf("         /         ,' ,'  `-..    ;-,,;'   `,,'			  ");
	gotoxy(ascX, ascY + 24);
	printf("       ,'    `.  ,' ,-        \\ ,'  ,:    ,'			  ");
	gotoxy(ascX, ascY + 25);
	printf("      |        ,' ,'       .  ,'  ,'  `-<'				  ");
	gotoxy(ascX, ascY + 26);
	printf("    ,-._     ,' ,'     -.  ,-'  ,'						  ");
	gotoxy(ascX, ascY + 27);
	printf("  ,'       ,'_,'   _    ,`'    |						  ");
	gotoxy(ascX, ascY + 28);
	printf(" \\       ,','       `,-:    _,/							  ");
	gotoxy(ascX, ascY + 29);
	printf(" \\     ,' '       ,-'   --''							  ");
	gotoxy(ascX, ascY + 30);
	printf("  '`-<' ,'   \\ ,-'										  ");
	gotoxy(ascX, ascY + 31);
	printf("        |    ,'											  ");
	gotoxy(ascX, ascY + 32);
	printf("        \\  _'											  ");
	gotoxy(ascX, ascY + 33);
	printf("         '-												  ");
	gotoxy(0, 0);
}

// Main Menu Functions

void difficultySet(string input, struct player &p)
{
	if (input == "1")
	{
		p.difficulty = 0; // easy
	}
	else if (input == "2")
	{
		p.difficulty = 1; // medium
	}
	else if (input == "3")
	{
		p.difficulty = 2; // hard
	}
}

void gameStart(struct player &p, struct ship &s, vector <systems>& t)
{
	string input;

	printf("Welcome adventurer! The year is 2130 and the Earth is falling apart.\n");
	_getch();
	system("CLS");
	printf("You and a team of 3 others have been selected to go on a mission that could save the world.\n");
	_getch();
	system("CLS");
	printf("You have been assigned the role of team captain and are tasked with finding a habitable world for the population of the earth.\n");
	_getch();
	system("CLS");
	printf("So what say you Captain? What shall your callsign be? You can change it later.\n");
	cin >> p.name;
	system("CLS");
	cout << "Captain " << p.name << ", you shall be in charge of a voyager class starship, what do you wish to call it?\n";
	cin >> s.name;
	system("CLS");
	printf("As the captain of your ship it's your responsibility to keep your ship and your crew alive. On top of this you must explore unknown space to discover a colonization candidate.\n");
	_getch();
	system("CLS");
	printf("We've sent many ships ahead of you, yet none have reported back sucessfully, keep your wits about you out there!\n");
	_getch();
	system("CLS");
	printf("Your voyager starship is currently equiped with just the command module, the \"bridge\" of the starship, and should be protected at all costs. In the future when you've collected some resources you'll be able to build ");
	printf("more modules with the blueprints we have supplied you with.\n");
	_getch();
	system("CLS");
	printf("If you ever need help or want to save visit your ships onboard computer, located in your command module, and reopen the menu.\n");
	_getch();
	system("CLS");
	cout << "Good luck Captain " << p.name << ", and make sure you come home safe!" << endl;
	_getch();
	system("CLS");
	printf("Difficulty:\n1: Easy\n2: Medium\n3: Hard\nInput: ");
	cin >> input;

	difficultySet(input, p);

	worldRan(p.difficulty, t);
}

void scores()
{
	ifstream highScores;
	highScores.open("highScores.txt");
	if (!highScores.is_open())
	{
		printf("High scores file not found");
	}

	string temp;

	vector <int> vecScore;

	int score;

	printf("Top 10 High Scores:\n");

	highScores.open("highScores.txt");

	if (!highScores.is_open())
	{
		printf("File not found");
	}

	vecScore.clear();
	while (getline(highScores, temp))
	{
		score = stoi(temp); // turns temp line from highScores.txt into int
		vecScore.push_back(score);
	}
	sort(vecScore.rbegin(), vecScore.rend()); // sorts the scores in vector from highest to lowest

	for (int i = 1; i < 11; i++)
	{
		cout << i << ") " << vecScore[i - 1] << endl; // outputs top 10 high scores
	}

	highScores.close();
	_getch();
}

void help(struct player &p)
{
	string input;

	while (1)
	{
		printf("Menu:\n1: Change Name\n2: Change Difficulty\n3: Reset Highscores\n4: Back\nInput: ");
		cin >> input;

		if (input == "1")
		{
			printf("Enter new name: ");
			cin >> input;
			p.name = input;
		}
		else if (input == "2")
		{
			printf("Difficulty:\n1: Easy\n2: Medium\n3: Hard\nInput: ");
			cin >> input;

			difficultySet(input, p);
		}
		else if (input == "3")
		{
			ofstream highScores;

			printf("Are you sure you want to reset your high scores?\n1: Yes\n2: No\nInput: ");
			cin >> input;
			if (input == "1")
			{
				highScores.open("highScores.txt", ios::out | ios::trunc);

				for (int i = 0; i < 9; i++)
				{
					highScores << "0\n";
				}
				highScores << "0";

				highScores.close();
			}
			else if (input == "2")
			{
				continue;
			}
			else
			{
				invalidInput();
				continue;
			}
		}
		else if (input == "4")
		{
			break;
		}
		else
		{
			invalidInput();
			continue;
		}
	}
}

void credits()
{
	printf("Author:\nJoey Soroka\n\n");
	printf("Programming Support:\nEric Pace\nKian Darrington\nSlater Swart\nIssac Morine\nTucker Norris\n\n");
	printf("Creative Support:\nIssac Morine\n");
	_getch();
}

void saveAndLoad()
{
	string input;

	printf("Menu:\n1: Save\n2: Load\n3: Back\nInput: ");
	cin >> input;
	system("CLS");
}

void mainMenu(bool inGame, struct player &p, struct ship &s, vector <systems>& t)
{
	string input;

	while (1) // menu loop
	{
		system("CLS");

		menuArt();

		if (inGame == false) // check to see if game has already been started
		{
			printf("Menu:\n1: Start Game\n"); // not started
		}
		else
		{
			printf("Menu:\n1: Resume Game\n"); // has started
		}
		printf("2: High Scores\n3: Help\n4: Credits\n5: Save/Load\n6: Exit\nInput: "); // default menus

		cin >> input;
		system("CLS");

		if (input == "1") // start/resume game
		{
			gameManager(p, s, t, inGame);
		}
		else if (input == "2") // High scores
		{
			scores();
		}
		else if (input == "3") // help
		{
			help(p);
		}
		else if (input == "4") // credits
		{
			credits();
		}
		else if (input == "5") // save/load
		{
			saveAndLoad();
		}
		else if (input == "6") // exit
		{
			break;
		}
		else // invalid input
		{
			invalidInput();
			continue;
		}
	}
}

// World Constructor Functions

void worldConstructor()
{
	int line = 196;
	int upLine = 179;
	int horSep = 10;
	int vertSep = 6;
	int temp = 1;
	int horDist = 100;
	int vertDist = 61;
	int topLeftCorner = 218;
	int topRightCorner = 191;
	int botLeftCorner = 192;
	int botRightCorner = 217;
	int rightT = 195;
	int leftT = 180;
	int bottomT = 193;
	int upT = 194;
	int junction = 197;
	int xy = 0;

	for (int x = 0; x < 10; x++)
	{
		cout << (char)topLeftCorner;
		for (int i = 1; i < horDist; i++)
		{
			cout << (char)line;
		}
		cout << (char)topRightCorner << endl;
		for (int p = 1; p < vertSep; p++)
		{
			for (int i = 0; i <= horDist; i += horSep)
			{
				gotoxy(i, p + (x * 6));
				cout << (char)upLine;
			}
		}
		cout << endl;
	}
	cout << (char)botLeftCorner;
	for (int p = 6; p < 60; p += 6)
	{
		gotoxy(0, p);
		cout << (char)rightT;
		for (int i = 10; i < horDist; i += 10)
		{
			gotoxy(i, p);
			cout << (char)junction;
		}
		gotoxy(100, p);
		cout << (char)leftT;
	}
	gotoxy(1, 60);
	for (int p = 0; p < 10; p++)
	{
		for (int i = 0; i < 9; i++)
		{
			cout << (char)line;
		}
		cout << (char)bottomT;
	}
	gotoxy(100, 60);
	cout << (char)botRightCorner;
	for (int i = 10; i < horDist; i += 10)
	{
		gotoxy(i, 0);
		cout << (char)upT;
	}
	gotoxy(100, 0);
	cout << (char)topRightCorner;

	mapMovement();
}

void worldRan(int difficulty, vector <systems> &t)
{
	string input;

	vector <int> worldSeed;

	int seed = 0;
	int xy = 0;

	for (int y = 0; y < 10; y++) // will run total of 100 times assinging some basic values to the systems
	{
		for (int x = 0; x < 10; x++)
		{
			t[xy].x = x; // system x value
			t[xy].y = y; // system y value
			t[xy].systemID = xy; // systemID for ease of access
			xy++;
		}
	}

	xy = 0; // resetting for later use

	system("CLS");
	printf("World Seed: "); // getting user inputted value for world seed
	cin >> input;
	system("CLS");

	for (int i = 0; i < input.length(); i++) // runs for length of world seed, changes input into its ascii value
	{
		seed += (int)input[i];
	}


	srand(seed); // uses ascii value of seed for srand


	for (int p = 0; p < 100; p++) // runs 100 times, getting random # 0-9, 1 for each system
	{
		worldSeed.push_back(rand() % (10));
	}


	// sets danger level and supplies for each system
	if (difficulty == 0) // easy
	{
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				if (worldSeed[xy] <= 2) // safe / no danger
				{
					t[xy].dangerLevel = 0;
					t[xy].supplies = rand() % (5);
				}
				else if (worldSeed[xy] <= 5 && worldSeed[xy] > 2) // low danger
				{
					t[xy].dangerLevel = 1;
					t[xy].supplies = rand() % (8);
				}
				else if (worldSeed[xy] <= 8 && worldSeed[xy] > 5) // medium danger
				{
					t[xy].dangerLevel = 2;
					t[xy].supplies = rand() % (10);
				}
				else if (worldSeed[xy] == 9) // lots of danger
				{
					t[xy].dangerLevel = 3;
					t[xy].supplies = rand() % (15);
				}
				xy++;
			}
		}
	}
	else if (difficulty == 1) // medium 
	{
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				if (worldSeed[xy] == 0) // safe / no danger
				{
					t[xy].dangerLevel = 0;
					t[xy].supplies = rand() % (5);
				}
				else if (worldSeed[xy] <= 4 && worldSeed[xy] > 0) // low danger
				{
					t[xy].dangerLevel = 1;
					t[xy].supplies = rand() % (8);
				}
				else if (worldSeed[xy] <= 8 && worldSeed[xy] > 4) // medium danger
				{
					t[xy].dangerLevel = 2;
					t[xy].supplies = rand() % (10);
				}
				else if (worldSeed[xy] == 9) // lots of danger
				{
					t[xy].dangerLevel = 3;
					t[xy].supplies = rand() % (15);
				}
				xy++;
			}
		}
	}
	else if (difficulty == 2) // hard
	{
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				if (worldSeed[xy] <= 3) // low danger
				{
					t[xy].dangerLevel = 1;
					t[xy].supplies = rand() % (8);
				}
				else if (worldSeed[xy] <= 7 && worldSeed[xy] > 3) // medium danger
				{
					t[xy].dangerLevel = 2;
					t[xy].supplies = rand() % (10);
				}
				else if (worldSeed[xy] >= 8) // lots of danger
				{
					t[xy].dangerLevel = 3;
					t[xy].supplies = rand() % (15);
				}
				xy++;
			}
		}
	}
	else
	{
		printf("Difficulty out of range");
	}

	t[0].dangerLevel = 0; // setting adjacent tiles to safe to avoid death on spawn
	t[1].dangerLevel = 0;
	t[10].dangerLevel = 0;
	t[11].dangerLevel = 0;

	t[0].current = true; // setting current system

	t[50 + rand() % 50].objective = true; // setting random system to be the "objective"

	worldConstructor();
}

// Game Functions

void gameManager(struct player&p, struct ship&s, vector <systems> &t, bool inGame)
{
	if (inGame == false)
	{

	}
}

void mapMovement()
{
	gotoxy(0, 61);

	if ()
}