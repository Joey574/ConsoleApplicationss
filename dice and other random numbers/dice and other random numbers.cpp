/*
Author: Joey Soroka
Project Name: dice and other random numbers
File Name: dice and other random numbers.cpp
Purpose: To create a 6 sided die, a 12 sided die, a random float between 0.0 and 5.0, and a random upper case letter
Pseudocode:
Maintenance Log:
9/17/21:	Started project setting up code
9/20/21:	Set up all the randomizers, so far working properly
*/


#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;




int main()
{
	int secondMax = 12;
	int min = 1;
	int max = 6;
	int sixFacedDie;
	int _12SidedDie;
	float floatMax = 5.0;
	float floatMin = 0.0;
	float floatRan;
	int randomizer;
	char characters;
			
	srand(0);
	srand((unsigned)time(NULL));
	
	sixFacedDie = min + rand() % (max - min + 1);
	printf("Six sided die:%d\n", sixFacedDie);
	
	_12SidedDie = min + rand() % (secondMax - min + 1);
	printf("Twelve sided die:%d\n", _12SidedDie);
	
	floatRan = floatMin + (float)(rand()) / ((float)(RAND_MAX / (floatMax - floatMin)));
	printf("Random Float:%f\n", floatRan);
	
	characters = 'a' + rand() % 26 - 32;
	/* 
	first generates a random number 1-26
	next it converts to a character from a-z, subtracts 32 to change from lowercase to uppercase as this is the 
	ASCII code difference between uppercase and lowercase characters
	*/
	printf("Random Character:%c\n", characters);

	return 0;
}

