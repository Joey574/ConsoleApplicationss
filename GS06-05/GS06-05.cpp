/*
Author: Joey Soroka
File Name: GS06-05.cpp
Project Name: Problem GS06-05 (word reverser)
Purpose: Create a function that reverses the users input before outputting it again for the user to see
Pseudocode: Gets input, passes it to function, reverses input, returns value to main, outputs it
Maintenance Log:
12/14/21:   Started project, added reverser function
*/


#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

string reverser(string input);

int main()
{
	string input;

	cin >> input;
	string output = reverser(input);

	system("CLS");
	cout << "Reversed String:\n" << output;

	_getch();
	return 0;
}

string reverser(string input)
{
	string output = "";

	for (int i = input.length(); i > -1; i--)
	{
		output += input[i];
	}

	return output;
}