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
void worldRan(int difficulty, vector <systems>& t);
void gameManager(struct gm &gm, vector <systems>& t);
void mapMenu(vector <systems>& t, struct gm& gm);
void objectiveFound(struct gm& gm);
void gameRestart(struct gm& gm, vector <systems>& t);
int encounterChance(vector <systems>& t);
void friendlyShip(struct gm& gm, vector <systems>& t);
void gameOver();
void moveUpdate(struct gm& gm);
void shipValues(struct gm& gm);
void shopRan(class NPC& n, vector <systems>& t);
void mapStats(struct gm& gm);
void weaponValues(struct gm& gm);

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

string upper(string s)
{
	string p = "";

	for (int i = 0; i < s.length(); i++)
	{
		p += toupper(s[i]);
	}
	return p;
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
	
	while (1)
	{
		printf("Difficulty:\n1: Easy\n2: Medium\n3: Hard\nInput: ");
		cin >> input;

		if (input.size() > 1)
		{
			invalidInput();
			system("CLS");
			continue;
		}

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
		else
		{
			invalidInput();
			system("CLS");
			continue;
		}
		break;
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
	printf("Programming Support:\nEric Pace\nKian Darrington\nSlater Swart\nIssac Morine\nTucker Norris\nBrooks Sammarco\nMonte Long\n\n");
	printf("Creative Support:\nIssac Morine\nMonte Long\n");
	_getch();
}

void save()
{
	string input;
	string temp;
	ifstream in;

	system("CLS");
	printf("Menu:\n");

	in.open("save1.txt");

	getline(in, temp, ' ');

	cout << "1: " << temp << endl;

	in.close();
	in.open("save2.txt");

	getline(in, temp, ' ');

	cout << "2: " << temp << endl;

	in.close();
	in.open("save3.txt");

	getline(in, temp, ' ');

	cout << "3: " << temp << endl;

	in.close();

	printf("4: Back\nInput: ");
	cin >> input;
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

void mainMenu(struct gm &gm, vector <systems>& t)
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
			gameManager(gm, t);
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

void worldRan(int difficulty, vector <systems>& t)
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
}

void shopRan(class NPC &n, vector <systems>& t)
{
	int i = 0;

	vector <int> id;
	vector <int> c;

	while (i < 6)  // finding 6 random systems from ID 19-99 to be used for shops
	{
		int q = 20 + rand() % 80;
		if (t[q].shop == false && t[q].objective == false)
		{
			t[q].shop = true;
			int ran = 1 + rand() % 100;
			if (ran <= 33)
			{
				id.push_back(0);
			}
			else if (ran <= 66)
			{
				id.push_back(1);
			}
			else if (ran <= 99)
			{
				id.push_back(2);
			}
			else if (ran == 100)
			{
				id.push_back(3);
			}
			c.push_back(q);
			i++;
		}
	}

	n.setShopID(id);
	n.setCurrent(c);
}

// Game Functions

void gameManager(struct gm& gm, vector <systems> &t)
{
	combat c;
	NPC n;

	int encounter;

	if (!gm.inGame)
	{
		gameStart(gm, t);
		difficultySet(gm);
		worldRan(gm.p.difficulty, t);
		shopRan(n, t);
		shipValues(gm);
		weaponValues(gm);
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
			mainMenu(gm, t);
			gm.inMenu = false;
		}
		else if (gm.inShop == true)
		{
			n.shopManager(gm, t);
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
					c.setComType(encounter - 1);
					c.setEnemies(t[systemCurrent(t)].enemies);
					c.combatManager(gm);
				}
				else if (encounter == 3)
				{
					friendlyShip(gm, t);
				}
				else if (encounter == 4)
				{
					n.shopManager(gm, t);
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

void moveUpdate(struct gm& gm)
{
	gm.s.fuel--;

	if (gm.s.fuel <= 0 || gm.s.health < 1)
	{
		gm.p.alive = false;
	}

	if (gm.s.fuel > gm.s.fuelMax)
	{
		gm.s.fuel = gm.s.fuelMax;
	}

	if (gm.s.health > gm.s.healthMax)
	{
		gm.s.health = gm.s.healthMax;
	}

	if (gm.s.shield < gm.s.shieldMax)
	{
			gm.s.shield = gm.s.shieldMax;	
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

void weaponValues(struct gm& gm)
{
	weaponData temp;

	for (int i = 0; i < 10; i++)
	{
		gm.wD.push_back(temp);
		gm.wD[i].type = i;
	}

	gm.wD[0].minDamage = 2;
	gm.wD[0].maxDamage = 2;
	gm.wD[0].accuracy = 0.8;
	gm.wD[0].shots = 5;
	gm.wD[0].name = "Machine Gun";

	gm.wD[1].minDamage = 4;
	gm.wD[1].maxDamage = 8;
	gm.wD[1].accuracy = 0.6;
	gm.wD[1].shots = 1;
	gm.wD[1].name = "Heavy Cannon";

	gm.wD[2].minDamage = 2;
	gm.wD[2].maxDamage = 4;
	gm.wD[2].accuracy = 0.7;
	gm.wD[2].shots = 2;
	gm.wD[2].name = "Light Cannon";

	gm.wD[3].minDamage = 1;
	gm.wD[3].maxDamage = 1;
	gm.wD[3].accuracy = 0.1;
	gm.wD[3].shots = 50;
	gm.wD[3].name = "PD Cannon";

	gm.wD[4].minDamage = 3;
	gm.wD[4].maxDamage = 4;
	gm.wD[4].accuracy = 1;
	gm.wD[4].shots = 4;
	gm.wD[4].name = "Missile Launcher";

	gm.wD[5].minDamage = 1;
	gm.wD[5].maxDamage = 3;
	gm.wD[5].accuracy = 1;
	gm.wD[5].shots = 2;
	gm.wD[5].name = "Phase Cannon";

	gm.wD[6].minDamage = 3;
	gm.wD[6].maxDamage = 4;
	gm.wD[6].accuracy = 0.7;
	gm.wD[6].shots = 2;
	gm.wD[6].name = "Coilgun";

	gm.wD[7].minDamage = 5;
	gm.wD[7].maxDamage = 7;
	gm.wD[7].accuracy = 0.5;
	gm.wD[7].shots = 1;
	gm.wD[7].name = "Torpedo";

	gm.wD[8].minDamage = 2;
	gm.wD[8].maxDamage = 3;
	gm.wD[8].accuracy = 0.7;
	gm.wD[8].shots = 1;
	gm.wD[8].name = "Railgun";

	gm.wD[9].minDamage = 2;
	gm.wD[9].maxDamage = 4;
	gm.wD[9].accuracy = 1;
	gm.wD[9].shots = 2;
	gm.wD[9].name = "Beam cannon";
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
				t[current].enemies = 1 + rand() % (3);
			}
			else if (t[current].dangerLevel == 2)
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
	int aces = 1;
	int menu = 0;
	int store = 0;
	int getSup = 0;

	bool l = false;
	bool r = false;
	bool u = false;
	bool d = false;

	string input;

	current = systemCurrent(t);

	gotoxy(101, 0);
	printf("Menu: ");

	gotoxy(101, move);

	if (t[current].x > 0)
	{
		cout << "A: ";
		printf("Go left");
		l = true;
		move++;
	}

	gotoxy(101, move);

	if (t[current].x < 9)
	{
		cout << "D: ";
		printf("Go right");
		r = true;
		move++;
	}

	gotoxy(101, move);

	if (t[current].y > 0)
	{
		cout << "W: ";
		printf("Go up");
		u = true;
		move++;
	}

	gotoxy(101, move);

	if (t[current].y < 9)
	{
		cout << "S: ";
		printf("Go down");
		d = true;
		move++;
	}

	gotoxy(101, move);

	if (t[current].supplies > 0)
	{
		cout << aces << ": ";
		printf("Collect Sup");
		getSup = aces;
		move++;
		aces++;
	}

	gotoxy(101, move);

	if (t[current].shop == true)
	{
		cout << aces << ": ";
		printf("Enter shop");
		store = aces;
		move++;
		aces++;
	}

	gotoxy(101, move);
	cout << aces << ": ";
	printf("Return to Menu");
	menu = aces;
	move++;

	while (1)
	{
		gotoxy(101, move);
		printf("                ");
		gotoxy(101, move);
		printf("Input: ");
		cin >> input;

		if (input.size() > 1)
		{
			gotoxy(101, move);
			invalidInput();
			continue;
		}

		if (intCheck(input) == false)
		{
			input = upper(input);
		}

		if (input != "W" && input != "A" && input != "S" && input != "D")
		{
			if (stoi(input) > aces || stoi(input) < 0)
			{
				gotoxy(101, move);
				invalidInput();
				continue;
			}
		}

		if (input == "W" && u == true)
		{
			t[current - 10].current = true;
			t[current].current = false;
			gotoxy((t[current].x * 10) + 5, (t[current].y * 6) + 4);
			printf(" ");
		}
		else if (input == "A" && l == true)
		{
			t[current - 1].current = true;
			t[current].current = false;
			gotoxy((t[current].x * 10) + 5, (t[current].y * 6) + 4);
			printf(" ");
		}
		else if (input == "S" && d == true)
		{
			t[current + 10].current = true;
			t[current].current = false;
			gotoxy((t[current].x * 10) + 5, (t[current].y * 6) + 4);
			printf(" ");
		}
		else if (input == "D" && r == true)
		{
			t[current + 1].current = true;
			t[current].current = false;
			gotoxy((t[current].x * 10) + 5, (t[current].y * 6) + 4);
			printf(" ");
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
		else
		{
			gotoxy(101, move);
			invalidInput();
			continue;
		}

		break;
	}

		gotoxy(101, 1);
		printf("                   ");
		gotoxy(101, 2);
		printf("                   ");
		gotoxy(101, 3);
		printf("                   ");
		gotoxy(101, 4);
		printf("                   ");
		gotoxy(101, 5);
		printf("                   ");
		gotoxy(101, 5);
		printf("                   ");
		gotoxy(101, 6);
		printf("                   ");
		gotoxy(101, 7);
		printf("                   ");
		gotoxy(101, 8);
		printf("                   ");
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

// Shop Class

void NPC::setShopID(vector <int> s)
{
	for (int i = 0; i < s.size(); i++)
	{
		sh.push_back(temp);
		sh[i].shopID = s[i];
	}
}

void NPC::setCurrent(vector <int> c)
{
	for (int i = 0; i < c.size(); i++)
	{
		sh[i].current = c[i];
	}
}

void NPC::shopManager(struct gm &gm, vector<systems> &t)
{

	int current = systemCurrent(t);
	int shopCID;

	for (int i = 0; i < 6; i++)
	{
		if (current == sh[i].current)
		{
			shopCID = i;
		}
	}

	if (sh[shopCID].shopID == 0)
	{
		generalShop(gm);
	}
	else if (sh[shopCID].shopID == 1)
	{
		shipShop(gm);
	}
	else if (sh[shopCID].shopID == 2)
	{
		weaponShop(gm);
	}
	else if (sh[shopCID].shopID == 3)
	{
		miyoshiShop(gm);
	}


}

void NPC::generalShop(struct gm& gm)
{
	string input;

	while (1)
	{
		system("CLS");
		
		printf("This is a general shop for all your general purchasing needs!\nMenu:\n1: Fuel\n2: Weapons\n3: Back\nInput: ");
		cin >> input;

		if (input == "1")
		{
			fuelPurch(gm);
		}
		else if (input == "2")
		{
			
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

void NPC::shipShop(struct gm& gm)
{
	string input;

	while (1)
	{
		system("CLS");

		printf("This is a ship shop for all your ship purchasing needs!\nMenu:\n1: Fuel\n2: Better Ship\n3: Back\nInput: ");
		cin >> input;

		if (input == "1")
		{

		}
	}
}

void NPC::weaponShop(struct gm& gm)
{
	string input;

	while (1)
	{
		system("CLS");

		printf("This is a weapon shop for all your genocidal needs!\nMenu:\n1: Fuel\n2: Weapons\n3: Back\nInput: ");
		cin >> input;

		if (input == "1")
		{

		}
	}
}

void NPC::miyoshiShop(struct gm& gm)
{
	string input;

	while (1)
	{
		system("CLS");

		printf("Hello... I am Miyoshi, many travelers come to me for help in their journey, what do you desire young traveler?\nMenu: ");
		cin >> input;
	}
}

void NPC::fuelPurch(struct gm& gm)
{
	string input;

	while (1)
	{
		system("CLS");

		printf("Menu: (Enter how much fuel you want 1:1 purchase)\nBack: S\nInput: ");
		cin >> input;

		
		if (intCheck(input) == false)
		{
			if (toupper(input[0]) == 'S')
			{
				break;
			}
			else
			{
				invalidInput();
				continue;
			}
		}
		else
		{
			if (stoi(input) > gm.p.supplies || stoi(input) + gm.s.fuel > gm.s.fuelMax)
			{
				invalidInput();
				continue;
			}
			else
			{
				gm.s.fuel += stoi(input);
				gm.p.supplies -= stoi(input);

				system("CLS");
				printf("Succesful Purchase! Press any key to continue");
				_getch();
				break;
			}
		}
		
	}
}

void NPC::shipPurch(struct gm& gm)
{
	
}

void NPC::statDisplay(struct gm& gm)
{
	gotoxy(0, 50);
	printf("Resources:");
	gotoxy(1, 50);
	cout << "Supplies: " << gm.p.supplies;
	gotoxy(2, 50);
	cout << "Fuel: " << gm.s.fuel << "/" << gm.s.fuelMax;
	gotoxy(3, 50);
	printf("Stats:");
	gotoxy(4, 50);
	cout << "HP: " << gm.s.health << "/" << gm.s.healthMax;
	gotoxy(5, 50);
	cout << "Shield: " << gm.s.shield << "/" << gm.s.shieldMax;
	gotoxy(6, 50);
	cout << "Shield Regen: " << gm.s.shieldRegeneration;
	gotoxy(7, 50);
	cout << "Modules: " << gm.s.modules << "/" << gm.s.modulesMax;
}

// Combat Class

void combat::setComType(int c)
{
	comType = c;
}

void combat::setEnemies(int e)
{
	enemies = e;
}

void combat::combatManager(struct gm& gm)
{
	system("CLS");
	enemyTypes();
	if (comType == 0) // ground
	{
		groundIntro();
		gStats();
	}
	else if (comType == 1) // space
	{
		spaceIntro();
		sStats();

		while (enemies >= 1 && gm.s.alive)
		{
			sCombat(gm);
		}
	}
}

void combat::gStats()
{
	for (int i = 0; i < enemies; i++)
	{
		if (cm.eg[i].type == 0)
		{

		}
	}
}

void combat::sStats()
{
	for (int i = 0; i < enemies; i++)
	{
		if (cm.es[i].type == 0) // corvette
		{
			cm.es[i].health = 5;
			cm.es[i].healthMax = 5;
			cm.es[i].maxDamage = 2;
			cm.es[i].minDamge = 0;
			cm.es[i].weapons = 1;
			cm.es[i].evasion = 0.4;
			cm.es[i].accuracy = 0.7;
		}
		else if (cm.es[i].type == 1) // destroyer
		{
			cm.es[i].health = 10;
			cm.es[i].healthMax = 10;
			cm.es[i].maxDamage = 3;
			cm.es[i].minDamge = 1;
			cm.es[i].weapons = 2;
			cm.es[i].evasion = 0.3;
			cm.es[i].accuracy = 0.8;
		}
		else if (cm.es[i].type == 2) // cruiser
		{
			cm.es[i].health = 12;
			cm.es[i].healthMax = 12;
			cm.es[i].maxDamage = 2;
			cm.es[i].minDamge = 0;
			cm.es[i].weapons = 1;
			cm.es[i].evasion = 0.2;
			cm.es[i].accuracy = 1;
		}
		else if (cm.es[i].type == 3) // batleship
		{
			cm.es[i].health = 15;
			cm.es[i].healthMax = 15;
			cm.es[i].maxDamage = 2;
			cm.es[i].minDamge = 0;
			cm.es[i].weapons = 1;
			cm.es[i].evasion = 0;
			cm.es[i].accuracy = 0.8;
		}
		else if (cm.es[i].type == 4) // assault carrier
		{
			cm.es[i].health = 12;
			cm.es[i].healthMax = 12;
			cm.es[i].maxDamage = 1;
			cm.es[i].minDamge = 1;
			cm.es[i].weapons = 8;
			cm.es[i].evasion = 0.1;
			cm.es[i].accuracy = 0.8;
		}
	}
}

void combat::enemyTypes()
{
	for (int i = 0; i < enemies; i++)
	{
		if (comType == 0) // ground
		{
			cm.eg.push_back(enemGround);
			cm.eg[i].ID = i + 1;
		}
		else if (comType == 1) // space
		{
			cm.es.push_back(enemShip);
			cm.es[i].ID = i + 1;
		}
	}

	enemyRace = rand() % 5;

	if (enemyRace == 0)
	{
		enemRaceName = "Androidus";
	}
	else if (enemyRace == 1)
	{
		enemRaceName = "Zorgons";
	}
	else if (enemyRace == 2)
	{
		enemRaceName = "Nalites";
	}
	else if (enemyRace == 3)
	{
		enemRaceName = "Quotis";
	}
	else if (enemyRace == 4)
	{
		enemRaceName = "Refips";
	}

	for (int i = 0; i < enemies; i++)
	{
		if (comType == 0) // ground
		{
			cm.eg[i].type = rand() % 4;

			if (cm.eg[i].type == 0)
			{
				cm.eg[i].enemTypeName = "Trooper";
			}
			else if (cm.eg[i].type == 1)
			{
				cm.eg[i].enemTypeName = "Gunner";
			}
			else if (cm.eg[i].type == 2)
			{
				cm.eg[i].enemTypeName = "Warrior";
			}
			else if (cm.eg[i].type == 3)
			{
				cm.eg[i].enemTypeName = "Officer";
			}
		}
		else if (comType == 1) // space
		{
			cm.es[i].type = rand() % 5;

			if (cm.es[i].type == 0)
			{
				cm.es[i].enemTypeName = "Corvette";
			}
			else if (cm.es[i].type == 1)
			{
				cm.es[i].enemTypeName = "Destroyer";
			}
			if (cm.es[i].type == 2)
			{
				cm.es[i].enemTypeName = "Cruiser";
			}
			if (cm.es[i].type == 3)
			{
				cm.es[i].enemTypeName = "Battleship";
			}
			if (cm.es[i].type == 4)
			{
				cm.es[i].enemTypeName = "Assault Carrier";
			}
		}
	}




} 

void combat::groundIntro()
{
	int t = 0;
	int g = 0;
	int w = 0;
	int o = 0;

	cout << "You are being boarded by " << enemies << " " << enemRaceName << endl;
	printf("\nCombatants:\n");
	
	for (int i = 0; i < enemies; i++)
	{
		if (cm.eg[i].type == 0)
		{
			t++;
		}
		else if (cm.eg[i].type== 1)
		{
			g++;
		}
		if (cm.eg[i].type == 2)
		{
			w++;
		}
		if (cm.eg[i].type == 3)
		{
			o++;
		}
	}

	if (t > 0)
	{
		cout << t;
		if (t > 1)
		{
			printf(" Troopers\n");
		}
		else
		{
			printf(" Trooper\n");
		}
	}
	if (g > 0)
	{
		cout << g;
		if (g > 1)
		{
			printf(" Gunners\n");
		}
		else
		{
			printf(" Gunner\n");
		}
	}
	if (w > 0)
	{
		cout << w;
		if (w > 1)
		{
			printf(" Warriors\n");
		}
		else
		{
			printf(" Warrior\n");
		}
	}
	if (o > 0)
	{
		cout << o;
		if (o > 1)
		{
			printf(" Officers\n");
		}
		else
		{
			printf(" Officer\n");
		}
	}

	_getch();
	
}

void combat::spaceIntro()
{
	int c = 0;
	int d = 0;
	int cr = 0;
	int b = 0;
	int ac = 0;

	cout << enemies << " " << enemRaceName << " ships are dropping out of hyperspace, weapons hot!" << endl;
	printf("\nCombatants:\n");

	for (int i = 0; i < enemies; i++)
	{
		if (cm.es[i].type == 0)
		{
			c++;
		}
		else if (cm.es[i].type == 1)
		{
			d++;
		}
		else if (cm.es[i].type == 2)
		{
			cr++;
		}
		else if (cm.es[i].type == 3)
		{
			b++;
		}
		else if (cm.es[i].type == 4)
		{
			ac++;
		}
	}

	if (c > 0)
	{
		cout << c;
		if (c > 1)
		{
			printf(" Corvettes\n");
		}
		else
		{
			printf(" Corvette\n");
		}
	}
	if (d > 0)
	{
		cout << d;
		if (d > 1)
		{
			printf(" Destroyers\n");
		}
		else
		{
			printf(" Destroyer\n");
		}
	}
	if (cr > 0)
	{
		cout << cr;
		if (cr > 1)
		{
			printf(" Cruisers\n");
		}
		else
		{
			printf(" Cruiser\n");
		}
	}
	if (b > 0)
	{
		cout << b;
		if (b > 1)
		{
			printf(" Battleships\n");
		}
		else
		{
			printf(" Battleship\n");
		}
	}
	if (ac > 0)
	{
		cout << ac;
		if (ac > 1)
		{
			printf(" Assault Carriers\n");
		}
		else
		{
			printf(" Assault Carrier\n");
		}
	}

	_getch();

}

void combat::sCombat(struct gm& gm)
{
	string input;

	vector <int> d;
	vector <bool> h;

	int temp = 1;
	int damage = 0;
	int enemyAttack;
	int weaponU;
	int shotsHit = 0;
	float cTH;
	float fTemp;

	while (1)
	{
		system("CLS");
		printf("Menu:\n\nAttack:\n");

		for (int i = 0; i < enemies; i++)
		{
			cout << cm.es[i].ID << ": " << cm.es[i].enemTypeName << " " << cm.es[i].health << "/" << cm.es[i].healthMax << " HP" << endl;
		}

		printf("Input: ");
		cin >> input;

		if (intCheck(input))
		{
			for (int i = 0; i < enemies; i++)
			{
				if (stoi(input) == cm.es[i].ID)
				{
					enemyAttack = stoi(input) - 1;
					while (1)
					{
						system("CLS");
						printf("Menu:\n\nWeapons:\n");
						for (int i = 0; i < gm.s.weapons; i++)
						{
							cout << i + 1 << ": " << gm.wD[gm.s.wID[i]].name << endl;
						}
						printf("Input: ");
						cin >> input;

						if (intCheck(input))
						{
							if (stoi(input) > gm.s.weapons)
							{
								invalidInput();
								continue;
							}

							weaponU = gm.wD[gm.s.wID[stoi(input) - 1]].type;

							for (int i = 0; i < gm.wD[weaponU].shots; i++)
							{

								damage = gm.wD[weaponU].minDamage + rand() % 1 + (gm.wD[weaponU].maxDamage - gm.wD[weaponU].minDamage);

								d.push_back(damage);
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
				else if (temp > enemies)
				{
					invalidInput();
					continue;
				}
				else
				{
					temp++;
				}
			}
		}
		else
		{
			invalidInput();
			continue;
		}
		break;
	}

	for (float i = 0; i < gm.wD[weaponU].shots; i+= 1)
	{
		cTH = (gm.wD[weaponU].accuracy - cm.es[enemyAttack].evasion) + (i / 100);

		fTemp = rand() % 101;
		fTemp /= 100;

		if (cTH > fTemp)
		{
			shotsHit += 1;
			h.push_back(true);
		}
		else
		{
			h.push_back(false);
		}
	}

	damage = 0;

	system("CLS");
	if (shotsHit >= 1)
	{
		cout << "Hit! ";
		
		if (shotsHit >= 2)
		{
			cout << shotsHit << " Shots hit their target! ";
		}
		else
		{
			cout << shotsHit << " Shot hit its target! ";
		}

		for (int i = 0; i < gm.wD[weaponU].shots; i++)
		{
			if (h[i] == true)
			{
				damage += d[i];
			}
		}

		cout << "Dealing a total of " << damage << " damage.";
		cm.es[enemyAttack].health -= damage;

		if (cm.es[enemyAttack].health <= 0)
		{
			cout << " Destroying the " << cm.es[enemyAttack].enemTypeName << endl;
			cm.es[enemyAttack].alive = false;
			enemies--;
		}
	}
	else
	{
		printf("Shot has missed, no damage dealt\n");
	}
	_getch();
}