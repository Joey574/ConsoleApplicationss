/*
Author: Joey Soroka
File Name:
Project Name:
Purpose:
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
#include <windows.h>
#include <math.h>
#include <sstream>
#include <fstream>
using namespace std;

struct info
{
	int a;
	float b;
	string c;
	char d;
};

int main()
{
	string temp;

	vector <info> vec;

	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");

	if (!in.is_open())
	{
		printf("File not found");
	}

	while (getline(in, temp, ','))
	{
		info i;

		i.a = stoi(temp);

		out << i.a << "\t";
		cout << i.a << "\t";

		getline(in, temp, ',');
		i.b = stof(temp);

		out << i.b << "\t";
		cout << i.b << "\t";

		getline(in, temp, ',');
		i.c = temp;

		out << i.c << "\t";
		cout << i.c << "\t";
		
		getline(in, temp);
		i.d = temp[0];

		out << i.d << "\n";
		cout << i.d << "\n";

		vec.push_back(i);
	}

	in.close();
	out.close();


	return 0;
}