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
	printf("\tYou are our last hope.\n\t Press any key to continue\n");

	_getch(); 

	system("CLS"); 

	printf("The year is 1257, hordes of goblins and ogres have swarmed a once peaceful realm, and only you, ");
	cout << playerName << endl;
	printf("a noble from a long forgotten land, holds the key to salvation.\n\t Press any key to continue\n");

	_getch();

	system("CLS");

	printf("What can only be described as a gate to hell has opened deep undergrund,\nunleashing swarms of monsters of your worst nightmares.\n");
	printf("Hundreds, no THOUSANDS, have tried to close said gate, however none have succeeded.\nYou have been called upon by your king to dispatch of this threat.\n\tPress any key to continue");

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

void statChecker(int& strength, int& perception, int& endurance, int& charisma, int& intelligence, int& agility, int& luck)
{
	if (strength > 10)
	{
		strength = 10;
	}
	if (perception > 10)
	{
		perception = 10;
	}
	if (endurance > 10)
	{
		endurance = 10;
	}
	if (charisma > 10)
	{
		charisma = 10;
	}
	if (intelligence > 10)
	{
		intelligence = 10;
	}
	if (agility > 10)
	{
		agility = 10;
	}
	if (luck > 10)
	{
		luck = 10;
	}
}

void characterSelection(int &strength, int &perception, int &endurance, int &charisma, int &intelligence, int &agility, int &luck, string playerName, bool &knight, bool &calvary, bool &spearman, bool &archer, bool &swordsman)
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
			strength = 8;
			perception = 3;
			endurance = 9;
			charisma = 7;
			intelligence = 4;
			agility = 2;
			luck = luckMin + rand() % (luckMax - luckMin + 1);
			knight = true;

			system("CLS");

			printf("You have chosen knight\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", strength);
			printf("Perception: %i\n", perception);
			printf("Endurance: %i\n", endurance);
			printf("Charisma: %i\n", charisma);
			printf("Intelligence: %i\n", intelligence);
			printf("Agility: %i\n", agility);
			printf("Luck: %i\n", luck);
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
			strength = 5;
			perception = 8;
			endurance = 4;
			charisma = 5;
			intelligence = 7;
			agility = 9;
			luck = luckMin + rand() % (luckMax - luckMin + 1);
			calvary = true;

			system("CLS");

			printf("You have chosen Calvary\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", strength);
			printf("Perception: %i\n", perception);
			printf("Endurance: %i\n", endurance);
			printf("Charisma: %i\n", charisma);
			printf("Intelligence: %i\n", intelligence);
			printf("Agility: %i\n", agility);
			printf("Luck: %i\n", luck);
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
			strength = 9;
			perception = 4;
			endurance = 5;
			charisma = 4;
			intelligence = 6;
			agility = 6;
			luck = luckMin + rand() % (luckMax - luckMin + 1);
			spearman = true;

			system("CLS");

			printf("You have chosen Spearman\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", strength);
			printf("Perception: %i\n", perception);
			printf("Endurance: %i\n", endurance);
			printf("Charisma: %i\n", charisma);
			printf("Intelligence: %i\n", intelligence);
			printf("Agility: %i\n", agility);
			printf("Luck: %i\n", luck);
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
			strength = 3;
			perception = 9;
			endurance = 4;
			charisma = 5;
			intelligence = 8;
			agility = 7;
			luck = luckMin + rand() % (luckMax - luckMin + 1);
			archer = true;

			system("CLS");

			printf("You have chosen Archer\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", strength);
			printf("Perception: %i\n", perception);
			printf("Endurance: %i\n", endurance);
			printf("Charisma: %i\n", charisma);
			printf("Intelligence: %i\n", intelligence);
			printf("Agility: %i\n", agility);
			printf("Luck: %i\n", luck);
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
			strength = 8;
			perception = 4;
			endurance = 7;
			charisma = 6;
			intelligence = 5;
			agility = 6;
			luck = luckMin + rand() % (luckMax - luckMin + 1);
			swordsman = true;

			system("CLS");

			printf("You have chosen Swordsman\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", strength);
			printf("Perception: %i\n", perception);
			printf("Endurance: %i\n", endurance);
			printf("Charisma: %i\n", charisma);
			printf("Intelligence: %i\n", intelligence);
			printf("Agility: %i\n", agility);
			printf("Luck: %i\n", luck);
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
}

void knightEquipment(int &strengthMod, int &perceptionMod, int &enduranceMod, int &charismaMod, int &intelligenceMod, int &agilityMod, int &luckMod)
{


}

void calvaryEquipment()
{
	
}

void spearmanEquipment()
{

}

void archerEquipment()
{

}

void swordsmanEquipment()
{

}
	
	void equipmentSelection(string playerName, bool knight, bool calvary, bool spearman, bool archer, bool swordsman, int &strengthMod, int &perceptionMod, int &enduranceMod, int &charismaMod, int &intelligenceMod, int &agilityMod, int &luckMod)
{

	string input;
	
	bool selectingEquipment = true;

	while (selectingEquipment = true)
	{
		cout << "Welcome to the armory " << playerName << "!" << endl;
		printf("Press any key to continue\n");

		_getch();

		system("CLS");

		printf("We'll first start off with armor, there are several");

		

	}
	
}


int main()
{
	int characterHealth;
	int level;
	int xp;
	int strength = 0;
	int perception = 0;
	int endurance = 0;
	int charisma = 0;
	int intelligence = 0;
	int agility = 0;
	int luck = 0;
	bool knight = false;
	bool calvary = false;
	bool spearman = false;
	bool archer = false;
	bool swordsman = false;
	bool intro = true;
	int strengthMod = 0;
	int perceptionMod = 0;
	int enduranceMod = 0;
	int charismaMod = 0;
	int intelligenceMod = 0;
	int agilityMod = 0;
	int luckMod = 0;
	
	string playerName;

	srand(0);
	srand((unsigned)time(NULL));

	printf("Hello adventurer, what would you like to be known as?\n");
	cin >> playerName;

	system("CLS");

	cout << "Welcome to my RPG, " << playerName << ", this is a c++ text based game made by me, Joey Soroka.\nHowever I should also credit Eric Pace for moral support.\nOn that note Isaac Morine also deserves a shoutout for inventing chainmail.\nLast but certainly not least The Void Monster under my bed" << endl;
	printf("Press any key to start the RPG.\n");

	_getch();

	system("CLS");

	if (intro = true)
	{
		introduction(playerName);

		intro = false;

		characterSelection(strength, perception, endurance, charisma, intelligence, agility, luck, playerName, knight, calvary, spearman, archer, swordsman);

		system("CLS");

		equipmentSelection(playerName, knight, calvary, spearman, archer, swordsman, strengthMod, perceptionMod, enduranceMod, charismaMod, intelligenceMod, agilityMod, luckMod);


	}

	
	
	return 0;
}

