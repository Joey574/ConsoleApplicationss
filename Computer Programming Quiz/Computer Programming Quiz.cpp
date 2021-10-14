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
10/12/21:	Added 5 questions, and 3 functions for when the player is correct, incorrect, or enters an incorrect input
10/14/21:	Added 3 more questions, hoping for 10 total, added letter and percentage grading at end of quiz
*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>

using namespace std;

void correct(float &score, string name)
{
	system("CLS");
	cout << "Correct answer " << name << ", + 1 point. Press any key to continue" << endl;
	score += 1;
	_getch();
	system("CLS");
}
void incorrect(float &score, string name)
{
	system("CLS");
	cout << "Incorrect answer " << name << ", - 0.25 points. Press any key to continue" << endl;
	score -= 0.25;
	_getch();
	system("CLS");
}
void _default(string name)
{
	system("CLS");
	cout << "No valid input detected " << name << " no point awarded or subtracted. Press any key to continue" << endl;
	_getch();
	system("CLS");
}


int main()
{
	string name;
	float score = 0;
	int input;
	
	printf("Hi! What's your name?\n");
	cin >> name;
	system("CLS");
	cout << "Welcome " << name << " to this programming quiz, press 1 to start, or 2 to exit." << endl;
	cin >> input;
	system("CLS");

	switch (input)
	{
	case 1:
		cout << "The first question " << name << " is what are the 2 ways to branch in coding?" << endl;
		printf("1. if and else\t2. if and else if\t3. switch and void\t4. if and switch\n");
		cin >> input;

		switch (input)
		{
		case 1:
			incorrect(score, name);
			break;
		case 2:
			incorrect(score, name);
			break;
		case 3:
			incorrect(score, name);
			break;
		case 4:
			correct(score, name);
			break;
		default:
			_default(name);
			break;
		}
		
		cout << "The second question " << name << " is what is an identifier?" << endl;
		printf("1. A type of variable\t2. A name assigned to variables, type, functions, and labels\t3. Another word used for branching\t4. Value assigned to a variable\n");
		cin >> input;

		switch (input)
		{
		case 1:
			incorrect(score, name);
			break;
		case 2:
			correct(score, name);
			break;
		case 3:
			incorrect(score, name);
			break;
		case 4:
			incorrect(score, name);
			break;
		default:
			_default(name);
			break;
		}

		cout << "The third question " << name << " is what is an operator?" << endl;
		printf("1. A type of void\t2. A symbol to tell the computer to do a mathematical or similar operation\t3. A way to go to the top of an if statement\t4. Similar to PEMDAS is it the computers order of operations\n");
		cin >> input;

		switch (input)
		{
		case 1:
			incorrect(score, name);
			break;
		case 2:
			correct(score, name);
			break;
		case 3:
			incorrect(score, name);
			break;
		case 4:
			incorrect(score, name);
			break;
		default:
			_default(name);
			break;
		}

		cout << "The fourth question " << name << " is what does I/O mean?" << endl;
		printf("1. It means information/operations\t2. It means input/operations\t3. It means information/output\t4. It means input/output\n");
		cin >> input;

		switch (input)
		{
		case 1:
			incorrect(score, name);
			break;
		case 2:
			incorrect(score, name);
			break;
		case 3:
			incorrect(score, name);
			break;
		case 4:
			correct(score, name);
			break;
		default:
			_default(name);
			break;
		}

		cout << "The fifth question " << name << " is what are the 2 ways to pass a variable to a function?" << endl;
		printf("1. Pass by reference and pass by value\t2. Pass by value and pass by operation\t3. Pass by reference and pass by order\t4. Pass by reference and pass by argument\n");
		cin >> input;
		
		switch (input)
		{
		case 1:
			correct(score, name);
			break;
		case 2:
			incorrect(score, name);
			break;
		case 3:
			incorrect(score, name);
			break;
		case 4:
			incorrect(score, name);
			break;
		default:
			_default(name);
			break;
		}

		cout << "The sixth question " << name << " is what is multithreading?" << endl;
		printf("1. A way to use subprocesses to process several lines of code at the same time\n2. Similar to a header file, multithreading includes new declarations for your code\n3. A way to assign different threads with different lines of code, allowing your computer to run two or more programs at the same time\n4. Allows each thread on a cpu to handle more lines of code at the same time\n");
		cin >> input;

		switch (input)
		{
		case 1:
			incorrect(score, name);
			break;
		case 2:
			incorrect(score, name);
			break;
		case 3:
			correct(score, name);
			break;
		case 4:
			incorrect(score, name);
			break;
		default:
			_default(name);
			break;
		}

		cout << "The seventh question " << name << " is how many cores are in the Ryzen 5 3600X?" << endl;
		printf("1. 4\t2. 6\t3.8\t4.10\n");
		cin >> input;

		switch (input)
		{
		case 1:
			incorrect(score, name);
			break;
		case 2:
			correct(score, name);
			break;
		case 3:
			incorrect(score, name);
			break;
		case 4:
			incorrect(score, name);
			break;
		default:
			_default(name);
			break;
		}

		cout << "The eighth question " << name << "is how many threads are in the Ryzen 5 3600X?" << endl;
		printf("1. 12\t2. 8\t3. 6\t4. 16\n");
		cin >> input;

		switch (input)
		{
		case 1:
			correct(score, name);
			break;
		case 2:
			incorrect(score, name);
			break;
		case 3:
			incorrect(score, name);
			break;
		case 4:
			incorrect(score, name);
			break;
		default:
			_default(name);
			break;
		}

		cout << "The ningth question " << name << " is what was the 3000 Nvidia GPU series architecture called?" << endl;
		printf("1. Love life\t2. RTX\t3. Ampere\t4. Turing\n");
		cin >> input;

		switch (input)
		{
		case 1:
			incorrect(score, name);
			break;
		case 2:
			incorrect(score, name);
			break;
		case 3:
			correct(score, name);
			break;
		case 4:
			incorrect(score, name);
			break;
		default:
			_default(name);
			break;
		}

		cout << "The tenth and final question " << name << " is what header file is needed for _getch()?" << endl;
		printf("1. Conio.h\t2. Stdio.h\t3. iostream\t4. vector\n");
		cin >> input;

		switch (input)
		{
		case 1:
			correct(score, name);
			break;
		case 2:
			incorrect(score, name);
			break;
		case 3:
			incorrect(score, name);
			break;
		case 4:
			incorrect(score, name);
			break;
		default:
			_default(name);
			break;
		}
		printf("Congrats on completing this quiz! Press any key to see your score.\n");
		_getch();
		
		system("CLS");
		cout << "You scored " << score << " out of 10 possible points" << endl;
		score = (score / 10) * 100;
		printf("Percentage: %.0f", score);
		printf("%%\n");
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

		break;
	default:
		break;
	}
	return 0;
}

