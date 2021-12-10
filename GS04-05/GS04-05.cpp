/*
Author: Joey Soroka
File Name: GS04-05.cpp
Project Name: GS04-05 (looping maze)
Purpose: Similar to the maze project the looping maze will funciton the same however won't close the doors behind you
Pseudocode:
Maintenance Log:
12/9/21:    Started the project
*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h>
#include <vector>
#include <windows.h>
using namespace std;

int main()
{
	string input;
	bool room1 = true;
	bool room2 = false;
	bool room3 = false;
	bool room4 = false;
	bool room5 = false;
	bool room6 = false;
	bool room7 = false;
	bool room8 = false;
	bool room9 = false;

	printf("You are in a maze with 9 different rooms, try to find a way out!\n");
	_getch();

	while (room9 == false)
	{
		system("CLS");
		if (room1 == true)
		{
			printf("1. Go right\n2. Go down\n");
			cin >> input;
			if (input == "1")
			{
				room2 = true;
			}
			else if (input == "2")
			{
				room4 = true;
			}
			room1 = false;
		}
		else if (room2 == true)
		{
			printf("1. Go left\n2. Go right\n3. Go down\n");
			cin >> input;
			if (input == "1")
			{
				room1 = true;
			}
			else if (input == "2")
			{
				room3 = true;
			}
			else if (input == "3")
			{	
				room5 = true;
			}
			room2 = false;
		}
		else if (room3 == true)
		{
			printf("1. Go left\n");
			cin >> input;
			if (input == "1")
			{
				room2 = true;
			}
			room3 = false;
		}
		else if (room4 == true)
		{
			printf("1. Go up\n2. Go right\n3. Go down\n");
			cin >> input;
			if (input == "1")
			{
				room1 = true;
			}
			else if (input == "2")
			{
				room5 = true;
			}
			else if (input == "3")
			{
				room7 = true;
			}
			room4 = false;
		}
		else if (room5 == true)
		{
			printf("1. Go up\n2. Go left\n3. Go right\n");
			cin >> input;
			if (input == "1")
			{
				room2 = true;
			}
			else if (input == "2")
			{
				room4 = true;
			}
			else if (input == "3")
			{
				room6 = true;
			}
			room5 = false;
		}
		else if (room6 == true)
		{
			printf("1. Go left\n");
			cin >> input;
			if (input == "1")
			{
				room5 = true;
			}
			room6 = false;
		}
		else if (room7 == true)
		{
			printf("1. Go up\n2. Go right\n");
			cin >> input;
			if (input == "1")
			{
				room4 = true;
			}
			else if (input == "2")
			{
				room8 = true;
			}
			room7 = false;
		}
		else if (room8 == true)
		{
			printf("1. Go right\n");
			cin >> input;
			if (input == "1")
			{
				room9 = true;
			}
			room8 = false;
		}
	}
	printf("Congratulations you made it out!\n");

	return 0;
}

