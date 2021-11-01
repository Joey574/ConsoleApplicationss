/*
Author: Joey Soroka
File Name: Choose your own adventure.cpp
Project Name: Choose your own adventure using if and switch
Purpose: A single choose your own adventure game with 9 endings using ifs and switches
Pseudocode: 
Maintenance Log
11/1/21:	Added introduction and collected player name, as well as presenting setting and asking for first player choices
*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <Windows.h>

using namespace std;

int main()
{
	string input;
	string name;

	printf("Welcome! To this choose your own adventure game! Known as...\n\nTHE TERROR OF CHEIF PACE\n\nPress any key to start\n");
	_getch();
	system("CLS");
	
	printf("Unkown: LOOK ME IN MY EYES WHEN I TALK TO YOU\n");
	printf("You: (look up)\n");
	printf("Unknown: WHAT'S YOUR NAME RECRUIT?\n");
	cin >> name;
	system("CLS");
	printf("Unknown: I'm Cheif Pace, your flight commander, today you'll be running through an obstacle course, of course civil air\npatrol isn't responsible for any \"accidents\" that may occur during this course\n");
	_getch();
	system("CLS");
	printf("Cheif Pace: Now then recruit, let's get started!\n");
	_getch();
	system("CLS");
	cout << name << ": You move into position in front of the obstacle course and look ahead, you see several different paths to choose\nfrom, on the left you see some tires to run through, however you think you see something moving in the tires in the" << endl;
	cout << "middle you see some monky bars over a pit, in the pit there seems to be this mysterious liquid, it looks like somethings\nin it... On the right you, you see a rope swing, overlooking a massive cavern, it would be quite the fall...\n ";
	_getch();
	system("CLS");
	printf("1. Go left\n2. Go straight\n3. Go right\n");
	cin >> input;
	system("CLS");

	if (input == "1")
	{
		cout << name << ": Decides to go left, towards the tires, you hear something moving around inside of them, a lot of somethings\nbut decide not to think about it you run through them going back and forth, however your legs and feet\nimmediately burst with pain, and as you look down you see the tires are filled with SNAKES!\n";
		_getch();
		system("CLS");
		cout << name << ": ";
	}
	else if (input == "2")
	{

	}
	else if (input == "3")
	{

	}
	else
	{

	}

}


