/*
Author: Joey Soroka
File Name: Looping quiz.cpp
Project Name: GS04-01
Purpose: A looping quiz where user MUST get a question correct before moving on
Pseudocode: A quiz with 3 question where the user must get a question right before continuing, asks user for name before starting quiz
Maintenance Log:
11/23/21:	Copied code from non looping quiz to modify
12/2/21:	Added loops to make sure user gets a question right before moving on
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
	string name;
	string input;
	bool questionOne = true;
	bool questionTwo = true;
	bool questionThree = true;
	printf("This is a looping science quiz in which you must get a question right before moving on...\n");
	_getch();
	system("CLS");
	printf("Please provide your name before we continue...\n");
	cin >> name;
	while (1)
	{
		do
		{
			system("CLS");
			cout << name << ", the first question is; How much of the Earth's oxygen is produced by the amazon rainforest?" << endl;
			printf("1. 20%\t2. 30%\t3. 15%\t4. 10%\n");
			cin >> input;
			system("CLS");

			if (input == "1")
			{
				cout << "Correct " << name << ", good job!\n";
				questionOne = false;
				_getch();
			}
			else if (input == "2" || input == "3" || input == "4")
			{
				cout << "Incorrect " << name << ", please try again\n";
				_getch();
				continue;
			}
			else
			{
				printf("Incorect input detected, please try again\n.");
				_getch();
				continue;
			}
		} while (questionOne == true);

		do
		{
			system("CLS");
			cout << name << ", the second question is, how long does it take for your body to replace themselves?" << endl;
			printf("1. 7-10 years\t2. 7-10 months\t3. 3 weeks\t4. 2 years\n");
			cin >> input;
			system("CLS");

			if (input == "1")
			{
				cout << "Correct " << name << ", good job!\n";
				questionTwo = false;
				_getch();
			}
			else if (input == "2" || input == "3" || input == "4")
			{
				cout << "Incorrect " << name << ", please try again\n";
				_getch();
				continue;
			}
			else
			{
				printf("Incorect input detected, please try again\n.");
				_getch();
				continue;
			}
		} while (questionTwo == true);

		do
		{
			system("CLS");
			cout << name << ", the third amd final question is, who invented the electric chair?" << endl;
			printf("1. Electrician\t2. Solder\t3.Dentist\t4. Prison gaurd\n");
			cin >> input;
			system("CLS");

			if (input == "3")
			{
				cout << "Correct " << name << ", good job, +4 points" << endl;
				questionThree = false;
				_getch();
			}
			else if (input == "1" || input == "2" || input == "4")
			{
				cout << "Incorrect " << name << ", please try again\n";
				_getch();
				continue;
			}
			else
			{
				printf("Incorect input detected, please try again\n.");
				_getch();
				continue;
			}
		} while (questionThree == true);

		printf("Congratulations, press 1 to repeat the test, or 2 to exit\n");
		cin >> input;
		if (input == "1")
		{
			continue;
		}
		else
		{
			break;
		}
	}
	return 0;
}
