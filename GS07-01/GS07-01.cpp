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
	float drinkPrice;
	float popcorn;
	sizes popcorn_size;
	sizes size = none;
	int ans;
	
	while (1)
	{
		printf("Popcorn Size: ($1.00, $1.50, $2.00):\n0: None\n1: Tiny\n2: Medium\n3: Large \n");
		cin >> ans;
		size = (sizes)ans;

		switch (size)
		{
		case none:
			drinkPrice = 0;
			break;
		case tiny:
			drinkPrice = 1;
			break;
		case medium:
			drinkPrice = 1.5;
			break;
		case large:
			drinkPrice = 2;
			break;
		default:
			printf("That option isn't supported please try again...");
			_getch();
			continue;
		}
		break;
	}
	printf("Welcome to the theater, place your order below:\n# of popcorn ($5.00 ea.): ");
	cin >> popcorn;
	printf("# of m&ms ($1.00 ea.): ");
	cin >> candy;
	printf("# of chips ($1.50 ea.): ");
	cin >> chips;
	while (1)
	{
		printf("Drink Size: ($1.00, $1.50, $2.00):\n0: None\n1: Tiny\n2: Medium\n3: Large \n");
		cin >> ans;
		size = (sizes)ans;
		
		switch (size)
		{
		case none:
			drinkPrice = 0;
			break;
		case tiny:
			drinkPrice = 1;
			break;
		case medium:
			drinkPrice = 1.5;
			break;
		case large:
			drinkPrice = 2;
			break;
		default:
			printf("That option isn't supported please try again...");
			_getch();
			continue;
		}
		break;
	}

	if (size != none)
	{
		printf("# of drinks: ");
		cin >> drinks;
	}
	else
	{
		drinks = 0;
	}

	system("CLS");
	float cost = (5 * popcorn) + candy + (1.5 * chips) + (drinkPrice * drinks);
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