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
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;



void introduction()

	srand(0);
{	srand((unsigned)time(NULL));
{
	int strength;
	int perception;
	int endurance;
	int charisma;
	int intelligence;
	int agility;
	int luck;
	int luckMax = 5;
	int luckMin = 0;
	int input1;
	printf("Hello adventurer! We need your help.\nThe world is in peril, and we need your help\n\t Press any key to continue\n");
	
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
			charisma = 5;
			intelligence = 4;
			agility = 2;
			
			luck = luckMin + rand() % (luckMax - luckMin + 1);

			system("CLS");
			printf("You have chosen knight\n");
			printf("Your stats are:\n");

			getch();

		}
		else if (input1 == 2)
		{
			system("CLS");
			printf("You have chosen Calvary\n\t Press any key to continue");
			_getch();
		}
		else if (input1 == 3)
		{
			system("CLS");
			printf("You have chosen Spearman\n\t Press any key to continue");
			_getch();
		}
		else if (input1 == 4)
		{
			system("CLS");
			printf("You have chosen Archer\n\t Press any key to continue");
			_getch();
		}
		else if (input1 == 5)
		{
			system("CLS");
			printf("You have chosen Swordsman\n\t Press any key to continue");
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


