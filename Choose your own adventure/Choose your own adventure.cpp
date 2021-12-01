/*
Author: Joey Soroka
File Name: Choose your own adventure.cpp
Project Name: Choose your own adventure using if and switch
Purpose: A single choose your own adventure game with 9 endings using ifs and switches
Pseudocode: 
Maintenance Log
11/1/21:	Added introduction and collected player name, as well as presenting setting and asking for first player choices

11/5/21:	Added 3 more choices for first path as well as first ending, also added switches, completing the switch part of the assignment

11/18/21:	Added first 3 ending as well as starting text for second option off the start
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
		cout << name << ": You move into position in front of the obstacle course and look ahead, you see several different paths to choose from, on the left you see some tires to run through, however you think you see something moving in the tires in the";
		cout << "middle you see some monky bars over a pit, in the pit there seems to be this mysterious liquid, it looks like somethings in it... On the right you, you see a rope swing, overlooking a massive cavern, it would be quite the fall...\n ";
		_getch();
		system("CLS");
		printf("1. Go left\n2. Go straight\n3. Go right\n");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			cout << name << ": You decide to go left, towards the tires, you hear something moving around inside of them, a lot of somethings\nbut decide not to think about it you run through them going back and forth, however your legs and feet immediately burst with pain, and as you look down you see the tires are filled with SNAKES!\n";
			_getch();
			system("CLS");
			cout << name << ": You keep going, however you're running out of breath, part because of the course, but mostly due to the searing pain in your legs, despite this you manage to make it through the tires and come out on the other end\n";
			_getch();
			system("CLS");
			cout << name << ": You're out of breath, however there's no way to leave the course now as walls surround you, the only way out is to complete the course. Looking around you see 3 more paths to choose from, on the left there's a path that on your left that leads straight to Lieutenant Pace, behind him stand several figures shrouded in shadow, straight ahead you see";
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
				printf("And before you know it you're lunging at him, grabbing him by his throat and strangling him, however he just laughs, mocking you, the dark, figures that stood behind him");
				printf("begin to move surrounding you before they pounce, covering you in darkness, your vision begins to fade, you realize you've made a big mistake, one that will cost you your life, as your heart begins to stop, the last thing you see is a wicked smile on Pace's face\n");
				break;
			case 2:
				cout << name << ": You decide sheltering in the cave would be your best bet, you charge towards the entrance, however as you run you feel the presence of something behind you, you run faster, and dare not look back as you are fileld with terror, you tear through the entrane of the cave,";
				printf(" you soon arrive at a junction and you choose a direction without even thinking, whatever is chasing you is getting closer, filled with adrenaline you run faster and faster... deeper and deeper into the cave, the only though on your mind is escaping what's behind you, this desire drives");
				printf(" you forward, down and down, going through junction afer junction until finally you can go no farther. You look behind you and see... nothing. Then that's when it hits you, you're lost, in pitch black darkness, with no hope of ever getting out...\n");
				break;
			case 3:
				cout << name << ": You decide to head toward the weird pillar off to your right you move closer and closer to the oblisk. Finally when you stand mere feet from it, it starts to glow, pulling you closer and closer, you panic, thinking this could be your end, while you struggle to get away.";
				printf(" However it doesn't matter, no amount of resistance would stop the obilisk, and soon with one final scream, you're sucked in... and next thing you know you're in your room, you start to laugh, thinking it had all been a bad dream, however if you had been listening more carefully you");
				printf(" would've heard a mad cackling coming from... somewhere...\n");
				break;
			default:
				printf("Incorrect input detected, please try again.\n");
				_getch();
				continue;
			}
			_getch();
			system("CLS");

		}
		else if (input == "2")
		{
			cout << name << ": You decide to go over the monkey bars, charching forward you switfly complete the obstacle, a smile on your face as Lieutenant Pace cheers you on\n";
			_getch();
			system("CLS");
			cout << name << "Ahead you see 3 more paths to go down, on the left you see ";
			_getch();
			system("CLS");
			printf("1. Go left\n2. Go straight\n3. Go right\n");
			cin >> input;
			system("CLS");
			input2 = stoi(input);

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


