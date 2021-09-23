/*
Author: Joey Soroka
Project Name: pair programming
File Name: Pair programming.cpp
Purpose: Allow the user to choose the min and max for different outputs
Pseudocode:
Maintenance Log:
9/22/21:	Started project, added random float, random user genertated float and int
9/23/21:	Working on getting random character from user, currently running into a "file not found issue"
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
	float floatRan;
	float floatRanMax = 1.0;
	float floatRanMin = 0.0;
	int uInt;
	int uIntMax;
	int uIntMin;
	float uFloat;
	float uFloatMax;
	float uFloatMin;
	char uChar;
	char uCharMax;
	char uCharMin;
	

	srand(0);
	srand((unsigned)time(NULL));
	
	printf("Hello there! Would you like to see a random float?\n\tPress any key to continue\n");

	_getch();

	system("CLS");

	floatRan = floatRanMin + (float)(rand()) / ((float)RAND_MAX / (floatRanMax - floatRanMin));
	printf("Random Float:%f\n", floatRan);
	printf("WOW wasn't that just SO entertaining, would you like to enter the parameters for your OWN random float?\n");
	printf("Dont answer that, I already know the answer\n\tPress any key to continue");

	_getch();

	system("CLS");

	printf("Enter the low parameter below:\n");
	cin >> uFloatMin;
	
	system("CLS");

	printf("Enter the high parameter below:\n");
	cin >> uFloatMax;

	system("CLS");

	uFloat = uFloatMin + (float)(rand()) / ((float)RAND_MAX / (uFloatMax - uFloatMin));
	printf("Random Float:%f\n", uFloat);

	printf("\tPress any key to continue");

	_getch();

	system("CLS");

	printf("Now since you had so much fun with that why don't we try a random integer as well!\n\tPress any key to continue");

	_getch();

	printf("Enter the low parameter below:\n");
	cin >> uIntMin;

	system("CLS");

	printf("Enter the high parameter below:\n");
	cin >> uIntMax;

	system("CLS");

	uInt = uIntMin + rand() % (uIntMax - uIntMin + 1);
	printf("Random Integer:%d\n");

	printf("OMG INSANE, NOW LET's DO CHARACTERS!\n\tPress any key to continue");

	_getch();

	printf("Enter the low parameter below:\n");
	cin >> uCharMin;

	system("CLS");

	printf("Enter the high parameter below:\n");
	cin >> uCharMax;

	system("CLS");

	uChar = 'a' + rand() % (uIntMax - uIntMin);
	printf("Random Character:%c", uChar);

	return 0;

}

