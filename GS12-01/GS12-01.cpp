/*
Author: Joey Soroka
File Name: GS12-01.cpp
Project Name: GS12-01 (ellipse class)
Purpose: Create an ellipse class and calculate area and circumfrence
Pseudocode: using a header file to store the class it asks user for the radii before calculating area and circumference
Maintenance Log:

*/

#pragma once
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
//#include <windows.h>
#include <chrono>
#include <thread>
#include <math.h>
#include <sstream>
#include <fstream>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

#include "Ellipse.h"

int main()
{
	Ellipse e;
	float r1;
	float r2;
	string input;


	printf("Enter value of first radius: ");
	cin >> r1;
	printf("Enter value of second radius: ");
	cin >> r2;
	e.setRadius1(r1);
	e.setRadius2(r2);
	sleep_for(500000000ns);

	for (int i = 0; i < 5; i++)
	{
		system("CLS");
		printf(".");
		sleep_for(250000000ns);
		printf(".");
		sleep_for(250000000ns);
		printf(".");
		sleep_for(250000000ns);
	}


	while (1)
	{
		system("CLS");
		printf("What would you like to know?\n");
		printf("1. Radii?\n");
		printf("2. Area?\n");
		printf("3. Circumfrence?\n");
		printf("4. EXIT\n");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			cout << "Radius 1: " << e.getRadius1() << endl;
			cout << "Radius 2: " << e.getRadius2() << endl;
			_getch();
		}
		else if (input == "2")
		{
			cout << "Area: " << e.area() << endl;
			_getch();
		}
		else if (input == "3")
		{
			cout << "Circumfrence: " << e.circumference() << endl;
			_getch();
		}
		else if (input == "4")
		{
			break;
		}
		else
		{
			printf("Incorrect input");
			printf(".");
			sleep_for(250000000ns);
			printf(".");
			sleep_for(250000000ns);
			printf(".");
			sleep_for(500000000ns);
			system("CLS");
			continue;
		}
	}

	return 0;
}

