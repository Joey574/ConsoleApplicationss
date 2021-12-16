/*
Author: Joey Soroka
File Name: GS10-02.cpp
Project Name: GS10-02 (more fortunes)
Purpose: Use a vector to store and output 20 different fortunes
Pseudocode:
Maintenance Log:

*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h>
#include <math.h>
#include <fstream>
using namespace std;

int main()
{
	string input;
	vector <string> fortunes {"You shall become a ginger", "You will have a great day", // 2 fortunes
							  "You will fail your favorite class", "You will complete all the goalsheats by the end of semester", // 2 fortunes
							  "Eric will force you to join CAP", "You will join CAP", "Miyoshi will be your best friend", // 3 fortunes
							  "You will solve world hunger", "You will end the world", "You will start the zombie apocolypse", // 3 fortunes
							  "Brooks will workout with you for once", "Eric will workout with you for once", "Issac will shut up", // 3 fortunes
							  "WOOO 1000 leaf clover!", "You will have 3 classes with miyoshi", "You will ace all your classes", // 3 fortunes
							  "You will get into caltech", "All your dreams will come true", "You will move out next year", // 3 fortunes
							  "You will ive forever!"}; // 1 fortune
	srand(0);
	srand((unsigned)time(NULL));


	while (1)
	{
		system("CLS");
		int i = 0 + rand() % (19 - 0 + 1);
		cout << "Fortune: " << fortunes.at(i) << endl;
		printf("Press 1 to exit, or any other key for a new fortune\n");

		input = _getch();
		if (input == "1")
		{
			break;
		}
		continue;
	}
	return 0;
}

