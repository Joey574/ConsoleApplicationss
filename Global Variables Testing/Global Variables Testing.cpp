/*
Author: Joey Soroka
File Name: Global Variables Testing.cpp
Purpose: To help me better understand global variables
Pseudocode: outputs strength to the screen, then adds to it in functions to see if it changes in main
Maintenance Log:
9/23/21:	Testing Global Variables, works fine
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <vector>

int strength = 6;

void numbers()
{

	strength += 1;
	printf("strength:%d", strength);

	_getch();

}

int main()
{
	
	strength += 1;
	printf("strength:%d", strength);

	_getch();

	system("CLS");

	numbers();

	system("CLS");

	printf("strength:%d", strength);

	_getch();

	system("CLS");

	return 0;

}


