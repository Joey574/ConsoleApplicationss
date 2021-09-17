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
*/
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;



void introduction()
{
	int input1;
	printf("Hello adventurer! We need your help.\nThe world is in peril, you are the last hope\n\t Press 1 to continue\n");
	cin >> input1;
	if (input1 == 1)
	{
		system("CLS");
	}
	else
	{
		
	}
		
		printf("\t\t\tCHOOSE YOUR CHARACTER\n1. Knight \t 2. Calvary \t 3. Spearman \t 4. Archer \t 5. Swordsman\n");
		cin >> input1;
		if (input1 == 1)
		{
			system("CLS");
			printf("You have chosen knight\n\t Press any key to continue");

		}
		else if (input1 == 2)
		{
			system("CLS");
			printf("You have chosen Calvary\n\t Press any key to continue");
		}
		else if (input1 == 3)
		{
			system("CLS");
			printf("You have chosen Spearman\n\t Press any key to continue");
		}
		else if (input1 == 4)
		{
			system("CLS");
			printf("You have chosen Archer\n\t Press any key to continue");
		}
		else if (input1 == 5)
		{
			system("CLS");
			printf("You have chosen Swordsman\n\t Press any key to continue");
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
	int damage;
	int speed;
	int agility;
	int constitution;
	bool intro = true;
	int input1;
	
	if (intro = true)
	{
		introduction();
	}
	else
	{
		defeat();
	}


	
	return 0;
}


