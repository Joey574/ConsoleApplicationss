#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h> // Uses functions named after shapes beware for classes
#include <chrono> // needed for sleep for
#include <thread>
#include <math.h>
#include <sstream> // needed for files
#include <fstream> // needed for files
#include <cwchar>
#include <algorithm> // needed for vector sort and other cool things

#include "Classes.h"
#include "Structs.h"

NPC::NPC()
{

}

// setters

void NPC::setShopID(int s)
{
	shopID = s;
}

// getters

int NPC::getShopID()
{
	return shopID;
}

// accesories 

void NPC::shopMenu(struct gm& gm)
{
	string input;


	while (1)
	{
		system("CLS");
		printf("Welcome to my shop! What would you like to purchase?\nMenu:\n");
		printf("1: Fuel\n2: Better Ship\n3: Back\nInput: ");
		cin >> input;
		system("CLS");

		if (input == "1")
		{

		}
		else if (input == "2")
		{
			
			printf("Are you sure you want to upgrade? That will cost 20 supplies.\nMenu:\n1: Yes\n2: Back\nInput: ");
			cin >> input;
			system("CLS");

			if (input == "1")
			{
				if (gm.p.supplies >= 20 && gm.s.shipID <= 2)
				{
					gm.s.shipID += 1;
				}
				else
				{
					printf("")
				}
			}
			else if (input == "2")
			{

			}
			else
			{
				printf("INVALID INPUT...");
				_getch();
				continue;
			}

		}
		else if (input == "3")
		{
			break;
		}
		else
		{
			system("CLS");
			printf("INVALID INPUT...");
			_getch();
			continue;
		}
	}
	

}