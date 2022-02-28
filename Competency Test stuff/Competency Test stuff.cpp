// Competency Test stuff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h> 
#include <vector>
#include <windows.h> // Uses functions named after shapes beware for classes
#include <chrono> // needed for sleep for
#include <thread>
#include <math.h>
#include <sstream> // needed for files
#include <fstream> // needed for files
#include <cwchar>
#include <algorithm> // needed for vector sort

using namespace std;

struct person
{
	string name;
	string phone;

	int age;
	int height;
	int weight;
};

int main()
{
	string input;
	vector <person> p;
	string temp;
	string push;

	int tem = 0;
	int t = 0;
	int x = 0;

	fstream f;

	f.open("names.txt");
	if (!f.is_open())
	{
		printf("File not found");
	}

	printf("Would you like to enter information?(y/n)\n");
	input = _getche();
	if (input == "y")
	{
		while (1)
		{
			system("CLS");
			printf("Enter name: ");
			cin >> input;
			f << input;
			printf("Enter age: ");
			cin >> input;
			f << "," << input;
			printf("Enter height (in): ");
			cin >> input;
			f << "," << input;
			printf("Enter weight: ");
			cin >> input;
			f << "," << input;
			printf("Enter phone #: ");
			cin >> input;
			f << "," << input << endl;
			system("CLS");
			printf("Is that all y/n?\n");
			input = _getche();
			if (input == "y")
			{
				break;
			}
		}
	}

	system("CLS");

	while (getline(f, temp, ','))
	{
		p.push_back(person());
		p[x].name = temp;

		getline(f, temp, ',');
		t = stoi(temp);
		p[x].age = t;

		getline(f, temp, ',');
		t = stoi(temp);
		p[x].height = t;

		getline(f, temp, ',');
		t = stoi(temp);
		p[x].weight = t;

		getline(f, temp);
		p[x].phone = temp;

		x++;
	}

	f.close();

	for (int i = 0; i < p.size(); i++)
	{
		cout << "Name: " << p[i].name << " Age: " << p[i].age << " Height: " << p[i].height << " Weight: " << p[i].weight << " Phone #: " << p[i].phone << endl;
	}
}

