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

using namespace std;
using namespace std::this_thread; // needed for sleep for
using namespace std::chrono; // needed for sleep for

#include "Player.h"
#include "Functions.h"
#include "WorldGeneration.h"

void mainMenu(struct player& player, struct ship& ship, vector <int> vectorScore, int& score, bool &inGame);
void gameStart(struct player &p, struct ship &s);

int main()
{
	player player;
	ship ship;
	module module;
	string input;

	int score;

	bool inGame = false;

	vector <int> vectorScore;

	fstream saveFile;
	fstream highScores;

	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

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
	 printf("\nBy: Joey Soroka\n");
	 _getch();

	mainMenu(player, ship, vectorScore, score, inGame);
	
	
	return 0;
}

void mainMenu(struct player &player, struct ship &ship, vector <int> vectorScore, int &score, bool &inGame)
{
	fstream saveFile;
	fstream highScores;

	string input;
	string temp;
	string saveName;

	int ascX = 25;
	int ascY = 5;
	
	while (1)
	{
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
		if (inGame == false) // check to see if game has already been started
		{
			printf("Menu:\n1: Start Game\n2: High Scores\n3: Help\n4: Credits\n5: Save/Load\n6: Exit\nInput: "); // not started
		}
		else
		{
			printf("Menu:\n1: Resume Game\n2: High Scores\n3: Help\n4: Credits\n5: Save/Load\n6: Exit\nInput: "); // has started
		}

		cin >> input;
		system("CLS");

		if (input == "1") // start or resume game
		{
			if (inGame == false) // check to see if game has already been started
			{
				gameStart(player, ship);
				inGame = true;
			}
			break;
		}
		else if (input == "2") // high scores, add possibility to see details about high scores in the future
		{
			printf("Top 10 High Scores:\n");

			highScores.open("highScores.txt");

			if (!highScores.is_open())
			{
				printf("File not found");
			}

			vectorScore.clear();
			while (getline(highScores, temp))
			{
				score = stoi(temp); // turns temp line from highScores.txt into int
				vectorScore.push_back(score);
			}
			sort(vectorScore.rbegin(), vectorScore.rend()); // sorts the scores in vector from highest to lowest

			for (int i = 1; i < 11; i++)
			{
				cout << i << ") " << vectorScore[i - 1] << endl; // outputs top 10 high scores
			}

			highScores.close();
			_getch();
		}
		else if (input == "3") // help
		{
			printf("Menu:\n1: Account\n2: Difficulty\n3: Reset High Scores\n4: Back\nInput: ");
			cin >> input;
			system("CLS");
			if (input == "1") // account
			{
				printf("Menu:\n1: Change name\n2: Back\nInput: ");
				cin >> input;
				if (input == "1") // change name
				{
					printf("Please enter new name: ");
					cin >> player.name;
					continue;
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
			else if (input == "2") // difficulty
			{
				printf("Difficulty:\n1: Easy\n2: Medium\n3: Hard\nInput: ");
				cin >> input;


				while (input != "1" && input != "2" && input != "3" && input != "4")
				{
					printf("Invalid input try again\nInput: ");
					cin >> input;
				}
				if (input == "4")
				{
					continue;
				}
				player.difficulty = stoi(input);
				continue;
			}
			else if (input == "3") // reset high scores
			{
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
				continue;
			}
			else
			{
				invalidInput();
				continue;
			}
		}
		else if (input == "4") // credits
		{
			printf("Author:\nJoey Soroka\n\nProgramming Support:\nEric Pace\nKian Darrington\nSlater Swart\nIssac Morine\nTucker Norris\n\nCreative Support:\nIssac Morine\n");
			_getch();
		}
		else if (input == "5") // save / load
		{

			printf("Menu:\n1: Save\n2: Load\n3: Back\nInput: ");
			cin >> input;
			system("CLS");

			if (input == "1" || input == "2")
			{
				if (input == "1")
				{
					printf("Save slots:\n");
				}
				else
				{
					printf("Load save:\n");
				}

				for (int i = 1; i < 4; i++)
				{
					if (i == 1)
					{
						saveFile.open("save1.txt");
					}
					else if (i == 2)
					{
						saveFile.open("save2.txt");
					}
					if (i == 3)
					{
						saveFile.open("save3.txt");
					}
					if (!saveFile.is_open())
					{
						printf("File not found\n");
					}
					for (int p = 0; p < 1; p++)
					{
						getline(saveFile, temp);
						if (temp == "empty")
						{
							cout << i << ": Empty\n";
						}
						else
						{
							cout << i << "Save " << i;
						}
						saveFile.close();
					}

				}		

				printf("4: Back\nInput: "); // no cin because branches were previously decided by input but shared first part of code and old input is still needed for if
				if (input == "1") // save
				{
					cin >> input;
					if (input == "1")
					{
						saveName = "save1.txt";
					}
					else if (input == "2")
					{
						saveName = "save2.txt";
					}
					else if (input == "3")
					{
						saveName = "save3.txt";
					}
					else if (input == "4")
					{
						continue;
					}
					else
					{
						invalidInput();
						continue;
					}

				}
				else // load
				{
					cin >> input;
					if (input == "1")
					{
						saveName = "save1.txt";
					}
					else if (input == "2")
					{
						saveName = "save2.txt";
					}
					else if (input == "3")
					{
						saveName = "save3.txt";
					}
					else if (input == "4")
					{
						continue;
					}
					else
					{
						invalidInput();
						continue;
					}

				}
				

					
			}
			else if (input == "3")
			{
				continue;
			}
			else
			{
				invalidInput();
				continue;
			}

		}
		else if (input == "6") // exit
		{
		if (inGame == false)
			{
			exit(0);
			}
		else
		{
			printf("Are you sure? Unsaved progress will be lost. Consider saving first\n1: Exit without saving\n2: Cancel\nInput: "); // add "exit with saving" option in future that calls a save function
			cin >> input;
			if (input == "1") // exit without saving
			{
				inGame = false;
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
		else
		{
			invalidInput();
			continue;
		}
	}
}

void mapMenu(vector <systems>& s)
{
	gotoxy(101, 2);
	printf("Menu: ");

	for (int xy = 0; xy < 100; xy++)
	{
		if (s[xy].current == true)
		{
			gotoxy((s[xy].x * 10) + 2, (s[xy].y * 6) + 4);
			printf("Current");
			gotoxy((s[xy].x * 10) + 4, (s[xy].y * 6) + 5);
			printf("POS");
		}
	}
}

void gameStart(struct player &p, struct ship &s)
{
	string input;
	vector <int> worldSeed;
	vector <systems> sy(100);

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


	while (input != "1" && input != "2" && input != "3")
	{
		printf("Invalid input try again\nInput: ");
		cin >> input;
	}
	
	p.difficulty = stoi(input);

	world(p.difficulty, worldSeed, sy);

	worldConstructor(sy, p.difficulty, worldSeed);

	exploredUpdater(sy);
}