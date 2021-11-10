/*
Author: Joey Soroka
File Name: Choose your own adventure.cpp
Project Name: Choose your own adventure using if and switch
Purpose: A single choose your own adventure game with 9 endings using ifs and switches
Pseudocode: 
Maintenance Log
11/1/21:	Added introduction and collected player name, as well as presenting setting and asking for first player choices

11/5/21:	Added 3 more choices for first path as well as first ending, also added switches, completing the switch part of the assignment
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
	int input2;
	string input;
	string name;

	printf("Welcome! To this choose your own adventure game! Known as...\n\nTHE TERROR OF LIEUTENANT PACE\n\nPress any key to start\n");
	_getch();
	system("CLS");
	
	printf("Unkown: LOOK ME IN MY EYES WHEN I TALK TO YOU\n");
	printf("You: (look up)\n");
	printf("Unknown: WHAT'S YOUR NAME RECRUIT?\n");
	cin >> name;
	system("CLS");
	printf("Unknown: I'm Lieutenant Pace, your flight commander, today you'll be running through an obstacle course, of course civil air\npatrol isn't responsible for any \"accidents\" that may occur during this course\n");
	_getch();
	system("CLS");
	printf("Lieutenant Pace: Now then recruit, let's get started!\n");
	_getch();

	while (1)
	{
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
			cout << name << ": You decide to go left, towards the tires, you hear something moving around inside of them, a lot of somethings\nbut decide not to think about it you run through them going back and forth, however your legs and feet\nimmediately burst with pain, and as you look down you see the tires are filled with SNAKES!\n";
			_getch();
			system("CLS");
			cout << name << ": You keep going, however you're running out of breath, part because of the course, but mostly due to the searing pain in your legs, despite this you manage to make it\nthrough the tires and come out on the other end\n";
			_getch();
			system("CLS");
			cout << name << ": You're out of breath, however there's no way to leave the course now as walls surround you, the only way out is to complete the course. Looking around you see 3 more paths to\nchoose from, on the left there's a path that on your left that leads straight to Lieutenant Pace, behind him stand several figures shrouded in shadow, straight ahead you see";
			printf(" a mysterious looking cave, however that's all you can see, and finally, to your right you see an obilisk, the dark tower piercing the skies\n");
			_getch();
			system("CLS");
			printf("1. Go left\n2. Go straight\n3. Go right\n");
			cin >> input;
			system("CLS");
			input2 = stoi(input);

			switch (input2)
			{
			case 1:
				cout << name << ": Hatred fills your body as you charge Pace, by your second step you stop thinking, letting your body take over, charging forward as blood pounds in your eardrums, as your heart pounds against your chest, you keep going, and going, and going, 50 ft, 40 ft... 20 ft... ";
				printf("And before you know it you're lunging at him, grabbing him by his throat and strangling him, however he just laughs, mocking you, the dark, sus figures that stood behind him");
				printf("begin to move surrounding you before they pounce, covering you in darkness, your vision begins to fade, you realize you've made a big mistake, one that will cost you your life, as your heart begins to stop, the last thing you see is a wicked smile on Pace's face\n");
				_getch();
				system("CLS");
				break;
			}
				

		}
		else if (input == "2")
		{

		}
		else if (input == "3")
		{

		}
		else
		{
			printf("please choose a valid input.");
			continue;
		}
	}
}


