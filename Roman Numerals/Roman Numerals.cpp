/*
Author: Joey Soroka
File Name: Roman Numerals.cpp
Project Name: Roman Numerals
Purpose: Create a program that can output the roman numerals for numbers 1-3999 inclusive of max and then output it in a string
Pseudocode: First gets user input for what number they want to be outputed as a roman numeral, then checks against a chart of roman numerals and finds highest nunmber, subtracts that number, then moves down, saving the roman numeral to 
			a string every time before finally outputting the roman numeral
Maintenance Log:
11/12/21:	Added all calculations for this project, it will take the number inputed then subtract the highest value it can from it and then move on, continuing this until nothing is left

11/13/21:	Made output a string instead of a bunch of printf
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
	string output = "";
	int num;
	int m = 0;
	int d = 0;
	int c = 0;
	int l = 0;
	int x = 0;
	int v = 0;
	int i = 0;
	int cm = 0;
	int cd = 0;
	int xc = 0;
	int xl = 0;
	int ix = 0;
	int iv = 0;

	while (1)
	{
		system("CLS");
		printf("Enter the number you'd like to convert to a roman numeral (between 1-3999, inclusive)\n");
		cin >> num;
		
		if (num > 3999)
		{
			printf("Read the instructions and try again");
			continue;
		}
		while (num >= 1000)
		{
			output += "M";
			num -= 1000;
		}
		while (num >= 900)
		{
			output += "CM";
			num -= 900;
		}
		while (num >= 500)
		{
			output += "D";
			num -= 500;
		}
		while (num >= 400)
		{
			output += "CD";
			num -= 400;
		}
		while (num >= 100)
		{
			output += "C";
			num -= 100;
		}
		while (num >= 90)
		{
			output += "XC";
			num -= 90;
		}
		while (num >= 50)
		{
			output += "L";
			num -= 50;
		}
		while (num >= 40)
		{
			output += "XL";
			num -= 40;
		}
		while (num >= 10)
		{
			output += "X";
			num -= 10;
		}
		while (num >= 9)
		{
			output += "IX";
			num -= 9;
		}
		while (num >= 5)
		{
			output += "V";
			num -= 5;
		}
		while (num >= 4)
		{
			output += "IV";
			num -= 4;
		}
		while (num >= 1)
		{
			output += "I";
			num -= 1;
		}

		cout << output << "\n";
		_getch();
		system("CLS");
		printf("Press 1 to exit, 2 to repeat\n");
		cin >> input;
		if (input == "1")
		{
			break;
		}
		else if (input == "2")
		{
			continue;
		}

	}
	return 0;
}


