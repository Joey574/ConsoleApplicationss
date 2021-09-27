/*
Author: Joey Soroka
Project Name: RPG Instructions
File Name: RPG.cpp
Purpose: Simple RPG introduction to explain what will happen in this RPG
Pseudocode: Introduces the player to the world they now occupy, as well as asking for their name and givng credit to author and moral support
Maintenance Log:
9/27/21:	Started project, copying introductory code from main RPG project and making slight adjustments
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h> 
#include <time.h> 
#include <conio.h> 
#include <vector>

using namespace std;

void introduction(string playerName)  // Says hello to user and gives intoduction
{

	cout << "Hello " << playerName << "! We need your help. The world is in peril." << endl;
	printf("\tYou are our last hope.\n\tPress any key to continue\n");

	_getch();

	system("CLS");

	printf("The year is 1257, hordes of goblins and ogres have swarmed a once peaceful realm, and only you, ");
	cout << playerName << "," << endl;
	printf("a noble from a long forgotten land, holds the key to salvation.\n\tPress any key to continue\n");

	_getch();

	system("CLS");

	printf("What can only be described as a gate to hell has opened deep undergrund,\nunleashing swarms of monsters of your worst nightmares.\n");
	printf("Hundres, no THOUSANDS, have tried to close said gate, however none have succeeded.\nYou have been called upon by your king to dispatch of this threat.\n");
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

	string playerName;

	srand(0);
	srand((unsigned)time(NULL));

	printf("Hello adventurer, what would you like to be known as?\n");
	cin >> playerName;

	system("CLS");

	cout << "Welcome to this RPG, " << playerName << " this is a c++ text based game made by me, Joey Soroka.\nHowever I should also credit Eric Pace for moral support." << endl;
	printf("Press any key to start the RPG.\n");

	_getch();

	system("CLS");

	if (intro = true)
	{
		introduction(playerName);

		intro = false;
	}
}

