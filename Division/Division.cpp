/*
Author: Joey Soroka
Project Name: A little division
File Name: Division.cpp
Purpose: A simple calculator
Pseudocode:
Maintenance Log:
9/17/21:    Start of project, setting up code
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
	printf("Division problems: \n\n");
	int a = 6;
	int b = 8;
	int c;
	float d = 3.7;
	float e = 6.2;
	float f;

	c = a / b;
	cout << "a / b = " << c << endl;

	f = d / e;
	cout << "d / e = " << f << endl;




	printf("\n Press any key to see multipulcation problems");
	_getch();
	system("CLS");
	printf("Multiplecation problems:\n\n");

	c = a * b;
	cout << "a * b = " << c << endl;

	f = d * e;
	cout << "d * e = " << f << endl;


	printf("\nPress any key to exit");

	_getch();

	return 0;
}

