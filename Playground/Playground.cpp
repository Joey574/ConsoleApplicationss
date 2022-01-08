/*
Author: Joey Soroka
Project Name: Personal Project
File Name: Playground.cpp
Purpose: playground to test random concepts
Pseudocode: 
Maintenance Log:
9/27/21:	Testing how to check string input in if statements
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
using namespace std;

class Circle
{
public:
	Circle();
	Circle(float r);
	Circle(Circle & c);

	void setRadius(float r);
	float getRadius();

	float circumfrence();
	float area();
private:
	float radius;
};

Circle::Circle(float r)
{
	radius = r;
}

Circle::Circle(Circle& c)
{
	radius = c.radius;
}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getRadius()
{
	return radius;
}

float Circle::circumfrence()
{
	return 2.0 * M_PI * radius;
}

float Circle::area()
{
	return M_PI * radius * radius;
}


int main()
{
	Circle test;

	float r;
	cin >> r;
	test.setRadius(r);
	cout << test.getRadius();


}
