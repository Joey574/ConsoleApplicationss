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

struct people
{
	string name = "";
	string phoneNumber = "";
	int age = 0;
	int height = 0;
	int weight = 0;
};

int main()
{
	string temp;
	string input;
	int t = 0;
	int p = 0;
	int search;

	vector <people> person(6);

	ifstream in;
	in.open("GS11-03.txt");

	if (!in.is_open())
	{
		printf("File not found");
	}

	while (getline(in, temp, ','))
	{
		person[p].name = temp;

		getline(in, temp, ',');
		t = stoi(temp);
		person[p].age = t;

		getline(in, temp, ',');
		t = stoi(temp);
		person[p].height = t;

		getline(in, temp, ',');
		t = stoi(temp);
		person[p].weight = t;

		getline(in, temp);
		person[p].phoneNumber = temp;
		p++;
	}
	in.close();

	while (1)
	{
		system("CLS");
		printf("What would you like to search by?\nName? (N)\nAge? (A)\nHeight? (H)\nWeight? (W)\nPhone #? (P)\nSPACE TO EXIT\n");
		input = _getch();
		if (input == " ")
		{
			break;
		}
		cin >> input;
		system("CLS");
		if (input == "n" || input == "N")
		{
			printf("Name: ");
			cin >> input;
			system("CLS");
			for (int p = 0; p < 6; p++)
			{
				if (person[0].name != input && person[1].name != input && person[2].name != input && person[3].name != input && person[4].name != input && person[5].name != input)
				{
					printf("No one matches your search...\n");
					_getch();
					break;
				}
				if (person[p].name == input)
				{
					cout << "Name: " << person[p].name;
					cout << "\tAge: " << person[p].age;
					cout << "\tHeight: " << person[p].height;
					cout << "\tWeight: " << person[p].weight;
					cout << "\tPhone #: " << person[p].phoneNumber << endl;
				}
			}
			_getch();
			continue;
		}
		else if (input == "a" || input == "A")
		{
			printf("Age: ");
			cin >> search;
			system("CLS");
			for (int p = 0; p < 6; p++)
			{
				if (person[0].age != search && person[1].age != search && person[2].age != search && person[3].age != search && person[4].age != search && person[5].age != search)
				{
					printf("No one matches your search...\n");
					_getch();
					break;
				}
				if (person[p].age == search)
				{
					cout << "Name: " << person[p].name;
					cout << "\tAge: " << person[p].age;
					cout << "\tHeight: " << person[p].height;
					cout << "\tWeight: " << person[p].weight;
					cout << "\tPhone #: " << person[p].phoneNumber << endl;
				}
			}
			_getch();
			continue;
		}
		else if (input == "h" || input == "H")
		{
			printf("Height (Inches): ");
			cin >> search;
			system("CLS");
			for (int p = 0; p < 6; p++)
			{
				if (person[0].height != search && person[1].height != search && person[2].height != search && person[3].height != search && person[4].height != search && person[5].height != search)
				{
					printf("No one matches your search...\n");
					_getch();
					break;
				}
				if (person[p].height == search)
				{
					cout << "Name: " << person[p].name;
					cout << "\tAge: " << person[p].age;
					cout << "\tHeight: " << person[p].height;
					cout << "\tWeight: " << person[p].weight;
					cout << "\tPhone #: " << person[p].phoneNumber << endl;
				}
			}
			_getch();
			continue;
		}
		else if (input == "w" || input == "W")
		{
			printf("Weight: ");
			cin >> search;
			system("CLS");
			for (int p = 0; p < 6; p++)
			{
				if (person[0].weight != search && person[1].weight != search && person[2].weight != search && person[3].weight != search && person[4].weight != search && person[5].weight != search)
				{
					printf("No one matches your search...\n");
					_getch();
					break;
				}
				if (person[p].weight == search)
				{
					cout << "Name: " << person[p].name;
					cout << "\tAge: " << person[p].age;
					cout << "\tHeight: " << person[p].height;
					cout << "\tWeight: " << person[p].weight;
					cout << "\tPhone #: " << person[p].phoneNumber << endl;
				}
			}
			_getch();
			continue;
		}
		else if (input == "p" || input == "P")
		{
			printf("Phone # (Ex. 123.456.7890): ");
			cin >> input;
			system("CLS");
			for (int p = 0; p < 6; p++)
			{
				if (person[0].phoneNumber != input && person[1].phoneNumber != input && person[2].phoneNumber != input && person[3].phoneNumber != input && person[4].phoneNumber != input && person[5].phoneNumber != input)
				{
					printf("No one matches your search...\n");
					_getch();
					break;
				}
				if (person[p].phoneNumber == input)
				{
					cout << "Name: " << person[p].name;
					cout << "\tAge: " << person[p].age;
					cout << "\tHeight: " << person[p].height;
					cout << "\tWeight: " << person[p].weight;
					cout << "\tPhone #: " << person[p].phoneNumber << endl;
				}
			}
			_getch();
			continue;
		}
		else
		{
			printf("Not a valid option...\n");
			_getch();
			continue;
		}
	}
	return 0;
}