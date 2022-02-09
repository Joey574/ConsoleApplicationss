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

int main()
{
	string temp;
	string line;
	string output = "";
	vector <string> info;

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
		info.push_back(temp);
		out << temp << "\t";
	}

	return 0;
}