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

9/20/21:	Finished character stats, gonna work on character equipment next...
			sctracth that, working on organization and transfering ints from functions to main and vice versa

9/21/21:	Working on header file, absolute chaos, simplified code with help of tucker, made it out of the dark ages, code works, no functions though

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

10/17/21:	Added 2 unique armor classes for knight and fixed exploit with luck skill generation, thinking about adding custom stat selection soon

10/20/21:	Completed stat selection, still has many bugs and exploits, negative stats, stats of 11, etc. needs much more polishing

10/21/21:	Fixed most issues with stat selection, however currently struggling with a big one, when selecting strength, the first stat, any character will be accepted in the 
			if statement, if a letter is inputted it will cause a crash in the program, if a letter bigger than 10 is entered it will cause the stat to be bigger then 10
			and if a negative number is enetered it will give that amount of stat points to the user... fixed the issue, no idea what it was but copying and pasting code 
			that worked fixed the issue... worked on equipment selection, universal armor will no longer stack stats, also fixed the flow for universal equipment so it's not
			funky and broken... added 2 unique armors for calvary, both are functional, added one partially functional armor for archer

10/22/21:	Worked on effiecieny a bit, getting rid of 80 lines of code, still having the same function as before, fixed error with character selection retaining the value even if user 
			went back and selected new character, and added character health calculator under main

10/25/21:	Added several new unique armor classes, only need 2 more

10/26/21:	Added the 2 final armors, changed how health is set up, endurance no longers plays a role in health, set up a dev mode when user enters DEV. as their username
			allowing user to jump to most functions, skipping rest of the code, reached 1000 lines of code milestone!!!! Redid credit scene at beginning, working on cleaning
			up the visual side of things and getting rid of walls of text... Added introductory text for weapon selection, as well as begining if statement for it

10/27/21:	Set up struct containing player information, going to make it easier to pass all sorts of variables, also added a few comments on functions saying what they do, not exactly
			much, but it's progress which is good, added weapon variables to the struct... added basic text for some weapons, no actual variables given values yet

11/2/21:	Added min and max damage ints to struct replacing just damage, added text for 5 knight primary weapons as well as bools identifying which weapon was selected, currently no
			variable besides the bools are actually modified
*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h>

using namespace std;

struct characterInformation // contains information about character and weapon information
{
	int baseStats[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int characterStats[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int characterHealth;
	int level;
	int xp;
	bool characterType[5] = { false, false, false, false, false };
	string playerName;
	string horseName;

	bool peircing;
	bool blunt;
	bool slash;
	int minDamage;
	int maxDamage;
	float range;
	int accuracy;
	int weight;
};

void introduction(struct characterInformation c)  // Says hello to user and gives intoduction
{
	cout << "Hello " << c.playerName << "! We need your help. The world is in peril." << endl;
	printf("You are our last hope.\nPress any key to continue\n");
	_getch();	
	system("CLS");

	printf("The year is 1257, hordes of goblins and ogres have swarmed a once peaceful realm, and only you, ");
	cout << c.playerName << endl;
	printf("a noble from a long forgotten land, holds the key to salvation.\nPress any key to continue\n");
	_getch();
	system("CLS");

	printf("What can only be described as a gate to hell has opened deep underground,\nunleashing swarms of monsters of your worst nightmares.\n");
	printf("Hundreds, no THOUSANDS, have tried to close said gate, however none have succeeded.\nYou have been called upon by your king to dispatch of this threat.\nPress any key to continue\n");
	_getch();
	system("CLS");
}

void callBack() // used in case incorrect input is taken, more convieniant than copy and pasting it everywhere
{
	system("CLS");

	printf("Incorrect input detected\nPress any key to continue\n");

	_getch();

	system("CLS");
}

void callBackNoCLS() // same thing as callback however doesnt clear any text from the screen
{
	printf("\nIncorrect input detected\nPress any key to continue\n\n");

	_getch();
}

void statSelection(struct characterInformation &c) // allows the user to select their own stats, however it will randomly generate luck
{
	string input;
	int statPoints = 18;
	int luckMin = 0;
	int luckMax = 10;

	system("CLS");
	
	cout << "Ok, " << c.playerName << " time to spread out your character points, you have 18 stat points you can put in 6 different categories" << endl;
	printf("Press any key to continue\n");
	_getch();
	system("CLS");
	printf("These categories are Strength, Perception, Endurance, Charisma, Intelligence, and Agility, or S.P.E.C.I.A, Luck will be randomly generated\n");
	printf("Also note each stat can only have a maximum of 10 points\nPress any key to continue\n");
	_getch();
	system("CLS");
	printf("However overall max for each stat is 25, and they can also go down to -10\nPress any key to continue\n");
	
	_getch();
	system("CLS");

	while (1)
	{
		printf("Strength: ");
		cin >> input;

		if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "8" || input == "9" || input == "10" || input == "0")
		{
			int points = stoi(input);

			if (statPoints - points < 0)
			{
				printf("\nOut of stat points, choose a smaller number\n");
				cout << "Stat points left: " << statPoints << endl << endl;
				continue;
			}
			c.characterStats[0] = points;
			c.baseStats[0] = points;

			statPoints -= points;
			break;
		}
		else
		{
			callBackNoCLS();
			continue;
		}
	}


	while(1)
	{
		printf("Perception: ");
		cin >> input;

		if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "8" || input == "9" || input == "10" || input == "0")
		{
			int points = stoi(input);

			if (statPoints - points < 0)
			{
				printf("\nOut of stat points, choose a smaller number\n");
				cout << "Stat points left: " << statPoints << endl << endl;
				continue;
			}
			c.characterStats[1] = points;
			c.baseStats[1] = points;

			statPoints -= points;
			break;
		}
		else
		{
			callBackNoCLS();
			continue;
		}
	} 


	while (1)
	{
		printf("Endurance: ");
		cin >> input;

		if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "8" || input == "9" || input == "10" || input == "0")
		{
			int points = stoi(input);

			if (statPoints - points < 0)
			{
				printf("\nOut of stat points, choose a smaller number\n");
				cout << "Stat points left: " << statPoints << endl << endl;
				continue;
			}
			c.characterStats[2] = points;
			c.baseStats[2] = points;

			statPoints -= points;
			break;
		}
		else
		{
			callBackNoCLS();
			continue;
		}
	} 


	while (1)
	{
		printf("Charisma: ");
		cin >> input;

		if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "8" || input == "9" || input == "10" || input == "0")
		{
			int points = stoi(input);

			if (statPoints - points < 0)
			{
				printf("\nOut of stat points, choose a smaller number\n");
				cout << "Stat points left: " << statPoints << endl << endl;
				continue;
			}
			c.characterStats[3] = points;
			c.baseStats[3] = points;

			statPoints -= points;
			break;
		}
		else
		{
			callBackNoCLS();
			continue;
		}
	} 


	while (1)
	{
		printf("Intelligence: ");
		cin >> input;

		if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "8" || input == "9" || input == "10" || input == "0")
		{
			int points = stoi(input);

			if (statPoints - points < 0)
			{
				printf("\nOut of stat points, choose a smaller number\n");
				cout << "Stat points left: " << statPoints << endl << endl;
				continue;
			}
			c.characterStats[4] = points;
			c.baseStats[4] = points;

			statPoints -= points;
			break;
		}
		else
		{
			callBackNoCLS();
			continue;
		}
	} 


	while (1)
	{
		printf("Agility: ");
		cin >> input;

		if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "8" || input == "9" || input == "10" || input == "0")
		{
			int points = stoi(input);

			if (statPoints - points < 0)
			{
				printf("\nOut of stat points, choose a smaller number\n");
				cout << "Stat points left: " << statPoints << endl << endl;
				continue;
			}
			c.characterStats[5] = points;
			c.baseStats[5] = points;

			statPoints -= points;
			break;
		}
		else
		{
			callBackNoCLS();
			continue;
		}
	}
	c.characterStats[6] = luckMin + rand() % (luckMax - luckMin + 1);
	c.baseStats[6] = c.characterStats[6];
	_getch();
	system("CLS");
	printf("Great! Now that you have selected your stats, lets move on to character selection!\nPress any key to continue\n");
	_getch();
}

void statChecker(struct characterInformation &c) // checks stats to make sure they dont exceed the maximum or minimum values
{
	if (c.characterStats[0] > 10)
	{
		c.characterStats[0] = 10;
	}
	if (c.characterStats[1] > 10)
	{
		c.characterStats[1] = 10;
	}
	if (c.characterStats[2] > 10)
	{
		c.characterStats[2] = 10;
	}
	if (c.characterStats[3] > 10)
	{
		c.characterStats[3] = 10;
	}
	if (c.characterStats[4] > 10)
	{
		c.characterStats[4] = 10;
	}
	if (c.characterStats[5] > 10)
	{
		c.characterStats[5] = 10;
	}
	if (c.characterStats[6] > 10)
	{
		c.characterStats[6] = 10;
	}
	if (c.characterStats[0] < -10)
	{
		c.characterStats[0] = -10;
	}
	if (c.characterStats[1] < -10)
	{
		c.characterStats[1] = -10;
	}
	if (c.characterStats[2] < -10)
	{
		c.characterStats[2] = -10;
	}
	if (c.characterStats[3] < -10)
	{
		c.characterStats[3] = -10;
	}
	if (c.characterStats[4] < -10)
	{
		c.characterStats[4] = -10;
	}
	if (c.characterStats[5] < -10)
	{
		c.characterStats[5] = -10;
	}
	if (c.characterStats[6] < -10)
	{
		c.characterStats[6] = -10;
	}
}

void characterSelection(struct characterInformation &c)
{

	string input;

	system("CLS");

	while (1)
	{
		printf("\t\t\tCHOOSE YOUR CHARACTER\n1. Knight \t 2. Calvary \t 3. Spearman \t 4. Archer \t 5. Swordsman\n");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			c.characterType[0] = true;

			printf("You have chosen knight\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", c.characterStats[0]);
			printf("Perception: %i\n", c.characterStats[1]);
			printf("Endurance: %i\n", c.characterStats[2]);
			printf("Charisma: %i\n", c.characterStats[3]);
			printf("Intelligence: %i\n", c.characterStats[4]);
			printf("Agility: %i\n", c.characterStats[5]);
			printf("Luck: %i\n", c.characterStats[6]);
			printf("SPECIAL ABILITY: During times of need a knight can pray for a random gift from the heavens.\n\n");
	
		}
		else if (input == "2")
		{	
			c.characterType[1] = true;

			printf("You have chosen Calvary\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", c.characterStats[0]);
			printf("Perception: %i\n", c.characterStats[1]);
			printf("Endurance: %i\n", c.characterStats[2]);
			printf("Charisma: %i\n", c.characterStats[3]);
			printf("Intelligence: %i\n", c.characterStats[4]);
			printf("Agility: %i\n", c.characterStats[5]);
			printf("Luck: %i\n", c.characterStats[6]);
			printf("SPECIAL ABILITY: Calvary can charge into units dealing massive splash damage.\n\n");
		}
		else if (input == "3")
		{
			c.characterType[2] = true;

			printf("You have chosen Spearman\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", c.characterStats[0]);
			printf("Perception: %i\n", c.characterStats[1]);
			printf("Endurance: %i\n", c.characterStats[2]);
			printf("Charisma: %i\n", c.characterStats[3]);
			printf("Intelligence: %i\n", c.characterStats[4]);
			printf("Agility: %i\n", c.characterStats[5]);
			printf("Luck: %i\n", c.characterStats[6]);
			printf("SPECIAL ABILITY: Spearmen can fortify, damaging any units that come near them.\n\n");
	
		}
		else if (input == "4")
		{	
			c.characterType[3] = true;

			printf("You have chosen Archer\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", c.characterStats[0]);
			printf("Perception: %i\n", c.characterStats[1]);
			printf("Endurance: %i\n", c.characterStats[2]);
			printf("Charisma: %i\n", c.characterStats[3]);
			printf("Intelligence: %i\n", c.characterStats[4]);
			printf("Agility: %i\n", c.characterStats[5]);
			printf("Luck: %i\n", c.characterStats[6]);
			printf("SPECIAL ABILITY: Archers can set their arrows alight for a short duration.\n\n");

		}
		else if (input == "5")
		{
			c.characterType[4] = true;

			printf("You have chosen Swordsman\n");
			printf("Your stats are:\n");
			printf("Strength: %i\n", c.characterStats[0]);
			printf("Perception: %i\n", c.characterStats[1]);
			printf("Endurance: %i\n", c.characterStats[2]);
			printf("Charisma: %i\n", c.characterStats[3]);
			printf("Intelligence: %i\n", c.characterStats[4]);
			printf("Agility: %i\n", c.characterStats[5]);
			printf("Luck: %i\n", c.characterStats[6]);
			printf("SPECIAL ABILITY: Swordsman can fortify, massively increasing their endurance and making them near invulnerable to arrows.\n\n");

		}
		else
		{
			callBack();
	
			continue;
		}

		printf("Good luck on your quest, I know not what you will encounter nor what you must do.\nHowever I have heard rumors that the bartender may help thee greatly\n");
		printf("\t Press 1 to continue, 2 to go back\n");
		cin >> input;

		if (input == "1")
		{
			break;
		}
		else if (input == "2")
		{
			system("CLS");

			c.characterType[0] = false;
			c.characterType[1] = false;
			c.characterType[2] = false;
			c.characterType[3] = false;
			c.characterType[4] = false;

			continue;
		}
		else
		{
			callBack();

			c.characterType[0] = false;
			c.characterType[1] = false;
			c.characterType[2] = false;
			c.characterType[3] = false;
			c.characterType[4] = false;

			continue;
		}

	}
	system("CLS");
}

void universalEquipment(struct characterInformation& c, string input, bool(&universalsSelected)[3])
{

	if (input == "1")
	{
		printf("Leather Selected:\nStrength: +0\nPerception: -1\nEndurance: +2\nCharisma: -1\nIntelligence: +0\nAgility: +1\nLuck: +0\n\n");
		printf("Current Stats:\n");
		cout << "Strength: " << c.characterStats[0] << endl << "Perception: " << c.characterStats[1] - 1<< endl << "Endurance: " << c.characterStats[2] + 2<< endl;
		cout << "Charisma: " << c.characterStats[3] - 1<< endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] + 1 << endl << "Luck: " << c.characterStats[6] << endl;
		universalsSelected[0] = true;
	}
	else if (input == "2")
	{
		printf("Chainmail Selected:\nStrength +1\nPerception: -2\nEndurance +3\nCharisma: +1\nIntelligence: +0\nAgility: -1\nLuck: +0\n\n");
		printf("Current Stats:\n");
		cout << "Strength: " << c.characterStats[0] + 1 << endl << "Perception: " << c.characterStats[1] - 2 << endl << "Endurance: " << c.characterStats[2] + 3 << endl;
		cout << "Charisma: " << c.characterStats[3] + 1 << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] - 1 << endl << "Luck: " << c.characterStats[6] << endl;
		universalsSelected[1] = true;
	}
	else if (input == "3")
	{
		printf("Plate Selected:\nStrength: +2\nPerception: -3\nEndurance: +5\nCharisma: +2\nIntelligence: +0\nAgility: -3\nLuck: + 0\n\n");
		printf("Current Stats:\n");
		cout << "Strength: " << c.characterStats[0] + 2 << endl << "Perception: " << c.characterStats[1] - 3 << endl << "Endurance: " << c.characterStats[2] + 5 << endl;
		cout << "Charisma: " << c.characterStats[3] + 2 << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] - 3 << endl << "Luck: " << c.characterStats[6] << endl;
		universalsSelected[2] = true;
	}
	
}
	
void equipmentSelection(struct characterInformation &c)
{

	string input;
	bool universal = false;
	bool universalsSelected[3] = { false, false, false };
	bool uniqueSelected[10] = { false, false, false, false, false, false, false, false, false, false };
	bool knightPrimary[5] = { false, false, false, false, false };
	

		cout << "Welcome to the armory " << c.playerName << "!" << endl;
		printf("Press any key to continue\n");
		_getch();
		system("CLS");
		printf("We'll first start off with armor, there are several universal armors, available to everyone, and there are some only available to specific classes\nPress any key to continue\n");
		_getch();
		system("CLS");

		do
	{

		printf("UNIVERSAL:\n1. Leather\n2. Chainmail\n3. Plate\n");
		if (c.characterType[0] == true)
		{
			printf("UNIQUE:\n");
			printf("4. The kings holy plate\n5. Heavy Plate\n");
			cin >> input;
			system("CLS");

			if (input == "1" || input == "2" ||input == "3")
			{
				universal = true;
			}
			else if (input == "4")
			{
				printf("Kings Holy Plate Selected:\nStrength: +2\nPerception: -1\nEndurance: +4\nCharisma: +4\nIntelligence: +1\nAgility: -3\nLuck: +2\n\n");
				printf("Current Stats:\n");
				cout << "Strength: " << c.characterStats[0] + 2 << endl << "Perception: " << c.characterStats[1] - 1 << endl << "Endurance: " << c.characterStats[2] + 4 << endl;
				cout << "Charisma: " << c.characterStats[3] + 4 << endl << "Intelligence: " << c.characterStats[4] + 1 << endl << "Agility: " << c.characterStats[5] - 3 << endl << "Luck: " << c.characterStats[6] + 2 << endl;
				uniqueSelected[0] = true;
			}
			else if (input == "5")
			{
				printf("Heavy Plate Selected:\nStrength: +4\nPerception: -4\nEndurance +6\nCharisma: +3\nIntelligence: +0\nAgility: -5\nLuck: +0\n\n");
				printf("Current Stats:\n");
				cout << "Strength: " << c.characterStats[0] + 4 << endl << "Perception: " << c.characterStats[1] - 4 << endl << "Endurance: " << c.characterStats[2] + 6 << endl;
				cout << "Charisma: " << c.characterStats[3] + 3 << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] - 5 << endl << "Luck: " << c.characterStats[6] << endl;
				uniqueSelected[1] = true;
			}
			else
			{
				callBack();

				continue;
			}

		}
		else if (c.characterType[1] == true)
		{
			printf("UNIQUE:\n");
			printf("4. Lamellar Armor\n5. Ring Mail\n");
			cin >> input;
			system("CLS");

			if (input == "1" || input == "2" || input == "3")
			{
				universal = true;
			}
			else if (input == "4")
			{
				printf("Lamellar Armor Selected:\nStrength: + 1\nPerception: + 2\nEndurance: + 1\nCharisma: + 2\nIntelligence: + 0\nAgility: + 2\nLuck: + 0\n\n");
				printf("Current Stats:\n");
				cout << "Strength: " << c.characterStats[0] + 1 << endl << "Perception: " << c.characterStats[1] + 2 << endl << "Endurance: " << c.characterStats[2] + 1 << endl;
				cout << "Charisma: " << c.characterStats[3] + 2 << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] + 2 << endl << "Luck: " << c.characterStats[6] << endl;
				uniqueSelected[2] = true;
			}
			else if (input == "5")
			{
				printf("Ring Mail Selected:\nStrength: + 0\nPerception: + 1\nEndurance: + 3\nCharisma: + 3\nIntelligence: + 0\nAgility: + 1\nLuck: + 0\n\n");
				printf("Current Stats:\n");
				cout << "Strength: " << c.characterStats[0] + 0 << endl << "Perception: " << c.characterStats[1] + 1 << endl << "Endurance: " << c.characterStats[2] + 3 << endl;
				cout << "Charisma: " << c.characterStats[3] + 3 << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] + 1 << endl << "Luck: " << c.characterStats[6] << endl;
				uniqueSelected[3] = true;
			}
			else
			{
				callBack();

				continue;
			}

		}
		else if (c.characterType[2] == true)
		{
			printf("UNIQUE:\n");
			printf("4. Light Plate\n5. Heavy Leather\n");
			cin >> input;
			system("CLS");

			if (input == "1" || input == "2" || input == "3")
			{
				universal = true;
			}
			else if (input == "4")
			{
				printf("Light Plate Selected:\nStrength: +2\nPerception: -2\nEndurance: +3\nCharisma: +1\nIntelligence: +0\nAgility: -2\nLuck: + 0\n\n");
				printf("Current Stats\n");
				cout << "Strength: " << c.characterStats[0] + 2 << endl << "Perception: " << c.characterStats[1] - 2 << endl << "Endurance: " << c.characterStats[2] + 3 << endl;
				cout << "Charisma: " << c.characterStats[3] + 1 << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] - 2 << endl << "Luck: " << c.characterStats[6] << endl;
				uniqueSelected[4] = true;
			}
			else if (input == "5")
			{
				printf("Heavy Leather Selected:\nStrength: +1\nPerception: -1\nEndurance: +3\nCharisma: +0\nIntelligence: +0\nAgility: +0\nLuck: +0\n\n");
				printf("Current Stats:\n");
				cout << "Strength: " << c.characterStats[0] + 1 << endl << "Perception: " << c.characterStats[1] - 1 << endl << "Endurance: " << c.characterStats[2] + 3 << endl;
				cout << "Charisma: " << c.characterStats[3] << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] << endl << "Luck: " << c.characterStats[6] << endl;
				uniqueSelected[5] = true;
			}
			else
			{
				callBack();

				continue;
			}

		}
		else if (c.characterType[3] == true)
		{
			printf("UNIQUE:\n");
			printf("4. Padded Leather\n5. Assasin's Robes\n");

			cin >> input;
			system("CLS");

			if (input == "1" || input == "2" || input == "3")
			{
				universal = true;
			}
			else if (input == "4")
			{
				printf("Padded Leather Selected:\nStrength: -1\nPerception: +3\nEndurance: +1\nCharisma: +0\nIntelligence: + 0\nAgility: +1\nLuck: +0\n\n");
				printf("Current Stats:\n");
				cout << "Strength: " << c.characterStats[0] - 1 << endl << "Perception: " << c.characterStats[1] + 3 << endl << "Endurance: " << c.characterStats[2] + 1 << endl;
				cout << "Charisma: " << c.characterStats[3] << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] + 1 << endl << "Luck: " << c.characterStats[6] << endl;
				uniqueSelected[6] = true;
			}
			else if (input == "5")
			{
				printf("Assasin's Robes Selected:\nStrength: -2\nPerception: +2\nEndurance: -1\nCharisma: +3\nIntelligence: +0\nAgility: +3\nLuck: +2\n\n");
				printf("Current Stats:\n");
				cout << "Strength: " << c.characterStats[0] - 2 << endl << "Perception: " << c.characterStats[1] + 2 << endl << "Endurance: " << c.characterStats[2] - 1 << endl;
				cout << "Charisma: " << c.characterStats[3] + 3 << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] + 3 << endl << "Luck: " << c.characterStats[6] + 2 << endl;
				uniqueSelected[7] = true;
			}
			else
			{
				callBack();

				continue;
			}

		}
		else if (c.characterType[4] == true)
		{
			printf("UNIQUE:\n");
			printf("4. Ebony Armor\n5. Peacekeeper Armor");

			cin >> input;
			system("CLS");

			if (input == "1" || input == "2" || input == "3")
			{
				universal = true;
			}
			else if (input == "4")
			{
				printf("Ebony Armor Selected:\nStrength: +3\nPerception: -3\nEndurance +4\nCharisma: +4\nIntelligence: +0\nAgility: -4\nLuck: +0\n\n");
				printf("Current Stats:\n");
				cout << "Strength: " << c.characterStats[0] + 3 << endl << "Perception: " << c.characterStats[1] - 3 << endl << "Endurance: " << c.characterStats[2] + 4 << endl;
				cout << "Charisma: " << c.characterStats[3] + 4 << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] - 4 << endl << "Luck: " << c.characterStats[6] << endl;
				uniqueSelected[8] = true;
			}
			else if (input == "5")
			{
				printf("Peacekeeper Armor Selected:\nStrength: +1\nPerception: -2\nEndurance +2\nCharisma: +2\nIntelligence: +0\nAgility: +3\nLuck: +0\n\n");
				printf("Current Stats:\n");
				cout << "Strength: " << c.characterStats[0] + 1 << endl << "Perception: " << c.characterStats[1] - 2 << endl << "Endurance: " << c.characterStats[2] + 2 << endl;
				cout << "Charisma: " << c.characterStats[3] + 2 << endl << "Intelligence: " << c.characterStats[4] << endl << "Agility: " << c.characterStats[5] + 3 << endl << "Luck: " << c.characterStats[6] << endl;
				uniqueSelected[9] = true;
			}
			else
			{
				callBack();

				continue;
			}

		}
		else
		{
			printf("How.... How did you manage this?\nERROR ERROR... ERROR... ERRO... ER......\n");
			_getch();
			system("CLS");
			printf("...");
			_getch();
			exit(0);
		}
		
		if (universal == true)
		{
			universalEquipment(c, input, universalsSelected);
		}

		printf("Press 1 to continue, 2 to go back\n");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			if (universalsSelected[0] == true)
			{
				c.characterStats[1] -= 1;
				c.characterStats[2] += 2;
				c.characterStats[3] -= 1;
				c.characterStats[5] += 1;

			}
			else if (universalsSelected[1] == true)
			{
				c.characterStats[0] += 1;
				c.characterStats[1] -= 2;
				c.characterStats[2] += 3;
				c.characterStats[3] += 1;
				c.characterStats[5] -= 1;
			}
			else if (universalsSelected[2] == true)
			{
				c.characterStats[0] += 2;
				c.characterStats[1] -= 3;
				c.characterStats[2] += 5;
				c.characterStats[3] += 2;
				c.characterStats[5] -= 3;
			}
			else if (uniqueSelected[0] == true)
			{
				c.characterStats[0] += 2;
				c.characterStats[1] -= 1;
				c.characterStats[2] += 4;
				c.characterStats[3] += 4;
				c.characterStats[4] += 1;
				c.characterStats[5] -= 3;
				c.characterStats[6] += 2;
			}
			else if (uniqueSelected[1] == true)
			{
				c.characterStats[0] += 4;
				c.characterStats[1] -= 4;
				c.characterStats[2] += 6;
				c.characterStats[3] += 3;
				c.characterStats[5] -= 5;
			}
			else if (uniqueSelected[2] == true)
			{
				c.characterStats[0] += 1;
				c.characterStats[1] += 2;
				c.characterStats[2] += 1;
				c.characterStats[3] += 2;
				c.characterStats[5] += 2;
			}
			else if (uniqueSelected[3] == true)
			{
				c.characterStats[1] += 1;
				c.characterStats[2] += 3;
				c.characterStats[3] += 3;
				c.characterStats[5] += 1;
			}
			else if (uniqueSelected[4] == true)
			{
				c.characterStats[0] += 2;
				c.characterStats[1] -= 2;
				c.characterStats[2] += 3;
				c.characterStats[3] += 1;
				c.characterStats[5] -= 2;
			}
			else if (uniqueSelected[5] == true)
			{
				c.characterStats[0] += 1;
				c.characterStats[1] -= 1;
				c.characterStats[2] += 3;
			}
			else if (uniqueSelected[6] == true)
			{
				c.characterStats[0] -= 2;
				c.characterStats[1] += 3;
				c.characterStats[2] += 1;
				c.characterStats[5] += 1;
			}
			else if (uniqueSelected[7] == true)
			{
				c.characterStats[0] -= 1;
				c.characterStats[1] += 2;
				c.characterStats[2] -= 1;
				c.characterStats[3] += 3;
				c.characterStats[5] += 3;
				c.characterStats[7] += 2;
			}
			else if (uniqueSelected[8] == true)
			{
				c.characterStats[0] += 3;
				c.characterStats[1] -= 3;
				c.characterStats[2] += 4;
				c.characterStats[3] += 4;
				c.characterStats[5] -= 4;
			}
			else if (uniqueSelected[9] == true)
			{
				c.characterStats[0] += 1;
				c.characterStats[1] -= 2;
				c.characterStats[2] += 2;
				c.characterStats[3] += 2;
				c.characterStats[5] += 3;
			}
			else
			{
				printf("IDK how you did this but good job ig? you broke my code and my heart </3\n");
				_getch();
				system("CLS");
				exit(0);
			}
		}
		else if (input == "2")
		{
			bool universalsSelected[3] = { false, false, false };
			bool uniqueSelected[10] = { false, false, false, false, false, false, false, false, false, false };
			system("CLS");

			continue;
		}
		else
		{
			bool universalsSelected[3] = { false, false, false };
			bool uniqueSelected[10] = { false, false, false, false, false, false, false, false, false, false };
			callBack();

			continue;
		}

		break;

	} while (1);

	system("CLS");
	printf("OK! So now that we've picked out our armor we can move on to the fun part, weapons!\nPress any key to continue\n");
	_getch();
	system("CLS");
	printf("Each weapon has its own characteristics, these include, peircing, blunt, or slash damage, weapon range, weapon accuracy and weight.\nPress any key to continue\n");
	_getch();
	system("CLS");
	printf("You will have access to a primary and secondary weapon, each class will have their own choice of weapons\nPress any key to continue\n");
	_getch();
	

do
{
	system("CLS");
	printf("Primary weapon:\n\n");
	
	if (c.characterType[0] = true)
	{
		printf("1. Longsword\n2. Shortsword\n3. Mace\n4. Axe\n5. Pollaxe\n");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			printf("Longsword Selected:\n\nSlash Damage: 6-8\nRange: 1 meter\nWeight: 4 lbs\n\n");
			knightPrimary[0] = true;

		}
		else if (input == "2")
		{
			printf("Shortsword Selected:\n\nSlash Damage: 4-6\nRange: 0.5 meter\nWeight: 2 lbs\n\n");
			knightPrimary[1] = true;

		}
		else if (input == "3")
		{
			printf("Mace Selected:\n\nBlunt Damage: 6-8\nRange: 1 meter\nWeight: 10 lbs\n\n");
			knightPrimary[2] = true;

		}
		else if (input == "4")
		{
			printf("Axe Selected:\n\nSlash Damage: 4-8\nRange: 1 meter\nWeight: 5 lbs\n\n");
			knightPrimary[3] = true;

		}
		else if (input == "5")
		{
			printf("Pollaxe Selected:\n\nPiercing/Slash Damge: 4-6\nRange: 1.5 meters\nWeight: 5 lbs\n\n");
			knightPrimary[4] = true;

		}
		else
		{
			callBack();
			continue;
		}

	}
	else if (c.characterType[1] = true)
	{
		
	}
	else if (c.characterType[2] = true)
	{
		
	}
	else if (c.characterType[3] = true)
	{
		
	}
	else if (c.characterType[4] = true)
	{
		
	}
	else
	{
	printf("ERROR NO CHARACTER TYPE SELECTED");
	_getch();
	system("CLS");
	}

	printf("Press 1 to continue, 2 to go back\n");
	cin >> input;

	if (input == "1")
	{

	}
	else if (input == "2")
	{
		continue;
		bool knightPrimary[5] = { false, false, false, false, false };
	}
	else 
	{
		callBack();
		continue;
		bool knightPrimary[5] = { false, false, false, false, false };
	}
	
} while (1);
	
}

int main()
{
	int gameDifficulty;
	bool intro = true;	
	string input;

	struct characterInformation c;

	srand(0);
	srand((unsigned)time(NULL));

	printf("Hello adventurer, what would you like to be known as?\n");
	cin >> c.playerName;

	if (c.playerName == "DEV.")
	{
		while (1)
		{
			system("CLS");
			printf("What function would you like to go to?\n");
			printf("1. Introduction\n2. callBack\n3. callBackNoCLS\n4. statSelection\n5. statChecker\n6. characterSelection\n7. equipmentSelectin\n");
			cin >> input;
			system("CLS");

			if (input == "1")
			{
				introduction(c);
			}
			else if (input == "2")
			{
				callBack();
			}
			else if (input == "3")
			{
				callBackNoCLS();
			}
			else if (input == "4")
			{
				statSelection(c);
			}
			else if (input == "5")
			{
				statChecker(c);
			}
			else if (input == "6")
			{
				characterSelection(c);
			}
			else if (input == "7")
			{
				equipmentSelection(c);
			}
			else
			{
				callBack();
				continue;
			}

			system("CLS");
			printf("Press 1 to exit, 2 to visit new function\n");
			cin >> input;

			if (input == "1")
			{
				break;
			}
			else
			{
				continue;
			}

		}
	}
	
	system("CLS");

	cout << "Welcome to my RPG, " << c.playerName << ", this is a c++ text based game made by me, Joey Soroka.\nAnd before we start I would like to give credit to those who helped me with this amazing project.\nPress any key to continue" << endl;
	_getch();
	system("CLS");
	printf("CREDITS:\n\nCODING SUPPORT:\nEric Pace\nSlater Swart\nTucker Norris\n\n");
	printf("CREATIVE HELP:\nIssac Morine\n\n");
	printf("MORAL SUPPORT:\nEric Pace\nIssac Morine\n\n");
	printf("Press any key to continue\n");
	_getch();
	system("CLS");

	if (intro = true)
	{
		introduction(c);

		statSelection(c);

		characterSelection(c);
		
		equipmentSelection(c);

		intro = false;

	}
	printf("Now that you've finished your customization we can move on to some more interesting things... LIKE CHARACTER HEALTH!!!\n");
	_getch();
	system("CLS");
	printf("Because you've chosen");
	if (c.characterType[0] == true)
	{
		printf("knight as your class");
		c.characterHealth = 12;
	}
	else if (c.characterType[1] == true)
	{
		printf("calvary as your class");
		c.characterHealth = 8;
	}
	else if (c.characterType[2] == true)
	{
		printf("spearman as your class");
		c.characterHealth = 8;
	}
	else if (c.characterType[3] == true)
	{
		printf("archer as your class");
		c.characterHealth = 6;
	}
	else if (c.characterType[4] == true)
	{
		printf("swordsman as your class");
		c.characterHealth = 10;
	}
	else
	{
		printf("ERROR NO CHARACTER TYPE SELECTED");
	}
	cout << " your character health is given a value of " << c.characterHealth;
	
	_getch();
	system("CLS");

	printf("Now for damage, since you've chosen ");

	return 0;
}