/*
Author: Joey Soroka
File Name: GS07-01.cpp
Project Name: GS07-01 (concession stand)
Purpose: Using an enum program a concession stand that calculates cost + tax of items that user purchases
Pseudocode: Using an enum to determine size code will ask user to input # of items they wish and size of drink they want then calculates cost + tax
Maintenance Log:
12/15/21:	Started and finished project
*/

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h>
#include <math.h>
#include <fstream>
using namespace std;

float taxCalculator(float cost);

enum sizes { none = 0, tiny, medium, large };

int main()
{

	float candy;
	float chips;
	float drinks;
	float popcorn;
	sizes candy_size;
	sizes popcorn_size;
	sizes chips_size;
	sizes drink_size;
	int ans;
	
		printf("Welcome to the theater, place your order below: \n");
		printf("Popcorn Size: ($5.00, $10.00, $15.00):\n0: None\n1: Tiny\n2: Medium\n3: Large \n");
		cin >> ans;
		
		if (ans == 1)
		{
			popcorn_size = tiny;
		}
		else if (ans == 2)
		{
			popcorn_size = medium;
		}
		else if (ans == 3)
		{
			popcorn_size = large;
		}
		else if (ans == 0)
		{
			popcorn_size = none;
		}

		if (popcorn_size != none)
		{
			printf("# of popcorn: ");
			cin >> popcorn;
		}

	printf("m&m size: ($1.50, $2.00, $3.50):\n0: None\n1: Tiny\n2: Medium\n3: Large \n");
	cin >> ans;

	if (ans == 1)
	{
		candy_size = tiny;
	}
	else if (ans == 2)
	{
		candy_size = medium;
	}
	else if (ans == 3)
	{
		candy_size = large;
	}
	else if (ans == 0)
	{
		candy_size = none;
	}

	if (candy_size != none)
	{
		printf("# of m&ms: ");
		cin >> candy;
	}

	printf("chips size: ($2.00, $3.00, $4.00):\n0: None\n1: Tiny\n2: Medium\n3: Large \n");
	cin >> ans;

	if (ans == 1)
	{
		chips_size = tiny;
	}
	else if (ans == 2)
	{
		chips_size = medium;
	}
	else if (ans == 3)
	{
		chips_size = large;
	}
	else if (ans == 0)
	{
		chips_size = none;
	}

	if (chips_size != none)
	{
		printf("# of m&ms: ");
		cin >> chips;
	}

	printf("drink size: ($2.00, $3.00, $4.00):\n0: None\n1: Tiny\n2: Medium\n3: Large \n");
	cin >> ans;

	if (ans == 1)
	{
		drink_size = tiny;
	}
	else if (ans == 2)
	{
		drink_size = medium;
	}
	else if (ans == 3)
	{
		drink_size = large;
	}
	else if (ans == 0)
	{
		drink_size = none;
	}

	if (drink_size != none)
	{
		printf("# of drinks: ");
		cin >> drinks;
	}

	if (drink_size != none)
	{
		printf("# of drinks: ");
		cin >> drinks;
	}
	else
	{
		drinks = 0;
	}

	system("CLS");
	float cost = ((popcorn_size * 5) * popcorn) + (candy * (candy_size + 0.5)) + (chips * (chips_size + 1)) + ((drink_size + 1) * drinks);
	float tax = taxCalculator(cost);
	cout << "Cost: " << cost << endl;
	cout << "Tax: " << tax << endl;
	cost += tax;
	cout << "Total cost: " << cost << endl;

	return 0;
}

float taxCalculator(float cost)
{
	float tax = cost * 0.1;
	return tax;
}