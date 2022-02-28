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

class person
{
public:
	person();
	person(string fName, string mName, string lName, string pNumber, int age);
	person(person& c);

	void setFName(string fName);
	void setMName(string mName);
	void setLName(string lName);
	void setPNumber(string pNumber);
	void setAge(int age);
	string getFName();
	string getMName();
	string getLName();
	string getPNumber();
	int getAge();

private:
	string fN;
	string mN;
	string lN;
	string pN;
	int a;
};

person::person()
{
	fN = "";
	mN = "";
	lN = "";
	pN = "";
	a = 0;
}

person::person(string fName, string mName, string lName, string pNumber, int age)
{
	fN = fName;
	mN = mName;
	lN = lName;
	pN = pNumber;
	a = age;
}

person::person(person& c)
{
	fN = c.fN;
	mN = c.mN;
	lN = c.lN;
	pN = c.pN;
	a = c.a;
}

void person::setFName(string fName)
{
	fN = fName;
}

void person::setMName(string mName)
{
	mN = mName;
}

void person::setLName(string lName)
{
	lN = lName;
}

void person::setPNumber(string pNumber)
{
	pN = pNumber;
}

void person::setAge(int age)
{
	a = age;
}

string person::getFName()
{
	return fN;
}

string person::getMName()
{
	return mN;
}

string person::getLName()
{
	return lN;
}

string person::getPNumber()
{
	return pN;
}

int person::getAge()
{
	return a;
}

void changeClass (person &p)
{
	string fN;
	string mN;
	string lN;
	string pN;
	int a;

	fstream dat;

	system("CLS");
	printf("Enter your first name: ");
	cin >> fN;
	printf("Enter you middle name: ");
	cin >> mN;
	printf("Enter your last name: ");
	cin >> lN;
	printf("Enter your phone number (use dashes in between, ex. 123-456-7890): ");
	cin >> pN;
	printf("Enter your age: ");
	cin >> a;
	p.setFName(fN);
	p.setMName(mN);
	p.setLName(lN);
	p.setPNumber(pN);
	p.setAge(a);

	dat.open("info.txt", ios::out | ios::trunc);
	if (!dat.is_open())
	{
		printf("FILE NOT FOUND");
	}

	dat << fN << "," << mN << "," << lN << "," << pN << "," << a;
}

int main()
{
	person p;
	string input;

	ifstream dat;
	dat.open("info.txt");
	if (!dat.is_open())
	{
		printf("FILE NOT FOUND");
	}

	while (getline(dat, input, ','))
	{
		p.setFName(input);
		getline(dat, input, ',');
		p.setMName(input);
		getline(dat, input, ',');
		p.setLName(input);
		getline(dat, input, ',');
		p.setPNumber(input);
		getline(dat, input);
		p.setAge(stoi(input));
	}

	while (1)
	{
		printf("1: Enter new info\n2: Use info from file\nInput: ");
		cin >> input;
		if (input == "1")
		{
			changeClass(p);
			break;
		}
		else if (input == "2")
		{
			break;
		}
		else
		{
			continue;
		}
	}
	
	while (1)
	{
		system("CLS");
		printf("What information would you like to know?\n1: First name\n2: Middle name\n3: Last name\n4: Phone number\n5: Age\n6: Change Info\n7: Exit\nInput: ");
		cin >> input;
		system("CLS");
		if (input == "1")
		{
			cout << "First name: " << p.getFName() << endl;
		}
		else if (input == "2")
		{
			cout << "Middle name: " << p.getMName() << endl;
		}
		else if (input == "3")
		{
			cout << "Last name: " << p.getLName() << endl;
		}
		else if (input == "4")
		{
			cout << "Phone number: " << p.getPNumber() << endl;
		}
		else if (input == "5")
		{
			cout << "Age: " << p.getAge() << endl;
		}
		else if (input == "6")
		{
			changeClass(p);
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