/*
Author: Joey Soroka
Project Name: RPG
File Name: RPG.cpp
Purpose: Simple RPG 
Pseudocode:
Maintenance Log:
9/9/21:		Added Introductory code and variables
9/10/21:	Attempting to set up main screen
9/13/21:	Attempting to set up player input
9/16/21:	Still working on player input, managed to get player input, setting up introduction
9/17/21:	Added character stats, have not initialized them yet
9/20/21:	Finished character stats, gonna work on character equipment next
			sctracth that, working on organization and transfering ints from functions to main and vice versa
9/21/21:	Working on header file, absolute chaos, simplified code with help of tucker, made it out of the dark ages, code works, no functions though );
9/23/21:	Working on setters and getters to allow variables to be set and gotten throughout the code, so far going well, much better than any other atempt
9/24/21:	While setters and getters are great they don't do exactly what I want them to do, went back to passing by refference, got it to work, set up callBack function
			and set up while loop for characterSelection
9/26/21:	Setting up equipment selection, going to be a long one though, currently just set up indtroduction for knight and set it up in a function.
			planning on creating a funciton for each different class
9/28/21:	Working on equipment selection, got rid of about 100 lines of code, going to redesign the whole thing, should be much more streamlined this way however, and
			much much more do-able.
10/14/21:	Changed out individual character stat variables into an array, same with character type
10/15/21:	Working on equipment selection, I've got the 3 universal armor types set up as well as the 2 unique armor types for knight
10/16/21:	Added 3 universal armor classes available to all, currently working on finding 2 unique armor types for each class
*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>

using namespace std;


void introduction(string playerName)  // Says hello to user and gives intoduction
{

	cout << "Hello " << playerName << "! We need your help. The world is in peril." << endl;
	printf("You are our last hope.\nPress any key to continue\n");

	_getch(); 

	system("CLS"); 

	printf("The year is 1257, hordes of goblins and ogres have swarmed a once peaceful realm, and only you, ");
	cout << playerName << endl;
	printf("a noble from a long forgotten land, holds the key to salvation.\nPress any key to continue\n");

	_getch();

	system("CLS");

	printf("What can only be described as a gate to hell has opened deep undergrund,\nunleashing swarms of monsters of your worst nightmares.\n");
	printf("Hundreds, no THOUSANDS, have tried to close said gate, however none have succeeded.\nYou have been called upon by your king to dispatch of this threat.\nPress any key to continue\n");

	_getch();

	system("CLS");

}

void callBack()
{
	system("CLS");

	printf("Incorrect input detected\nPress any key to continue\n");

	_getch();

	system("CLS");

}

void characterSelection(int (&characterStats)[7], string playerName, bool (&characterType)[5])
{
	string input;
	int luckMin = 1;
	int luckMax = 10;
	bool reselectChar = true;

	system("CLS");

	while (reselectChar = true)
	{
		printf("\t\t\tCHOOSE YOUR CHARACTER\n1. Knight \t 2. Calvary \t 3. Spearman \t 4. Archer \t 5. Swordsman\n");

		cin >> input;

		if (input == "1")
		{
			characterStats[0] = 8;
			characterStats[1] = 3;
			characterStats[2] = 9;
			characterStats[3] = 7;
			characterStats[4] = 4;
			characterStats[5] = 2;
			characterStats[6] = luckMin + rand() % (luckMax - luckMin + 1);
			
			characterType[0] = true;

			system("CLS");

			printf("You have chosen knight\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", characterStats[0]);
			printf("Perception: %i\n", characterStats[1]);
			printf("Endurance: %i\n", characterStats[2]);
			printf("Charisma: %i\n", characterStats[3]);
			printf("Intelligence: %i\n", characterStats[4]);
			printf("Agility: %i\n", characterStats[5]);
			printf("Luck: %i\n", characterStats[6]);
			printf("SPECIAL ABILITY: During times of need a knight can pray for a random gift from the heavens.\n\n");
			printf("Good luck on your quest, I know not what you will encounter nor what you must do.\nHowever I have heard rumors that the bartender may help thee greatly\n");
			printf("\t Press 1 to continue, 2 to go back\n");
			
			cin >> input;

			if (input == "1")
			{
				reselectChar = false;
				
				break;
			}
			else if (input == "2")
			{
				system("CLS");

				continue;
			}
			else
			{
				callBack();
				
				continue;
			}
		}
		else if (input == "2")
		{
			characterStats[0] = 5;
			characterStats[1] = 8;
			characterStats[2] = 4;
			characterStats[3] = 5;
			characterStats[4] = 7;
			characterStats[5] = 9;		
			characterStats[6] = luckMin + rand() % (luckMax - luckMin + 1);

			characterType[1] = true;

			system("CLS");

			printf("You have chosen Calvary\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", characterStats[0]);
			printf("Perception: %i\n", characterStats[1]);
			printf("Endurance: %i\n", characterStats[2]);
			printf("Charisma: %i\n", characterStats[3]);
			printf("Intelligence: %i\n", characterStats[4]);
			printf("Agility: %i\n", characterStats[5]);
			printf("Luck: %i\n", characterStats[6]);
			printf("SPECIAL ABILITY: Calvary can charge into units dealing massive splash damage.\n\n");
			printf("Good luck on your quest, I know not what you will encounter nor what you must do.\nHowever I have heard rumors that the bartender may help thee greatly\n");
			printf("\t Press 1 to continue, 2 to go back\n");
			cin >> input;

			if (input == "1")
			{
				reselectChar = false;
				
				break;
			}
			else if (input == "2")
			{
				system("CLS");

				continue;
			}
			else
			{
				callBack();

				continue;
			}
		}
		else if (input == "3")
		{
			characterStats[0] = 9;
			characterStats[1] = 4;
			characterStats[2] = 5;
			characterStats[3] = 4;
			characterStats[4] = 6;
			characterStats[5] = 6;
			characterStats[6] = luckMin + rand() % (luckMax - luckMin + 1);

			characterType[2] = true;

			system("CLS");

			printf("You have chosen Spearman\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", characterStats[0]);
			printf("Perception: %i\n", characterStats[1]);
			printf("Endurance: %i\n", characterStats[2]);
			printf("Charisma: %i\n", characterStats[3]);
			printf("Intelligence: %i\n", characterStats[4]);
			printf("Agility: %i\n", characterStats[5]);
			printf("Luck: %i\n", characterStats[6]);
			printf("SPECIAL ABILITY: Spearmen can fortify, damaging any units that come near them.\n\n");
			printf("Good luck on your quest, I know not what you will encounter nor what you must do.\nHowever I have heard rumors that the bartender may help thee greatly\n");
			printf("\t Press 1 to continue, 2 to go back\n");
			cin >> input;

			if (input == "1")
			{
				reselectChar = false;
				
				break;
			}
			else if (input == "2")
			{
				system("CLS");

				continue;
			}
			else
			{
				callBack();

				continue;
			}
		}
		else if (input == "4")
		{
			characterStats[0] = 3;
			characterStats[1] = 9;
			characterStats[2] = 4;
			characterStats[3] = 5;
			characterStats[4] = 8;
			characterStats[5] = 7;
			characterStats[6] = luckMin + rand() % (luckMax - luckMin + 1);

			characterType[3] = true;

			system("CLS");

			printf("You have chosen Archer\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", characterStats[0]);
			printf("Perception: %i\n", characterStats[1]);
			printf("Endurance: %i\n", characterStats[2]);
			printf("Charisma: %i\n", characterStats[3]);
			printf("Intelligence: %i\n", characterStats[4]);
			printf("Agility: %i\n", characterStats[5]);
			printf("Luck: %i\n", characterStats[6]);
			printf("SPECIAL ABILITY: Archers can set their arrows alight for a short duration.\n\n");
			printf("Good luck on your quest, I know not what you will encounter nor what you must do.\nHowever I have heard rumors that the bartender may help thee greatly\n");
			printf("\t Press 1 to continue, 2 to go back\n");
			cin >> input;

			if (input == "1")
			{
				reselectChar = false;
				
				break;
			}
			else if (input == "2")
			{
				system("CLS");

				continue;
			}
			else
			{
				callBack();

				continue;
			}
		}
		else if (input == "5")
		{
			characterStats[0] = 8;
			characterStats[1] = 4;
			characterStats[2] = 7;
			characterStats[3] = 6;
			characterStats[4] = 5;
			characterStats[5] = 6;
			characterStats[6] = luckMin + rand() % (luckMax - luckMin + 1);

			characterType[4] = true;

			system("CLS");

			printf("You have chosen Swordsman\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", characterStats[0]);
			printf("Perception: %i\n", characterStats[1]);
			printf("Endurance: %i\n", characterStats[2]);
			printf("Charisma: %i\n", characterStats[3]);
			printf("Intelligence: %i\n", characterStats[4]);
			printf("Agility: %i\n", characterStats[5]);
			printf("Luck: %i\n", characterStats[6]);
			printf("SPECIAL ABILITY: Swordsman can fortify, massively increasing their endurance and making them near invulnerable to arrows.\n\n");
			printf("Good luck on your quest, I know not what you will encounter nor what you must do.\nHowever I have heard rumors that the bartender may help thee greatly\n");
			printf("\t Press 1 to continue, 2 to go back\n");
			cin >> input;

			if (input == "1")
			{
				reselectChar = false;
				
				break;
			}
			else if (input == "2")
			{
				system("CLS");

				continue;
			}
			else
			{
				callBack();

				continue;
			}
		}
		else;
		{
			callBack();
	
			continue;
		}

	}
	system("CLS");
}

void universalEquipment(string input, bool(characterType)[5], int(&characterStats)[7])
{

	if (input == "1")
	{
		printf("Leather Selected:\nStrength: +0\nPerception: -1\nEndurance: +2\nCharisma: -1\nIntelligence: +0\nAgility: +1\nLuck: +0\n\n");
		characterStats[1] -= 1;
		characterStats[2] += 2;
		characterStats[3] -= 1;
		characterStats[5] += 1;
		printf("Current Stats:\n");
		cout << "Strength: " << characterStats[0] << endl << "Perception: " << characterStats[1] << endl << "Endurance: " << characterStats[2] << endl;
		cout << "Charisma: " << characterStats[3] << endl << "Intelligence: " << characterStats[4] << endl << "Agility: " << characterStats[5] << endl << "Luck: " << characterStats[6] << endl;

	}
	else if (input == "2")
	{
		printf("Chainmail Selected:\nStrength +1\nPerception: -2\nEndurance +3\nCharisma: +1\nIntelligence: +0\nAgility: -1\nLuck: +0\n\n");
		characterStats[0] += 1;
		characterStats[1] -= 2;
		characterStats[2] += 3;
		characterStats[3] += 1;
		characterStats[5] -= 1;
		printf("Current Stats:\n");
		cout << "Strength: " << characterStats[0] << endl << "Perception: " << characterStats[1] << endl << "Endurance: " << characterStats[2] << endl;
		cout << "Charisma: " << characterStats[3] << endl << "Intelligence: " << characterStats[4] << endl << "Agility: " << characterStats[5] << endl << "Luck: " << characterStats[6] << endl;

	}
	else if (input == "3")
	{
		printf("Plate Selected:\n Strength: +2\nPerception: -3\nEndurance: +5\nCharisma: +2\nIntelligence: +0\nAgility: -3\nLuck: + 0\n\n");
		characterStats[0] += 2;
		characterStats[1] -= 3;
		characterStats[2] += 5;
		characterStats[3] += 2;
		characterStats[5] -= 3;
		printf("Current Stats:\n");
		cout << "Strength: " << characterStats[0] << endl << "Perception: " << characterStats[1] << endl << "Endurance: " << characterStats[2] << endl;
		cout << "Charisma: " << characterStats[3] << endl << "Intelligence: " << characterStats[4] << endl << "Agility: " << characterStats[5] << endl << "Luck: " << characterStats[6] << endl;
	}
	
}
	
void equipmentSelection(string playerName, bool (characterType)[5], int (&characterStats)[7])
{

	string input;
	bool universal = false;
	
	bool selectingArmor = true;

	
		cout << "Welcome to the armory " << playerName << "!" << endl;
		printf("Press any key to continue\n");
		_getch();
		system("CLS");

		printf("We'll first start off with armor, there are several universal armors, available to everyone, and there are some only available to specific classes\nAlso note that should a stat achieve a value higher than 10 it will be set to 10 automatically\nAnd vice versa for negative stats\nPress amy key to continue\n");
		_getch();
		system("CLS");

		do
	{

		printf("UNIVERSAL:\n1. Leather\n2. Chainmail\n3. Plate\n");
		if (characterType[0] == true)
		{
			printf("UNIQUE:\n");
			printf("4. The kings holy plate\n5. Heavy Plate\n");
			cin >> input;
			system("CLS");

			if (input == "1" || "2" || "3")
			{
				universal = true;
			}
			else if (input == "4")
			{

			}
			else if (input == "5")
			{

			}
			else
			{
				callBack();

				continue;
			}

		}
		else if (characterType[1] == true)
		{
			printf("UNIQUE:\n");
			printf("4. Lamellar Armor\n5. ");


		}
		else if (characterType[2] == true)
		{
			printf("UNIQUE:\n");

		}
		else if (characterType[3] == true)
		{
			printf("UNIQUE:\n");

		}
		else if (characterType[4] == true)
		{
			printf("UNIQUE:\n");

		}
		else
		{
			printf("How.... How did you manage this?\nERROR ERROR... ERROR... ERRO... ER......");
			_getch();
			system("CLS");
			printf("...");
			_getch();
			exit(0);
		}
		
		if (universal == true)
		{
			universalEquipment(input, characterType, characterStats);
			printf("Press 1 to continue, 2 to go back");
			cin >> input;
			if (input == "2")
			{
				system("CLS");

				continue;
			}
			else
			{
				callBack;

				continue;
			}
		}
		

		printf("OK! So now that we've picked out our armor we can move on to the fun part, weapons!\nPress any key to continue");
		_getch();
		system("CLS");


	} while (selectingArmor = true);
	
}


int main()
{
	int characterStats[7] = { 0, 0, 0, 0, 0, 0, 0};
	int characterHealth;
	int level;
	int gameDifficulty;
	int xp;
	bool characterType[5] = { false, false, false, false, false };
	bool intro = true;
		
	string playerName;

	srand(0);
	srand((unsigned)time(NULL));

	printf("Hello adventurer, what would you like to be known as?\n");
	cin >> playerName;

	system("CLS");

	cout << "Welcome to my RPG, " << playerName << ", this is a c++ text based game made by me, Joey Soroka.\n\nCREDITS:\n\nEric Pace for moral support.\nIsaac Morine for inventing chainmail.\nLast but certainly not least The Void Monster under my bed" << endl;
	printf("Press any key to start the RPG.\n");

	_getch();

	system("CLS");

	if (intro = true)
	{
		introduction(playerName);

		characterSelection(characterStats, playerName, characterType);
		
		equipmentSelection(playerName, characterType, characterStats);

		intro = false;

	}

	
	
	return 0;
}

