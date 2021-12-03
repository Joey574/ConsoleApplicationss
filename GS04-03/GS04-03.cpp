/*
Author: Joey Soroka
Project Name: GS04-03
Purpose: Create a program to count # of characters in a string
Pseudocode: 
Maintenance Log:
12/2/21:    Started project
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
	string input;
	int spaces = 0;
	int newline = 0;
	int numbers = 0;
	int tabs = 0;

	printf("Enter string to count, use tilde to represent end.\n");
	getline(cin, input, '~');
	cout << 

	for (int i = 0; i < input.length(); i++)
	{

		if (input[i] == ' ')
		{
			spaces+= 1;
		}
		else if (input[i] == '\t')
		{
			tabs+= 1;
		}
		else if (input[i] == '\n')
		{
			newline+= 1;
		}
		else if (input[i] >= '0' && input[i] <= '9')
		{
			numbers+= 1;
		}
	}
	printf("%i spaces, %i numbers, %i new lines, %i tabs.\n", spaces, numbers, newline, tabs);
	return 0;
}