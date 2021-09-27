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
		
Common Commands and what they do:
_getch(); // Kind of like a break, the code waits here until any key is pressed
system("CLS"); // Clears the screen of any text that has been outputed, may not want to use this when clearing specific text
continue; // This command will cause a loop to go back to the beginnig
break; // This command will cause a loop to "break" and stop repeating
void example()  // A void is a function, you can call a fucntion any time you want under main and the code in a void will be executed, helpful for saving space
{      			// the parameters of a void can be set to pass a local variable through by reference, to do this, when you call a void under main, type the name
	 			// of the variable you want to pass, then in the void parameters, define the variable and give it the name it will be called under that void
}	
cin >> example; // This is an easy way to collect player input, however be careful, as the input is stored and if the game asks for another input it will automatically
				// use the one given previously unless another cin command is given
while (example = true) // While is a type of loop that will continuesly execute the commands inside until the while statement is no longer true or a break; command is given
{

}
srand(0); and srand((unsigned)time(NULL)); // Both of these commands should only be executed once at the beginning of the code, as they are what gives the number for the
										   // srand randomizer, initilizing these more than once will cause an error
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
	printf(" a noble from a long forgotten land, holds the key to salvation.\n\t Press any key to continue\n");

	_getch();

	system("CLS");

	printf("What can only be described as a gate to hell has opened deep undergrund,\nunleashing swarms of monsters of your worst nightmares.\n");
	printf("Hundreds, no THOUSANDS, have tried to close said gate, however none have succeeded.\nYou have been called upon by your king to dispatch of this threat.\n");

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

	void characterSelection(int &strength, int &perception, int &endurance, int &charisma, int &intelligence, int &agility, int &luck, string playerName, bool &knight, bool &calvary, bool &spearman, bool &archer, bool &swordsman)
{
	int input;
	int luckMin = 1;
	int luckMax = 10;
	bool reselectChar = true;

	system("CLS");

	while (reselectChar = true)
	{
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
				reselectChar = false;
				
				break;
			}
			else if (input == 2)
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
				reselectChar = false;
				
				break;
			}
			else if (input == 2)
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
				reselectChar = false;
				
				break;
			}
			else if (input == 2)
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
				reselectChar = false;
				
				break;
			}
			else if (input == 2)
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
				reselectChar = false;
				
				break;
			}
			else if (input == 2)
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

void knightEquipment()
{
	printf("As a knight, you get to pick from a wide assortment of heavy equipment.\nMainly consisting of plate armour and a longsword.\nHowever slight variations are definitely possible.\n ");
	printf("Press any key to choose your armour.\n");

	_getch();

	system("CLS");


}

	void equipmentSelection(string playerName, bool knight, bool calvary, bool spearman, bool archer, bool swordsman)
{

	int input;

	bool selectingEquipment = true;

	while (selectingEquipment = true)
	{
		cout << "Welcome to the armoury " << playerName << "!" << endl;
		printf("Press any key to continue\n");

		_getch();

		system("CLS");

		if (knight == true)
		{
			knightEquipment();
		}
		else if (calvary == true)
		{

		}
		else if (spearman == true)
		{

		}
		else if (archer == true)
		{

		}
		else if (swordsman == true)
		{

		}
		else
		{
			callBack();

			continue;

		}

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

		characterSelection(strength, perception, endurance, charisma, intelligence, agility, luck, playerName, knight, calvary, spearman, archer, swordsman);

		system("CLS");

		equipmentSelection(playerName, knight, calvary, spearman, archer, swordsman);


	}

	
	
	return 0;
}

