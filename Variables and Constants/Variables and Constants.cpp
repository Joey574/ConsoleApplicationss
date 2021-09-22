/*
Author: Joey Soroka
Project Name: Variables and Constants
File Name: Variables and Constants.cpp
Purpose: To declare and initialie 13 variables and 5 constants
Pseudocode:
Maintenance Log:
9/14/21:	I added 21 lines of code containing variables and constants, as well as working on outputting them to the screen, 
			so far i have 6 outputting sucessfully.
9/16/21:	Got all the variables and constants to print to screen however struggling with the last 3
9/20/21:	Got the bools to output, still need to do the scientific constants, should be easy
9/22/21:	Added the constants, code is now fully complete
*/
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;


int main()
{

	const float c = 3.0e8; // done
	const float g = 9.8; // done
	const float plancksConstant = 6.62607004; // done
	const float avogardo = 6.0221409e23; // done
	const float goldenRatio = 1.61803398875; // done
	const bool single = true; //done


	bool understandsThisClass = false; //done

	int age = 14; //done
	int placesIHAveLived = 4; //done
	int luckyNumber = 4; //done
	int yearsIvePlayedFootball = 8; //done

	string struggle; //
	struggle = "I don't understand anything in this class what is even going on"; //done
	string color; //
	color = "My favorite color is blue"; //done
	string food; //
	food = "I had cereal for breakfast today"; //done

	char mathGrade = 'A'; //done
	char _11 = 'x'; //done
	char _24 = 'z'; //done

	double netWorth = 0; //done
	double taxes = 10; //done
	double height = 5.11; //done


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

	printf("My Networth:%f\n", netWorth);
	printf("Washington State tax percentage:%f\n", taxes);
	printf("I am %f", height);
	printf(" feet tall\n");

	cout << std::boolalpha;
	cout << "Single: " << single << endl;
	cout << "Understands this class: " << understandsThisClass << endl;

	cout << "Speed of light: " << c << endl;
	cout << "Gravity: " << g << endl;
	cout << "Planck's Constant: " << plancksConstant << endl;
	cout << "Avogardo's Number: " << avogardo << endl;
	cout << "Golden Ratio: " << goldenRatio << endl;

	_getch();
		
	return 0;

}
