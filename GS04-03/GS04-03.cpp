/*
Author: Joey Soroka
Project Name: GS04-03
Purpose: Create a program to count # of characters in a string as well as some other data
Pseudocode: Asks user for input and to use a tilde tell the code where the input ends, it then counts the # of spaces, newlines, numbers, and tabs,
			before outputting them as well as # of characters.
Maintenance Log:
12/2/21:    Started project
12/6/21:	Fixed issues with code, now works fine
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
	string text;
	int spaces = 0;
	int numbers = 0;
	int tabs = 0;
	int newlines = 0;

	printf("Enter string to count, use tilde to represent end.\n");
	getline(cin, text, '~');
	system("CLS");

	for (int i = 0; i < text.length(); i++)
	{

		if (text[i] == ' ')
		{
			spaces += 1;
		}
		else if (text[i] == '\t')
		{
			tabs += 1;
		}
		else if (text[i] == '\n')
		{
			newlines += 1;
		}
		else if (text[i] >= '0' && text[i] <= '9')
		{
			numbers += 1;
		}

	}
	cout << "Characters: " << text.length() << "\nSpaces: " << spaces << "\nLines: " << newlines << "\nNumbers: " << numbers << "\nTabs: " << tabs << endl;
	return 0;
}