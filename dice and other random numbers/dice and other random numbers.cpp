/*
Author: Joey Soroka
Project Name: dice and other random numbers
File Name: dice and other random numbers.cpp
Purpose: To create a 6 sided die, a 12 sided die, a random float between 0.0 and 5.0, and a random upper case letter
Pseudocode:
Maintenance Log:
9/17/21:	Started project setting up code
*/


#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>




int main()
{
	int secondMax = 12;
	int min = 1;
	int max = 6;
	int sixFacedDie;
	int _12SidedDie;
	srand(0);
	srand((unsigned)time(NULL));
	sixFacedDie = min + rand() % (max - min + 1);
	printf("Six sided die:%d\n", sixFacedDie);
	_12SidedDie = min + rand() % (secondMax - min + 1);
	printf("Twelve sided die:%d\n", _12SidedDie);



}

