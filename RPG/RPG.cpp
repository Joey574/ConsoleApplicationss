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
	printf("CHOOSE YOUR CHARACTER\n\t 1. Knight \t 2. Calvary \t 3. Spearman \t 4. Archer \t 5. Swordsman");
	cin >> input1;
	if (input1 == 1)
	{

	}
	else if (input1 == 2)
	{

	}
	else if (input1 == 3)
	{

	}
	else if (input1 == 4)
	{

	}
	else if (input1 == 5)
	{

	}
	else ()

}
void defeat()
{

}


int main()
{
	int characterHealth;
	int level;
	int xp;
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


