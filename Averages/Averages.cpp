/*
Author: Joey Soroka
File Name: Averages.cpp
Project Name: Averages
Purpose: Gets user info about miles traveled, hours traveled, gallons used, and averages it into, miles per gallon, miles per average etc.
Pseudocode:	Gets user info about miles traveled, hours driving, and gallons used and ouputs their mpg and mph
Maintenance Log:
10/4/21:    Started project, haven't done anything yet
10/5/21:	Finished project, added code to get user name and info, then to ouput average mph and mpg to the screen
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <conio.h> 

using namespace std;

int main()
{
	string name;
	int milesTraveled;
	int hoursTraveling;
	float gallonsUsed;
	int mph;
	float mpg;

	printf("Hello, this program will help you figure out your average speed and fuel consumption\nPlease enter your name: ");
	cin >> name;
	system("CLS");

	printf("To start this off I'm going to need some information, ");
	cout << name << " could you first enter how many miles you've traveled? (please round to a whole number)" << endl;
	cin >> milesTraveled;
	system("CLS");

	printf("Wonderful ");
	cout << name << "! Now please enter how long you've been driving? (in hours, and once again, please use whole numbers)" << endl;
	cin >> hoursTraveling;
	system("CLS");

	printf("Ok, ");
	cout << name << "! Now please enter how many gallons of gas you've used (this one doesn't have to be a whole number)" << endl;
	cin >> gallonsUsed;
	system("CLS");

	printf("Ok that's it, press any key to see the information.");
	_getch();
	system("CLS");

	mph = milesTraveled / hoursTraveling;
	mpg = milesTraveled / gallonsUsed;

	cout << "Miles per hour: " << mph << endl;
	printf("Miles per gallon: %.1f\n", mpg);
	printf("Press any key to exit");

	_getch();

	return 0;
}

