/*
Author: Joey Soroka
File Name: Bus Charter.cpp
Project Name: Bus Charter
Purpose: To figure out how many busses and vans will needed for a tour group
Pseudocode: Asks users name, then asks for number of tourists, using this it calculates the number of busses and vans needed, then tells the user if some will
			neeed to walk, finally asks user if they want to repeat code or exit.
Maintenance Log:
10/1/21:	Started code and got user name
10/4/21:	Finished code, everything seems to be working correctly, not quite idiot proof yet though
*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 

using namespace std;

int main()
{
	string playerName;
	int tourists;
	int remainder;
	int bussesNeeded;
	int vansNeeded;
	int input;
	bool reselect = false;

	printf("Hello, this is a tour calculator meant to help you figure out how many busses and vans you will need for your tour group! Please enter your name below.\n");
	
	cin >> playerName;

	system("CLS");

	cout << "Welcome " << playerName;
	

	while (1)
	{
		printf(". This is a tour calculator meant to help you figure out how many busses and vans you will need for your tour. First enter the number of tourists below.\n");
		if (reselect == true)
		{
			printf("Please re-enter the correct number of tourists.\n");
		}

		cin >> tourists;

		system("CLS");

		cout << "You have entered " << tourists << " tourists, is this correct?" << endl;
		printf("Press 1 to continue, 2 to reselect number of tourists\n");

		cin >> input;

		system("CLS");

		switch (input)
		{
		case 1:
			bussesNeeded = tourists / 60;
			remainder = (tourists % 60) % 7;
			vansNeeded = (tourists % 60) / 7;

			cout << "You will need " << bussesNeeded << " busses." << endl;
			cout << "This will mean that " << vansNeeded << " vans will be needed" << endl;
			cout << "Finally " << remainder << " people will need to walk or find other transportation" << endl;
			printf("Press any key to continue\n");

			_getch();

			system("CLS");

			break;
		case 2:
			reselect = true;
			continue;
		default:
			reselect = true;
			continue;
		}
		break;
	}
	printf("I hope this was helpful to you, press 1 to exit, press 2 to restart program\n");

	cin >> input;

	if (input == 1)
	{
		return 0;
	}
	else if (input == 2)
	{
		system("CLS");

		main();
	}
		
}
