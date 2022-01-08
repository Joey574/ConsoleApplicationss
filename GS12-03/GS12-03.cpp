/*
Author: Joey Soroka
File Name: GS12-03
Project Name: GS12-03 (right triangle class)
Purpose: To create and test a right triangle class
Pseudocode: 
Maintenance Log:

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

class rightTriangle
{
public:
	rightTriangle();
	rightTriangle(float l, float w);
	rightTriangle(rightTriangle& c);

	void setA(float l);
	void setB(float w);
	float getA();
	float getB();

	float perimeter();
	float area();
	float hypotenuse();

private:
	float a;
	float b;
};

rightTriangle::rightTriangle()
{
	a = 0;
	b = 0;
}

rightTriangle::rightTriangle(float l, float w)
{
	a = l;
	b = w;
}

rightTriangle::rightTriangle(rightTriangle& c)
{
	a = c.a;
	b = c.b;
}

void rightTriangle::setA(float l)
{
	a = l;
}

void rightTriangle::setB(float w)
{
	b = w;
}

float rightTriangle::getA()
{
	return a;
}

float rightTriangle::getB()
{
	return b;
}

float rightTriangle::perimeter()
{
	return a + b + sqrt((a * a) + (b * b));
}

float rightTriangle::area()
{
	return (a * b) / 2;
}

float rightTriangle::hypotenuse()
{
	return sqrt((a * a) + (b * b));
}

int main()
{
	rightTriangle r;
	string input;
	float a;
	float b;

	printf("Enter length of side a: ");
	cin >> a;
	printf("Enter length of side b: ");
	cin >> b;
	r.setA(a);
	r.setB(b);
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
		printf("1. Length of all sides?\n");
		printf("2. Area?\n");
		printf("3. Perimeter?\n");
		printf("4. EXIT\n");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			cout << "Side A: " << r.getA() << endl;
			cout << "Side B: " << r.getB() << endl;
			cout << "Side C (hypotenuse): " << r.hypotenuse() << endl;
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

