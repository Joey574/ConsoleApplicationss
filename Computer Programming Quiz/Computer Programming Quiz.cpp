/*
Author: Joey Soroka
File Name: Computer Programming Quiz
Project Name: Computer Programming Quiz using switch
Purpose: A computer programming quiz that will use switch statements, it will have 3 multiple choice questions at least, and go over I/O, identifiers, operators
		and branching, at least 4 answers for each question, each correct answer will give 1 point, and each incorrect answer will take 0.25 points. No answer
		will not impact score in any direction
Pseudocode:
Maintenance Log
10/11/21:	Collected player name and added choices for first question
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
	float score = 0;
	int input;
	
	printf("Hi! What's your name?\n");
	cin >> name;
	cout << "Welcome " << name << " to this programming quiz, press 1 to start, or 2 to exit." << endl;
	cin >> input;

	switch (input)
	{
	case 1:
		cout << "The first question " << name << " is what are the 2 ways to branch in coding?" << endl;
		cin >> input;
		printf("1. if and else\t2. if and else if\t3. switch and ");

		break;
	case 2:
		break;
	default:
		break;
	}


	return 0;
}

