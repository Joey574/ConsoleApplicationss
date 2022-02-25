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
	string input;
	string temp;
	string encrypted;
	string output;

	int encryptionValue;

	printf("Please enter name of encryption file: ");
	cin >> encrypted;
	encrypted += ".txt";
	
	printf("Pleae enter name of decryption file: ");
	cin >> output;
	output += ".txt";

	while (1)
	{
		system("CLS");
		printf("1: Encrypt(make sure to change text before encrypting)\n2: Decrypt (make sure to encrypt file before decrypting)\n3: Change Text\n4: Exit\nInput: ");
		cin >> input;
		system("CLS");

		if (input == "1")
		{
			ifstream ori;
			ofstream enc;

			ori.open("original.txt");
			enc.open(encrypted, ios::out | ios::trunc);

			if (!ori.is_open())
			{
				printf("File not found");
			}

			printf("Please enter an encryption value: ");
			cin >> encryptionValue;

			while (encryptionValue > 94 || encryptionValue < -94)
			{
				if (encryptionValue > 94)
				{
					encryptionValue -= 94;

				}
				else if (encryptionValue < 94)
				{
					encryptionValue += 94;

				}
			}

			while (getline(ori, temp))
			{
				for (int i = 0; i < temp.length(); i++)
				{
					unsigned char c = temp[i];

					if (int(c) + encryptionValue > 127)
					{
						c = (int)c + encryptionValue - 95;
					}
					else
					{
						c = (int)c + encryptionValue;
					}
					enc << c;
					cout << c;
				}
				enc << "\n";
				cout << "\n";
			}

			ori.close();
			enc.close();

			_getch();
		}
		else if (input == "2")
		{
			ifstream encin;
			ofstream out;

			encin.open(encrypted);

			out.open(output, ios::out | ios::trunc);

			while (getline(encin, temp))
			{
				for (int i = 0; i < temp.length(); i++)
				{
					unsigned char c = temp[i];

					if (int(c) - encryptionValue < 32)
					{
						c = (int)c - encryptionValue + 95;
					}
					else
					{
						c = (int)c - encryptionValue;
					}
					out << c;
					cout << c;
				}
				out << "\n";
				cout << "\n";
			}

			out.close();
			encin.close();

			_getch();
		}
		else if (input == "3")
		{
			ofstream ori;
			ori.open("original.txt", ios::out | ios::trunc);

			printf("Please enter text to encrypt/decrypt: ");
			cin.ignore();
			getline(cin, input);

			ori << input;
		}
		else if (input == "4")
		{
			break;
		}
		else
		{
		printf("Invalid input...");
		_getch();
		}
	}
	
	return 0;
}