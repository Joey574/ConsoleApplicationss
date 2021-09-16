/*
Author: Joey Soroka
Project Name: 
File Name: Variables and Constants
Purpose: To declare and initialie 13 variables and 5 constants
Pseudocode:
Maintenance Log:
9/14/21:	I added 21 lines of code containing variables and constants, as well as working on outputting them to the screen, 
			so far i have 6 outputting sucessfully.
9/16/21:	Got all the variables and constants to print to screen however struggling with the last 3
*/
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;


int main()
{
	const float c = 3.0e8;
	const float g = 9.8;
	const bool single = true;
	const float plancksConstant = 6.62607004;
	const float avogardo = 6.0221409e23;
	const float goldenRatio = 1.61803398875;
	bool understandsThisClass = false;
	int age = 14;
	int placesIHAveLived = 4;
	int luckyNumber = 4;
	int yearsIvePlayedFootball = 8;
	string struggle;
	struggle = "I don't understand anything in this class what is even going on";
	string color;
	color = "My favorite color is blue";
	string food;
	food = "I had cereal for breakfast today";
	char mathGrade = 'A';
	char _11 = 'x';
	char _24 = 'z';
	double netWorth = 0;
	double taxes = 10;
	double height = 5.11;


	cout << "Math Grade: " << mathGrade << endl;
	cout << "11 = "<< _11 << endl;
	cout << "24 = "<< _24 << endl;
	printf("Age:%i\n", age);
	printf("Places I have lived:%i\n", placesIHAveLived);
	printf("Lucky number:%i\n", luckyNumber);
	printf("I've played football for %i", yearsIvePlayedFootball);
	printf(" years\n");
	cout << "" << struggle << endl;
	cout << "" << color << endl;
	cout << "" << food << endl;
	printf("Math Grade:%c\n", mathGrade);
	printf("11:%c\n", _11);
	printf("24:%c\n", _24);
	printf("My Networth:%fl\n", netWorth);
	printf("Washington State tax percentage:%fl\n ", taxes);
	printf("I am %fl", height);
	printf(" feet tall");
		
	return 0;


}
