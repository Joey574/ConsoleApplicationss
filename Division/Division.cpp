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
	int a = 6;
	int b = 8;
	float d = 3.7;
	float e = 6.2;
	
	printf("Addition problems:\n\n");

	cout << "a + b = " << a + b << endl;

	cout << "d + e = " << d + e << endl;

	printf("\nPress any key to see subtraction problems\n");
	_getch();
	system("CLS");
	printf("Subtraction problems:\n\n");

	cout << "a - b = " << a - b << endl;

	cout << "d - e = " << d - e << endl;

	printf("\nPress any key to see multipulcation problems\n");
	_getch();
	system("CLS");
	printf("Multiplecation problems:\n\n");

	cout << "a * b = " << a * b << endl;
		
	cout << "d * e = " << d * e << endl;

	printf("\nPress any key to see division problems\n");
	_getch();
	system("CLS");
	printf("Division probles:\n\n");

	cout << "a / b = " << a / b << endl;

	cout << "d / e = " << d / e << endl;

	cout << "a / d = " << a / d << endl;
	
	cout << "e / a = " << e / a << endl;

	cout << "a / d = " << a / (int)d << endl;

	cout << "e / b = " << e / (float)b << endl;

	printf("\nPress any key to exit\n");

	_getch();

	system("CLS");

	return 0;
}

