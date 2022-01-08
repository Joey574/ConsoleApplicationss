/*
Author: Joey Soroka
File Name: GS11-04+-5.cpp
Project Name: Problem GS11-04&05 (encrypt and decrypt files)
Purpose: To encrypt and decrypt text files based on a value given by the user
Pseudocode: Asks user for encryption value and uses that to change ascii value of characters to encrypt and then decrpyt a file
Maintenance Log:
12/20/21:	Started and completed project
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
	char c;
	char outs;
	int encryptionValue;

	ifstream original;
	fstream encrypted;
	original.open("original.txt");
	encrypted.open("encrypted.txt");
	if (!original.is_open())
	{
		printf("File not found");
	}

	printf("Encyrption Value: ");
	cin >> encryptionValue;

	while (getline(original, temp))
	{
		for (int i = 0; i < temp.length(); i++)
		{
			c = temp[i];
			if ((int)c + encryptionValue > 127)
			{
				for (int i = 0; (int)c + i < 127; i++, encryptionValue--)
				{
					outs = 32 + encryptionValue;
				}
			}
			else
			{
				outs = (int)c + encryptionValue;
			}	
			encrypted << outs;
		}
		encrypted << "\n";
	}
	original.close();
	encrypted.close();

	ofstream output;
	encrypted.open("encrypted.txt");
	output.open("output.txt");
	if (!encrypted.is_open())
	{
		printf("File not found");
	}

	while (getline(encrypted, temp))
	{
		for (int i = 0; i < temp.length(); i++)
		{
			c = temp[i];
			if ((int)c + encryptionValue > 127)
			{
				for (int i = 0; (int)c - i < 32; i++, encryptionValue++)
				{
					outs = 127 - encryptionValue;
				}
			}
			else
			{
				outs = (int)c - encryptionValue;
			}
			output << outs;
		}
		output << "\n";
	}
	return 0;
}

