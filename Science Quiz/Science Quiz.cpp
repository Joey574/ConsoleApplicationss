/*
Author: Joey Soroka
File Name: Science Quiz.cpp
Project Name: Science Quiz using if
Purpose: Gives the user a science quiz using if
Pseudocode: Asks the user 3 multiple choice questions then grades it and gives a letter grade as well
Maintenance Log
10/7/21:	Set up quiz, asks 3 questions with 4 different answeres to each one, at the end of the quiz it will automatically grade it and give a letter grade
10/11/21:	Set up code so there was only one return 0, decrease lines of code by about 3
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
	string name;
	string input;
	float score = 0;
	bool retakeTest = false;

	printf("Welcome to this science quiz, and who might you be?\n");
	cin >> name;
	system("CLS");

	cout << "Hello " << name << "! Press 1 to start the quiz, or 2 to exit." << endl;
	cin >> input;
	system("CLS");

	if (input == "1")
	{
		do
		{
			cout << name << ", the first question is; How much of the Earth's oxygen is produced by the amazon rainforest?" << endl;
			printf("1. 20%\t2. 30%\t3. 15%\t4. 10%\n");
			cin >> input;
			system("CLS");

			if (input == "1")
			{
				cout << "Correct " << name << ", good job, +4 points" << endl;
				score += 4;
				_getch();
			}
			else if (input == "2")
			{
				cout << "Sorry " << name << ", that is incorrect, -1 point" << endl;
				score -= 1;
				_getch();
			}
			else if (input == "3")
			{
				cout << "Sorry " << name << ", that is incorrect, -1 point" << endl;
				score -= 1;
				_getch();
			}
			else if (input == "4")
			{
				cout << "Sorry " << name << ", that is incorrect, -1 point" << endl;
				score -= 1;
				_getch();
			}
			else
			{
				printf("Incorect input detected, no points awarded.");
				_getch();
			}

			system("CLS");
			cout << name << ", the second question is, how long does it take for your body to replace themselves?" << endl;
			printf("1. 7-10 years\t2. 7-10 months\t3. 3 weeks\t4. 2 years\n");
			cin >> input;
			system("CLS");

			if (input == "1")
			{
				cout << "Correct " << name << ", good job, +4 points" << endl;
				score += 4;
				_getch();
			}
			else if (input == "2")
			{
				cout << "Sorry " << name << ", that is incorrect, -1 point" << endl;
				score -= 1;
				_getch();
			}
			else if (input == "3")
			{
				cout << "Sorry " << name << ", that is incorrect, -1 point" << endl;
				score -= 1;
				_getch();
			}
			else if (input == "4")
			{
				cout << "Sorry " << name << ", that is incorrect, -1 point" << endl;
				score -= 1;
				_getch();
			}
			else
			{
				printf("Incorect input detected, no points awarded.");
				_getch();
			}

			system("CLS");
			cout << name << ", the last question is, who invented the electric chair?" << endl;
			printf("1. Electrician\t2. Solder\t3.Dentist\t4. Prison gaurd\n");
			cin >> input;
			system("CLS");


			if (input == "1")
			{
				cout << "Sorry " << name << ", that is incorrect, -1 point" << endl;
				score -= 1;
				_getch();
			}
			else if (input == "2")
			{
				cout << "Sorry " << name << ", that is incorrect, -1 point" << endl;
				score -= 1;
				_getch();
			}
			else if (input == "3")
			{
				cout << "Correct " << name << ", good job, +4 points" << endl;
				score += 4;
				_getch();
			}
			else if (input == "4")
			{
				cout << "Sorry " << name << ", that is incorrect, -1 point" << endl;
				score -= 1;
				_getch();
			}
			else
			{
				printf("Incorect input detected, no points awarded.");
				_getch();
			}
			
			system("CLS");
			cout << "You scored " << score << " out of 12 possible points" << endl;
			score = (score / 12) * 100;
			if (score >= 91)
			{
				printf("You got an A!\n");
			}
			else if (score >= 84 && score < 91)
			{
				printf("You got an A-!\n");
			}
			else if (score >= 80 && score < 84)
			{
				printf("You got a B+!\n");
			}
			else if (score >= 76 && score < 80)
			{
				printf("You got a B!\n");
			}
			else if (score >= 71 && score < 76)
			{
				printf("You got a B-!\n");
			}
			else if (score >= 67 && score < 71)
			{
				printf("You got a C+\n");
			}
			else if (score >= 63 && score < 67)
			{
				printf("You got a C\n");
			}
			else if (score >= 58 && score < 63)
			{
				printf("You got a C-\n");
			}
			else if (score >= 51 && score < 58)
			{
				printf("You got a D+\n");
			}
			else if (score >= 42 && score < 51)
			{
				printf("You got a D\n");
			}
			else if (score < 42)
			{
				printf("You got a F\n");
			}
			else
			{
				printf("Something isn't working right");
			}
			_getch();
			system("CLS");
			printf("Press 1 to exit, 2 to retake quiz\n");
			cin >> input;
			if (input == "1")
			{
				break;
			}
			else if (input == "2")
			{
				score = 0;
				system("CLS");
				continue;
			}

		} 	while (retakeTest = true);

	}
	else if (input == "2")
	{
		
	}
	else
	{
		printf("Incorect input detected, exiting quiz.");
		_getch();
	}
	return 0;
}

