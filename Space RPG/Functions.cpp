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

#include "Structs.h"

using namespace std;

// Function Prototypes

void gotoxy(int x, int y);
void exploredUpdater(vector<systems>& s);
void worldRan(int difficulty, vector <systems>& t, vector<NPC>& n);
void gameManager(struct gm &gm, vector <systems>& t, vector<NPC>& n);
void mapMenu(vector <systems>& t, struct gm& gm);
void objectiveFound(struct gm& gm);
void gameRestart(struct gm& gm, vector <systems>& t);
void combat(struct gm& gm, vector <systems>& t, int encounter);
int encounterChance(vector <systems>& t);
void friendlyShip(struct gm& gm, vector <systems>& t);
void gameOver();
void moveUpdate(struct gm& gm);
void shipValues(struct gm& gm);
void shop(struct gm& gm, vector <NPC> &n, vector <systems>& t);
void mapStats(struct gm& gm);

// Useful Functions

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
			s[xy].explored = true;

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
			if (s[xy].x < 9 && s[xy].y < 9)
			{
				s[xy + 11].explored = true;
			}
			if (s[xy].x > 0 && s[xy].y < 9)
			{
				s[xy + 9].explored = true;
			}
			if (s[xy].x > 0 && s[xy].y > 0)
			{
				s[xy - 11].explored = true;
			}
			if (s[xy].x < 9 && s[xy].y > 0)
			{
				s[xy - 9].explored = true;
			}
			break;
		}
	}
}

void systemInfo(vector<systems>& s, struct gm& gm)
{
	for (int xy = 0; xy < 100; xy++)
	{
		if (s[xy].current == true)
		{
			gotoxy((s[xy].x * 10) + 2, (s[xy].y * 6) + 3);
			printf("       ");
			gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 1);
			cout << "Danger: " << s[xy].dangerLevel;
			gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 2);
			cout << "Supplies:";
			gotoxy((s[xy].x * 10) + 5, (s[xy].y * 6) + 3);
			cout << s[xy].supplies;
			gotoxy((s[xy].x * 10) + 5, (s[xy].y * 6) + 4);
			cout << char(234);
			if (s[xy].objective == true)
			{
				gotoxy((s[xy].x * 10) + 2, (s[xy].y * 6) + 5);
				printf("       ");
				gm.p.victory = true;
				gotoxy(0, 0);
			}
		}
		else if (s[xy].explored == true)
		{
			gotoxy((s[xy].x * 10) + 2, (s[xy].y * 6) + 3);
			printf("       ");
			gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 1);
			cout << "Danger: " << s[xy].dangerLevel;
			gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 2);
			cout << "Supplies:";
			gotoxy((s[xy].x * 10) + 5, (s[xy].y * 6) + 3);
			cout << s[xy].supplies;
			if (s[xy].objective == true)
			{
				gotoxy((s[xy].x * 10) + 2, (s[xy].y * 6) + 5);
				printf("GENESIS");
			}
		}
		else
		{
			gotoxy((s[xy].x * 10) + 2, (s[xy].y * 6) + 3);
			printf("No Data");
		}
		if (s[xy].shop == true && s[xy].explored == true)
		{
			gotoxy((s[xy].x * 10) + 3, (s[xy].y * 6) + 5);
			printf("STORE");
		}
	}
}

int systemCurrent(vector<systems>& t)
{
	int current;
	for (int xy = 0; xy < 100; xy++) // finding current system and saving value for later use
	{
		if (t[xy].current == true)
		{
			current = xy;
		}
	}
	return current;
}

bool intCheck(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]) == false)
		{
			return false;
		}
	}
	return true;
}

// Art Functions

void introArt()
{
	system("CLS");
	printf("                     `. ___\n");
	printf("                   __,' __`.                _..----....____\n");
	printf("       __...--.'``;.   ,.   ;``--..__     .'    ,-._    _.-'\n");
	printf("  _..-''-------'   `'   `'   `'     O ``-''._   (,;') _,'\n");
	printf(",'________________                          \\`-._`-','\n");
	printf(" `._              ```````````------...___   '-.._'-:\n");
	printf("    ```--.._      ,.                     ````--...__\\-.\n");
	printf("            `.--. `-`                       ____    |  |`\n");
	printf("              `. `.                       ,'`````.  ;  ;`\n");
	printf("                `._`.        __________   `.      \\'__/`\n");
	printf("                   `-:._____/______/___/____`.     \\  `\n");
	printf("                              |       `._    `.    \\\n");
	printf("                              `._________`-.   `.   `.___\n");
	printf("                                                 `------'`\n");
	printf("\n  _________  __           .__   .__                   \n");
	printf(" /   _____/_/  |_   ____  |  |  |  |  _____   _______ \n");
	printf(" \\_____  \\ \\   __\\_/ __ \\ |  |  |  |  \\__  \\  \\_  __ \\\n");
	printf(" /        \\ |  |  \\  ___/ |  |__|  |__ / __ \\_ |  | \\/\n");
	printf("/_______  / |__|   \\___  >|____/|____/(____  / |__|   \n");
	printf("        \\/             \\/                  \\/         \n");
	printf("__________                                            __           \n");
	printf("\\______   \\  ____    _____    ____  _____     ____  _/  |_   ______\n");
	printf(" |       _/_/ __ \\  /     \\  /    \\ \\__  \\   /    \\ \\   __\\ /  ___/\n");
	printf(" |    |   \\\\  ___/ |  Y Y  \\|   |  \\ / __ \\_|   |  \\ |  |   \\___ \\ \n");
	printf(" |____|_  / \\___  >|__|_|  /|___|  /(____  /|___|  / |__|  /____  >\n");
	printf("        \\/      \\/       \\/      \\/      \\/      \\/             \\/ \n");
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

void difficultySet(struct gm& gm)
{
	string input;
	
	printf("Difficulty:\n1: Easy\n2: Medium\n3: Hard\nInput: ");
	cin >> input;

	if (input == "1")
	{
		gm.p.difficulty = 0; // easy
	}
	else if (input == "2")
	{
		gm.p.difficulty = 1; // medium
	}
	else if (input == "3")
	{
		gm.p.difficulty = 2; // hard
	}
}

void gameStart(struct gm& gm, vector <systems>& t)
{
	string input;

	printf("Welcome adventurer! The year is 2130 and the Earth is falling apart.\n");
	_getch();
	system("CLS");
	printf("You and a team of 3 others have been selected to go on a mission that could save the world.\n");
	_getch();
	system("CLS");
	printf("You have been assigned the role of team captain and are tasked with finding a habitable world for the population of the earth. (The Genesis)\n");
	_getch();
	system("CLS");
	printf("So what say you Captain? What shall your callsign be? You can change it later.\n");
	cin >> gm.p.name;
	system("CLS");
	cout << "Captain " << gm.p.name << ", you shall be in charge of a voyager class starship, what do you wish to call it?\n";
	cin >> gm.s.name;
	system("CLS");
	printf("As the captain of your ship it's your responsibility to keep your ship and your crew alive. On top of this you must explore unknown space to discover a colonization candidate.\n");
	_getch();
	system("CLS");
	printf("We've sent many ships ahead of you, yet none have reported back sucessfully, keep your wits about you out there!\n");
	_getch();
	system("CLS");
	printf("Your voyager starship is currently equiped with just the command module, the \"bridge\" of the starship, and should be protected at all costs. \nIn the future when you've collected some resources you'll be able to build ");
	printf("more modules with the blueprints we have supplied you with.\n");
	_getch();
	system("CLS");
	printf("If you ever need help or want to save visit your ships onboard computer, located in your command module, and reopen the menu.\n");
	_getch();
	system("CLS");
	cout << "Good luck Captain " << gm.p.name << ", and make sure you come home safe!" << endl;
	_getch();
	system("CLS");
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

void help(struct gm& gm)
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
			gm.p.name = input;
		}
		else if (input == "2")
		{
			printf("Difficulty:\n1: Easy\n2: Medium\n3: Hard\nInput: ");
			cin >> input;

			difficultySet(gm);
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
	printf("Programming Support:\nEric Pace\nKian Darrington\nSlater Swart\nIssac Morine\nTucker Norris\nBrooks Sammarco\n\n");
	printf("Creative Support:\nIssac Morine\n");
	_getch();
}

void save()
{

}

void load()
{

}

void saveAndLoad()
{
	string input;

	while (1)
	{
		system("CLS");
		printf("Menu:\n1: Save\n2: Load\n3: Back\nInput: ");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			save();
		}
		else if (input == "2")
		{
			load();
		}
		else if (input == "3")
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

void mainMenu(struct gm &gm, vector <systems>& t, vector<NPC>& n)
{
	string input;

	while (1) // menu loop
	{
		system("CLS");

		menuArt();

		if (gm.inGame == false) // check to see if game has already been started
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
			gameManager(gm, t, n);
		}
		else if (input == "2") // High scores
		{
			scores();
		}
		else if (input == "3") // help
		{
			help(gm);
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
			exit(0);
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

	gotoxy(0, 0);
	system("CLS");

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
}

void worldRan(int difficulty, vector <systems>& t, vector<NPC>& n)
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

	int i = 0;

	while (i < 3)  // finding 3 random systems from ID 19-99 to be used for shops
	{
		int q = 20 + rand() % 80;
		if (t[q].shop == false && t[q].objective == false)
		{
			t[q].shop = true;
			int ran = 1 + rand() % 100;
			if (ran <= 33)
			{
				n[i].setShopID(0);
			}
			else if (ran <= 66)
			{
				n[i].setShopID(1);
			}
			else if (ran <= 99)
			{
				n[i].setShopID(2);
			}
			else if (ran == 100)
			{
				n[i].setShopID(3);
			}
			n[i].setCurrent(q);
			i++;
		}
	}
}

// Game Functions

void gameManager(struct gm& gm, vector <systems> &t, vector<NPC>& n)
{
	int encounter;

	if (!gm.inGame)
	{
		gameStart(gm, t);
		difficultySet(gm);
		worldRan(gm.p.difficulty, t, n);
		shipValues(gm);
	}
	gm.inGame = true;
	gm.inMenu = false;
	worldConstructor();
	exploredUpdater(t);
	systemInfo(t, gm);
	while (!gm.p.victory && gm.p.alive)
	{
		mapStats(gm);
		mapMenu(t, gm);
		if (gm.inMenu == true)
		{
			mainMenu(gm, t, n);
			gm.inMenu = false;
		}
		else if (gm.inShop == true)
		{
			shop(gm, n, t);
			shipValues(gm);
			worldConstructor();
			systemInfo(t, gm);
			gm.inShop = false;
		}
		else
		{
			moveUpdate(gm);
			exploredUpdater(t);
			systemInfo(t, gm);
			encounter = encounterChance(t);
			if (encounter > 0)
			{
				if (encounter == 1 || encounter == 2)
				{
					combat(gm, t, encounter);
				}
				else if (encounter == 3)
				{
					friendlyShip(gm, t);
				}
				else if (encounter == 4)
				{
					shop(gm, n, t);
					shipValues(gm);
				}
				worldConstructor();
				systemInfo(t, gm);
			}
		}
	}
	if (gm.p.victory == true)
	{
		objectiveFound(gm);
	}
	else if (gm.p.alive == false)
	{
		gameOver();
	}
	gameRestart(gm, t);
}

void shop(struct gm& gm, vector<NPC>& n, vector <systems>& t)
{
	string input;

	int current = systemCurrent(t);
	int temp;
	int shop;

	while (1)
	{
		system("CLS");
		printf("You've encountered a trader, would you like to enter dialouge?\nMenu:\n1: Yes\n2: No\nInput: ");
		cin >> input;

		if (input == "1")
		{
			for (int i = 0; i < 3; i++)
			{
				temp = n[i].getCurrent();
				if (temp == current)
				{
					shop = i;
				}
			}
			n[shop].shopMenu(gm);
		}
		else if (input == "2")
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

void moveUpdate(struct gm& gm)
{
	gm.s.fuel--;

	if (gm.s.fuel <= 0 || gm.s.health < 1)
	{
		gm.p.alive = false;
	}

	if (gm.s.health > gm.s.healthMax)
	{
		gm.s.health = gm.s.healthMax;
	}

	if (gm.s.shield < gm.s.shieldMax)
	{
		gm.s.shield += gm.s.shieldRegeneration;
		if (gm.s.shield > gm.s.shieldMax)
		{
			gm.s.shield = gm.s.shieldMax;
		}
	}
}

void gameOver()
{
	system("CLS");
	printf("You have failed your mission, and as you and your crew slowly succumb to the dangers of space, you realize you shall never know the fate of Earth, and along with it... Humanity");
	_getch();
}

void shipValues(struct gm& gm)
{
	gm.s.healthMax = gm.s.shipData[gm.s.shipID][1];
	gm.s.shieldMax = gm.s.shipData[gm.s.shipID][3];
	gm.s.shieldRegeneration = gm.s.shipData[gm.s.shipID][4];
	gm.s.modulesMax = gm.s.shipData[gm.s.shipID][6];
	gm.s.fuelMax = gm.s.shipData[gm.s.shipID][8];
}

void friendlyShip(struct gm& gm, vector <systems>& t)
{
	int current;
	int ran = rand() % (2);

	current = systemCurrent(t);

	system("CLS");
	printf("You have encounted a friendly vessle which has given you ");
	cout << t[current].addedSup;
	if (ran == 0)
	{
		printf(" supplies in hopes that you succeed in your jounrey!");
		gm.p.supplies += t[current].addedSup;
	}
	else if (ran == 1)
	{
		printf(" fuel in hopes that you succeed in your jounrey!");
		gm.s.fuel += t[current].addedSup;
	}

	_getch();
}

void combat(struct gm& gm, vector <systems>& t, int encounter)
{
	int current;

	current = systemCurrent(t);

	if (encounter == 1)
	{
		system("CLS");
		cout << "You have been boarded by " << t[current].enemies << " enemy combatants, brace for combat!";
		_getch();
	}
	else if (encounter == 2)
	{
		system("CLS");
		cout << t[current].enemies << " enemy ship has dropped out of hyperspace and engaged! brace for combat!";
		_getch();
	}

}

int encounterChance(vector <systems>&t)
{
	int current;
	int enemies = 0;
	int ran;

	int encounter;

	current = systemCurrent(t);

	ran = 1 + rand() % (10);

	if (t[current].shop == true) // shop
	{
		encounter = 4;
	}
	else if (ran <= 9 && ran > 3 && t[current].encountered == false && t[current].dangerLevel > 0) // enemies attack
	{
		ran = rand() % (2);

		if (ran == 0) // boarded
		{
			if (t[current].dangerLevel == 1)
			{
				t[current].enemies = 1 + rand() % (2);
			}
			else if (t[current].dangerLevel == 2)
			{
				t[current].enemies = 2 + rand() % (3);
			}
			else if (t[current].dangerLevel == 3)
			{
				t[current].enemies = 3 + rand() % (4);	
			}
			encounter = 1;
		}
		else if (ran == 1) // ship attack
		{
			if (t[current].dangerLevel == 3)
			{
				t[current].enemies = 1 + rand() % (2);
			}
			else
			{
				t[current].enemies = 1;
			}
			encounter = 2;
		}
		
	}
	else if (ran <= 10 && ran > 9 && t[current].encountered == false) // friendly ships with supplies
	{
		t[current].addedSup = 2 + rand() % (6);
		encounter = 3;
	}
	else // no encounter
	{
		encounter = 0;
	}

	t[current].encountered = true;

	return encounter;
}

void objectiveFound(struct gm& gm)
{
	system("CLS");
	printf("There it is, from the bridge of your ship you see it... A new hope, a candidate for life, \"I did it...\" you think to yourself.\n");
	cout << "Your name... Captain " << gm.p.name << " will be written in the history books, forever remembered as the one who saved humanity.";
	_getch();
}

void mapStats(struct gm& gm)
{
	gotoxy(120, 0);
	printf("Stats: ");
	gotoxy(120, 1);
	cout << gm.p.supplies << " Supplies";
	gotoxy(120, 2);
	cout << gm.p.health << " / " << gm.p.healthMax << " Player HP";
	gotoxy(120, 3);
	cout << gm.s.health << " / " << gm.s.healthMax << " Ship Hull";
	gotoxy(120, 4);
	cout << gm.s.shield << " / " << gm.s.shieldMax << " Ship Shield";
	gotoxy(120, 5);
	cout << gm.s.fuel << " / " << gm.s.fuelMax << " Ship Fuel";
	gotoxy(120, 6);
	cout << gm.s.modules << " / " << gm.s.modulesMax << " Ship Modules";
}

void mapMenu(vector <systems>& t, struct gm& gm)
{
	int current;
	int move = 1;

	int left = 0;
	int right = 0;
	int up = 0;
	int down = 0;
	int menu = 0;
	int store = 0;
	int getSup = 0;

	string input;

	current = systemCurrent(t);

	gotoxy(101, 0);
	printf("Menu: ");

	gotoxy(101, move);

	if (t[current].x > 0)
	{
		cout << move << ": ";
		printf("Go left");
		left = move;
		move++;
	}

	gotoxy(101, move);

	if (t[current].x < 9)
	{
		cout << move << ": ";
		printf("Go right");
		right = move;
		move++;
	}

	gotoxy(101, move);

	if (t[current].y > 0)
	{
		cout << move << ": ";
		printf("Go up");
		up = move;
		move++;
	}

	gotoxy(101, move);

	if (t[current].y < 9)
	{
		cout << move << ": ";
		printf("Go down");
		down = move;
		move++;
	}

	gotoxy(101, move);

	if (t[current].supplies > 0)
	{
		cout << move << ": ";
		printf("Collect Sup");
		getSup = move;
		move++;
	}

	gotoxy(101, move);

	if (t[current].shop == true)
	{
		cout << move << ": ";
		printf("Enter shop");
		store = move;
		move++;
	}

	gotoxy(101, move);
	cout << move << ": ";
	printf("Return to Menu");
	menu = move;
	move++;

	while (1)
	{
		gotoxy(101, move);
		printf("                ");
		gotoxy(101, move);
		printf("Input: ");
		cin >> input;

		if (move - 1 == 3)
		{
			if (input != "1" && input != "2" && input != "3")
			{
				gotoxy(101, move);
				invalidInput();
				continue;
			}
		}
		else if (move - 1 == 4)
		{
			if (input != "1" && input != "2" && input != "3" && input != "4")
			{
				gotoxy(101, move);
				invalidInput();
				continue;
			}
		}
		else if (move - 1 == 5)
		{
			if (input != "1" && input != "2" && input != "3" && input != "4" && input != "5")
			{
				gotoxy(101, move);
				invalidInput();
				continue;
			}
		}
		else if (move - 1 == 6)
		{
			if (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6")
			{
				gotoxy(101, move);
				invalidInput();
				continue;
			}
		}
		else if (move - 1 == 7)
		{
			if (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7")
			{
				gotoxy(101, move);
				invalidInput();
				continue;
			}
		}
		break;
	}

	gotoxy(101, 1);
	printf("                 ");
	gotoxy(101, 2);
	printf("                 ");
	gotoxy(101, 3);
	printf("                 ");
	gotoxy(101, 4);
	printf("                 ");
	gotoxy(101, 5);
	printf("                 ");
	gotoxy(101, 5);
	printf("                 ");
	gotoxy(101, 6);
	printf("                 ");
	gotoxy(101, 7);
	printf("                 ");
	gotoxy(101, 8);
	printf("                 ");


	if (left == stoi(input))
	{
		t[current - 1].current = true;
	}
	else if (right == stoi(input))
	{
		t[current + 1].current = true;
	}
	else if (up == stoi(input))
	{
		t[current - 10].current = true;
	}
	else if (down == stoi(input))
	{
		t[current + 10].current = true;
	}
	else if (menu == stoi(input))
	{
		gm.inMenu = true;
	}
	else if (getSup == stoi(input))
	{
		gm.p.supplies += t[current].supplies;
		t[current].supplies = 0;
	}
	else if (store == stoi(input))
	{
		gm.inShop = true;
	}

	if (left == stoi(input) || right == stoi(input) || up == stoi(input) || down == stoi(input))
	{
		t[current].current = false;
		gotoxy((t[current].x * 10) + 5, (t[current].y * 6) + 4);
		printf(" ");
	}
	
}

void gameRestart(struct gm& gm, vector <systems>& t)
{
	gm.p.victory = false;
	gm.p.alive = true;
	gm.inGame = false;
	gm.s.alive = true;

	gm.p.supplies = 20;
	gm.s.fuel = 25;
	gm.s.health = 10;
	gm.s.shield = 10;
	gm.s.modules = 1;
	gm.s.shipID = 0;
	
	for (int i = 0; i < 100; i++)
	{
		t[i].explored = false;
		t[i].encountered = false;
		t[i].current = false;
		t[i].objective = false;
		t[i].shop = false;
		t[i].enemies = 0;
		t[i].addedSup = 0;
	}
}

// Classes 

void NPC::setShopID(int s)
{
	shopID = s;
}

void NPC::setCurrent(int c)
{
	current = c;
}

int NPC::getShopID()
{
	return shopID;
}

int NPC::getCurrent()
{
	return current;
}

void NPC::shopMenu(struct gm& gm)
{
	system("CLS");
	printf("Welcome to my shop! ");

	if (shopID == 0)
	{
		generalShop(gm);
	}
	else if (shopID == 1)
	{
		shipShop(gm);
	}
	else if (shopID == 2)
	{
		weaponShop(gm);
	}
	else if (shopID == 3)
	{
		miyoshiShop(gm);
	}
}

void NPC::generalShop(struct gm& gm)
{
	string input;

	printf("I sell all sorts of general appliances\n");
}

void NPC::shipShop(struct gm& gm)
{
	string input;

	printf("I sell anything your space ship could ever need\n");
}

void NPC::weaponShop(struct gm& gm)
{
	string input;

	printf("I sell all manners of destruction.\n");
}

void NPC::miyoshiShop(struct gm& gm)
{
	string input;

	while (1)
	{
		system("CLS");
		printf("I am Mr. Miyoshi, yes, the one and only.\n1: Genesis location\n2: \n3: \n4: Back");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			printf("Ah yes... The Genesis, it's current location is \"over there\"...");
			_getch();
		}
		else if (input == "4")
		{
			break;
		}
		else
		{
			invalidInput();
		}
	}

}

void NPC::fuelPurch(struct gm& gm)
{
	string input;

	while (1)
	{
		system("CLS");
		cout << "Please enter how much fuel you want to buy (1 fuel for 1 supply) " << gm.s.fuel << " / " << gm.s.fuelMax << endl;
		printf("Menu:\nInput: ");
		cin >> input;
		system("CLS");

		bool b = intCheck(input);

		if (b == true)
		{
			if (stoi(input) <= gm.p.supplies)
			{
				if (gm.s.fuel + stoi(input) <= gm.s.fuelMax)
				{
					gm.s.fuel += stoi(input);
					gm.p.supplies -= stoi(input);
				}
				else
				{
					printf("Not enough fuel capacity...\n");
					_getch();
					continue;
				}
			}
			else
			{
				printf("Not enough supplies...\n");
				_getch();
				continue;
			}
		}
		else
		{
			invalidInput();
			continue;
		}
		break;
	}
}

void NPC::shipPurch(struct gm& gm)
{
	string input;

	while (1)
	{
		gotoxy(50, 0);
		if (gm.s.shipID < 2)
		{
			printf("Stats: ");
			gotoxy(50, 1);
			cout << gm.s.shipData[gm.s.shipID][1] << " --> " << gm.s.shipData[gm.s.shipID + 1][1] << " Max Hull";
			gotoxy(50, 2);
			cout << gm.s.shipData[gm.s.shipID][3] << " --> " << gm.s.shipData[gm.s.shipID + 1][3] << " Max Shields";
			gotoxy(50, 3);
			cout << gm.s.shipData[gm.s.shipID][4] << " --> " << gm.s.shipData[gm.s.shipID + 1][4] << " Shield Regeneration";
			gotoxy(50, 4);
			cout << gm.s.shipData[gm.s.shipID][8] << " --> " << gm.s.shipData[gm.s.shipID + 1][8] << " Max Fuel";
			gotoxy(50, 5);
			cout << gm.s.shipData[gm.s.shipID][6] << " --> " << gm.s.shipData[gm.s.shipID + 1][6] << " Max Modules";
			gotoxy(50, 6);
			cout << "Ship Level "  <<gm.s.shipID + 1 << " / 3";
		}
		else
		{
			printf("MAX LEVEL");
		}
		gotoxy(0, 0);
		printf("Are you sure you want to upgrade your ship?\nIt will cost 20 supplies\n1: Upgrade\n2: Back\nInput: ");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			if (gm.s.shipID < 2)
			{
				if (gm.p.supplies >= 20)
				{
					gm.s.shipID += 1;
					gm.p.supplies -= 20;
				}
				else
				{
					printf("Not enough supplies...");
				}
			}
			else
			{
				printf("Maximum level...");
			}
		}
		else if (input == "2")
		{
			break;
		}
		else
		{
			invalidInput();
			continue;
		}
		break;
	}
}