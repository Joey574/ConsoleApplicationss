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

using namespace std;

// Function Prototypes

void gotoxy(int x, int y);
void exploredUpdater(vector<systems>& s);
void worldRan(int difficulty, vector <systems>& t);
void gameManager(struct gm &gm, vector <systems>& t);
void mapMovement(vector <systems>& t, struct gm& gm);
void objectiveFound(struct gm& gm);
void gameRestart(struct gm& gm, vector <systems>& t);
void combat(struct gm& gm, vector <systems>& t, int encounter);
int encounterChance(vector <systems>& t);
void friendlyShip(vector <systems>& t);

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
	}
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
	printf("You have been assigned the role of team captain and are tasked with finding a habitable world for the population of the earth.\n");
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
	printf("Your voyager starship is currently equiped with just the command module, the \"bridge\" of the starship, and should be protected at all costs. In the future when you've collected some resources you'll be able to build ");
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

// Game Functions

void gameManager(struct gm& gm, vector <systems> &t)
{
	int encounter;

	if (!gm.inGame)
	{
		gameStart(gm, t);
		difficultySet(gm);
		worldRan(gm.p.difficulty, t);
		worldConstructor();
	}
	else
	{
		worldConstructor();
	}
	gm.inGame = true;
	exploredUpdater(t);
	systemInfo(t, gm);
	while (!gm.p.victory && gm.p.alive)
	{
		mapMovement(t, gm);
		exploredUpdater(t);
		systemInfo(t, gm);
		encounter = encounterChance(t);
		if (encounter == 1 || encounter == 2)
		{
			combat(gm, t, encounter);
			worldConstructor();
			systemInfo(t, gm);
		}
		else if (encounter == 3)
		{
			friendlyShip(t);
			worldConstructor();
			systemInfo(t, gm);
		}
		else if (encounter == 4)
		{

		}
	}
	if (gm.p.victory == true)
	{
		objectiveFound(gm);
	}
	else if (gm.p.alive == false)
	{

	}
	gameRestart(gm, t);
}

void friendlyShip(vector <systems>& t)
{
	int current;

	for (int i = 0; i < 100; i++)
	{
		if (t[i].current == true)
		{
			current = i;
		}
	}

	system("CLS");
	printf("You have encounted a friendly vessle which has given you ");
	cout << t[current].addedSup;
	printf(" supplies in hopes that you succeed in your jounrey!");
	_getch();
}

void combat(struct gm& gm, vector <systems>& t, int encounter)
{
	int current;

	for (int i = 0; i < 100; i++)
	{
		if (t[i].current == true)
		{
			current = i;
		}
	}

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

	for (int i = 0; i < 100; i++)
	{
		if (t[i].current == true)
		{
			current = i;
		}
	}

	ran = 1 + rand() % (10);

	if (t[current].shop == true) // shop
	{
		encounter = 4;
	}
	else if (ran <= 9 && ran > 7 && t[current].encountered == false && t[current].dangerLevel > 0) // enemies attack
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

void mapMovement(vector <systems>& t, struct gm& gm)
{
	int current;
	int move = 1;

	int left = 0;
	int right = 0;
	int up = 0;
	int down = 0;

	string input;

	for (int xy = 0; xy < 100; xy++) // finding current system and saving value for later use
	{
		if (t[xy].current == true)
		{
			current = xy;
		}
	}

	gotoxy(101, 0);
	printf("Menu: ");
	gotoxy(120, 0);
	printf("Stats: ");
	gotoxy(120, 1);
	cout << gm.p.supplies;
	gotoxy(120, 2);
	cout << gm.p.health << " / " << gm.p.healthMax;

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

	while (1)
	{
		gotoxy(101, move);
		printf("                ");
		gotoxy(101, move);
		printf("Input: ");
		cin >> input;

		if (move - 1 == 2)
		{
			if (input != "1" && input != "2")
			{
				gotoxy(101, move);
				invalidInput();
				continue;
			}
		}
		else if (move - 1 == 3)
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
		break;
	}

	gotoxy(101, 1);
	printf("           ");
	gotoxy(101, 2);
	printf("           ");
	gotoxy(101, 3);
	printf("           ");
	gotoxy(101, 4);
	printf("           ");
	gotoxy(101, 5);
	printf("           ");

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

	t[current].current = false;
	gotoxy((t[current].x * 10) + 5, (t[current].y * 6) + 4);
	printf(" ");
}

void gameRestart(struct gm& gm, vector <systems>& t)
{
	gm.p.victory = false;
	gm.p.alive = true;
	gm.inGame = false;
	
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