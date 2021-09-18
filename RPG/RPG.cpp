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
*/
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;



void introduction()
{
	srand(0);
	srand((unsigned)time(NULL));

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
	int luckMax = 5;
	int luckMin = 1;
	int input1;
	printf("Hello adventurer! We need your help.\nThe world is in peril, and you must save us\n\t Press any key to continue\n");
	
	_getch();

	system("CLS");
		
	printf("The year is 1257, hords of goblins and ogres have swarmed a once peaceful realm, and only you, a noble from a long forgotten land, holds the key to salvation.\n\t Press any key to continue\n");

	_getch();
	
	system("CLS");
		
		
		printf("\t\t\tCHOOSE YOUR CHARACTER\n1. Knight \t 2. Calvary \t 3. Spearman \t 4. Archer \t 5. Swordsman\n");
		cin >> input1;
		if (input1 == 1)
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
			printf("Press any key to continue\n");

			_getch();
		}
		else if (input1 == 2)
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
			printf("Press any key to continue\n");

			_getch();
		}
		else if (input1 == 3)
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
			printf("Press any key to continue\n");

			_getch();
		}
		else if (input1 == 4)
		{
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
			printf("Press any key to continue\n");

			_getch();
		}
		else if (input1 == 5)
		{
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
			printf("Press any key to continue\n");

			_getch();
		}
		else;
		{

		}
		

}
void defeat()
{

}


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
	int input1;
	
	if (intro = true)
	{
		introduction();
		intro = false;
	}
	else
	{
		defeat();
	}


	
	return 0;
}


