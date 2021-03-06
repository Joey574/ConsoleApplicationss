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
#include <windows.h> // Uses functions named after shapes beware for classes
#include <chrono> // needed for sleep for
#include <thread>
#include <math.h>
#include <sstream> // needed for files
#include <fstream> // needed for files
#include <cwchar>
#include <algorithm> // needed for vector sort

using namespace std;
using namespace std::this_thread; // needed for sleep for
using namespace std::chrono; // needed for sleep for

class animal
{
public:
	animal();
	animal(string name, int age, int level, string d);
	animal(animal& c);

	void setName(string name);
	void setAge(int age);
	void setLevel(int level);
	void setDialouge(string dialouge);
	string getName();
	string getDialouge();
	int getAge();
	int getLevel();

	int health();
	int speed();

private:
	string n;
	string d;
	int a;
	int l;
};

animal::animal()
{
	n = "";
	d = "";
	a = 0;
	l = 0;
}

animal::animal(string name, int age, int level, string dialouge)
{
	n = name;
	d = dialouge;
	a = age;
	l = level;
}

animal::animal(animal& c)
{
	n = c.n;
	d = c.d;
	a = c.a;
	l = c.l;
}

void animal::setName(string name)
{
	n = name;
}

void animal::setDialouge(string dialouge)
{
	d = dialouge;
}

void animal::setAge(int age)
{
	a = age;
}

void animal::setLevel(int level)
{
	l = level;
}

string animal::getName()
{
	return n;
}

string animal::getDialouge()
{
	return d;
}

int animal::getAge()
{
	return a;
}

int animal::getLevel()
{
	return l;
}

int animal::health()
{
	if (100 + (l * 5) > 200)
	{
		return 200;
	}
	else
	{
		return 100 + (l * 5);
	}
}

int animal::speed()
{
	if (100 - (a * 2) < 20)
	{
		return 20;
	}
	else
	{
		return 100 - (a * 2);
	}	
}

int main()
{
	animal a;
	string input;
	string name;
	string dialouge;
	int age;
	int level;

	printf("Enter dialouge: ");
	getline(cin, dialouge, '\n');
	printf("Enter name of animal: ");
	cin >> name;
	printf("Enter age of animal: ");
	cin >> age;
	printf("Enter level of animal: ");
	cin >> level;
	a.setName(name);
	a.setDialouge(dialouge);
	a.setAge(age);
	a.setLevel(level);

	while (1)
	{
		system("CLS");
		printf("What would you like to know?\n1: Name\n2: Dialouge\n3: Age\n4: Level\n5: Health\n6: Speed\n7: Exit\nInput: ");
		cin >> input;
		system("CLS");
		if (input == "1")
		{
			cout << "Name: " << a.getName() << endl;
		}
		else if (input == "2")
		{
			cout << "Dialouge: " << a.getDialouge() << endl;
		}
		else if (input == "3")
		{
			cout << "Age: " << a.getAge() << endl;
		}
		else if (input == "4")
		{
			cout << "Level: " << a.getLevel() << endl;
		}
		else if (input == "5")
		{
			cout << "Health: " << a.health() << endl;
		}
		else if (input == "6")
		{
			cout << "Speed: " << a.speed() << endl;
		}
		else if (input == "7")
		{
			break;
		}
		else
		{
			printf("Invalid input");
		}
		_getch();
	}

	return 0;
}