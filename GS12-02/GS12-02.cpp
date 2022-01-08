/*
Author: Joey Soroka
File Name: GS12-02
Project Name: GS12-02 (rectangle class)
Purpose: To create and test a rectangle class
Pseudocode: Asks user for length and width of rectangle and then asks what the user would like to know, allowing them to find out area, perimeter, 
			and the length and width of the rectangle again
Maintenance Log:
1/7/21:	Started and finished project
*/

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
//#include <windows.h> // Uses functions named after shapes beware for classes
#include <chrono>
#include <thread>
#include <math.h>
#include <sstream>
#include <fstream>
using namespace std;
using namespace std::this_thread; // needed for sleep for
using namespace std::chrono; // needed for sleep for

class Rectangle
{
public:
	Rectangle();
	Rectangle(float l, float w);
	Rectangle(Rectangle& c);

	void setlength(float l);
	void setwidth(float w);
	float getlength();
	float getwidth();

	float perimeter();
	float area();

private:
	float length;
	float width;
};

Rectangle::Rectangle()
{
	length = 0;
	width = 0;
}

Rectangle::Rectangle(float l, float w)
{
	length = l;
	width = w;
}

Rectangle::Rectangle(Rectangle& c)
{
	length = c.length;
	width = c.width;
}

void Rectangle::setlength(float l)
{
	length = l;
}

void Rectangle::setwidth(float w)
{
	width = w;
}

float Rectangle::getlength()
{
	return length;
}

float Rectangle::getwidth()
{
	return width;
}

float Rectangle::perimeter()
{
	return 2 * (length + width);
}

float Rectangle::area()
{
	return length * width;
}

int main()
{
	Rectangle r;
	string input;
	float length;
	float width;

	printf("Enter value of length: ");
	cin >> length;
	printf("Enter value of width: ");
	cin >> width;
	r.setlength(length);
	r.setwidth(width);
	sleep_for(500000000ns);

	for (int i = 0; i < 5; i++)
	{
		system("CLS");
		printf(".");
		sleep_for(250000000ns);
		printf(".");
		sleep_for(250000000ns);
		printf(".");
		sleep_for(250000000ns);
	}


	while (1)
	{
		system("CLS");
		printf("What would you like to know?\n");
		printf("1. Length and Width?\n");
		printf("2. Area?\n");
		printf("3. Perimeter?\n");
		printf("4. EXIT\n");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			cout << "Length: " << r.getlength() << endl;
			cout << "Width: " << r.getwidth() << endl;
			_getch();
		}
		else if (input == "2")
		{
			cout << "Area: " << r.area() << endl;
			_getch();
		}
		else if (input == "3")
		{
			cout << "Perimeter: " << r.perimeter() << endl;
			_getch();
		}
		else if (input == "4")
		{
			break;
		}
		else
		{
			printf("Incorrect input");
			printf(".");
			sleep_for(250000000ns);
			printf(".");
			sleep_for(250000000ns);
			printf(".");
			sleep_for(500000000ns);
			system("CLS");
			continue;
		}
	}

	return 0;
}

