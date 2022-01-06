/*
Author: Joey Soroka
File Name:
Project Name:
Purpose:
Pseudocode:
Maintenance Log:

*/

#pragma once
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h>
#include <math.h>
#include <sstream>
#include <fstream>
using namespace std;

class Ellipse
{
	public:
		Ellipse();
		Ellipse(float r1, float r2);
		Ellipse(Ellipse& c);

		void setRadius1(float r1);
		void setRadius2(float r2);
		float getRadius1();
		float getRadius2();

		float circumference();
		float area();

	private:
		float radius1;
		float radius2;
};

Ellipse::Ellipse()
{
	radius1 = 0;
	radius2 = 0;
}

Ellipse::Ellipse(float r1, float r2)
{
	radius1 = r1;
	radius2 = r2;
}

Ellipse::Ellipse(Ellipse& c)
{
	radius1 = c.radius1;
	radius2 = c.radius2;
}

void Ellipse::setRadius1(float r1)
{
	radius1 = r1;
}

void Ellipse::setRadius2(float r2)
{
	radius2 = r2;
}

float Ellipse::getRadius1()
{
	return radius1;
}

float Ellipse::getRadius2()
{
	return radius2;
}

float Ellipse::circumference()
{
	return 2 * M_PI * sqrt(radius1 * radius2);
}

float Ellipse::area()
{
	return M_PI * radius1* radius2;
}

int main()
{
	Ellipse e;
	float r1;
	float r2;
	string input;


	printf("Enter value of first radius: ");
	cin >> r1;
	printf("Enter value of second radius: ");
	cin >> r2;
	Sleep(500);

	for (int i = 0; i < 5; i++)
	{
		system("CLS");
		printf(".");
		Sleep(250);
		printf(".");
		Sleep(250);
		printf(".");
		Sleep(250);
	}
	system("CLS");

	printf("What would you like to know?\n");
	printf("1. Radii?\n");
	printf("2. Area?\n");
	printf("3. Circumfrence?\n");
	cin >> input;

	if (input == "1")
	{

	}
	else if (input == "2")
	{

	}
	else if (input == "3")
	{

	}
	else
	{

	}

}

