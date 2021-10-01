/*
Author: Joey Soroka
File Name: Bus Charter.cpp
Project Name: Bus Charter
Purpose: To figure out how many busses and vans will needed for a tour group
Pseudocode:
Maintenance Log:
10/1/21:	
*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>

using namespace std;

int main()
{
	int tourists;
	string playerName;
	int busCapacity = 60;
	int vanCapacity = 7;
	int input;
	bool reselect = false;

	printf("Hello, this is a tour calculator meant to help you figure out how many busses and vans you will need for your tour group! Please enter your name below.\n");
	
	cin >> playerName;

	system("CLS");

	cout << "Welcome " << playerName;
	printf(". This is a tour calculator meant to help you figure out how many busses and vans you will need for your tour. First enter the number of tourists below.\n");

	while (1)
	{
		if (reselect == true)
		{
			printf(" Please re-enter the correct number of tourists.\n");
		}

		cin >> tourists;

		system("CLS");

		cout << "You have entered " << tourists << "tourists, is this correct?" << endl;
		printf("Press 1 to continue, 2 to reselect number of tourists");

		system("CLS");

		switch (input)

			case 1:
				tourists 

			case 2:


			default:
				reselect = true;
				continue;
	}
}
