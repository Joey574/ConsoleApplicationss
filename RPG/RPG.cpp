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

*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <vector>

using namespace std;


void introduction(string playerName)
{
	srand(0);
	srand((unsigned)time(NULL));

	cout << "Hello " << playerName << "! We need your help. The worl is in peril." << endl;

	printf("\tYou are our last hope.\n\t Press any key to continue\n");

	_getch();

	system("CLS");

	printf("The year is 1257, hordes of goblins and ogres have swarmed a once peaceful realm, and only you, a noble from a long forgotten land, holds the key to salvation.\n\t Press any key to continue\n");

	_getch();

	system("CLS");
}
	//void characterSelection(int strength, int perception, int endurance, int charisma, int intelligence, int agility, int luck, string playerName, bool knight, bool calvary, bool spearman, bool archer, bool swordsman)
/*{
	int input;
	int luckMin = 1;
	int luckMax = 10;

	system("CLS");

	printf("\t\t\tCHOOSE YOUR CHARACTER\n1. Knight \t 2. Calvary \t 3. Spearman \t 4. Archer \t 5. Swordsman\n");
	cin >> input;
	if (input == 1)
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

		if (input == 1)
		{

		}
		else if (input == 2)
		{
			//	characterSelection();
		}
		else
		{

		}
	}
	else if (input == 2)
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

		if (input == 1)
		{

		}
		else if (input == 2)
		{
			//	characterSelection();
		}
		else
		{

		}
	}
	else if (input == 3)
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

		if (input == 1)
		{

		}
		else if (input == 2)
		{
			//	characterSelection();
		}
		else
		{

		}
	}
	else if (input == 4)
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

		if (input == 1)
		{

		}
		else if (input == 2)
		{
			//	characterSelection();
		}
		else
		{

		}
	}
	else if (input == 5)
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

		if (input == 1)
		{

		}
		else if (input == 2)
		{
			//	characterSelection();
		}
		else
		{

		}
	}
	else;
	{

	}

}
*/

int main()
{
	int characterHealth;
	int level;
	int xp;
	int strength;
	int perception;
	int endurance;
	int charisma;
	int intelligence;
	int agility;
	int luck;
	bool knight;
	bool calvary;
	bool spearman;
	bool archer;
	bool swordsman;
	bool intro = true;
	
	string playerName;

	printf("Hello adventurer, what would you like to be known as?\n");
	cin >> playerName;
	system("CLS");
	cout << "Welcome " << playerName;
	printf(" Press any key to continue.\n");

	_getch();

	system("CLS");

	if (intro = true)
	{
		introduction(playerName);
		intro = false;
		
		int input;
		int luckMin = 1;
		int luckMax = 10;

		system("CLS");

		printf("\t\t\tCHOOSE YOUR CHARACTER\n1. Knight \t 2. Calvary \t 3. Spearman \t 4. Archer \t 5. Swordsman\n");
		cin >> input;
		if (input == 1)
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

			if (input == 1)
			{

			}
			else if (input == 2)
			{
				
			}
			else
			{

			}
		}
		else if (input == 2)
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

			if (input == 1)
			{

			}
			else if (input == 2)
			{
				
			}
			else
			{

			}
		}
		else if (input == 3)
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

			if (input == 1)
			{

			}
			else if (input == 2)
			{
				
			}
			else
			{

			}
		}
		else if (input == 4)
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

			if (input == 1)
			{

			}
			else if (input == 2)
			{
				
			}
			else
			{

			}
		}
		else if (input == 5)
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

			if (input == 1)
			{

			}
			else if (input == 2)
			{
				
			}
			else
			{

			}
		}
		else;
		{

		}

	}
	
	
	return 0;
}

