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

int main()
{
	enum sizes { tiny = 8, medium = 16, large = 24 };
	float popcorn;
	float candy;
	float chips;
	float drinks;
	float drinkSize;
	float drinkPrice;

	printf("Welcome to the theater, place your order below:\n# of popcorn ($5.00 ea.): ");
	cin >> popcorn;
	printf("# of m&ms ($1.00 ea.): ");
	cin >> candy;
	printf("# of chips ($1.50 ea.): ");
	cin >> chips;
	while (1)
	{
		printf("Drink Size: 8oz/16oz/24oz ($1.00, $1.50, $2.00): ");
		cin >> drinkSize;
		if (drinkSize == tiny)
		{
			drinkPrice = 1;
		}
		else if (drinkSize == medium)
		{
			drinkPrice = 1.5;
		}
		else if (drinkSize == large)
		{
			drinkPrice = 2;
		}
		else
		{
			printf("We don't offer that size please try again\n");
			continue;
		}
		break;
	}
	printf("# of drinks: ");
	cin >> drinks;

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