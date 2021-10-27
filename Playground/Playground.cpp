/*
Author: Joey Soroka
Project Name: Personal Project
File Name: Playground.cpp
Purpose: playground to test random concepts
Pseudocode: 
Maintenance Log:
9/27/21:	Testing how to check string input in if statements
*/

#include <iostream>
#include <conio.h>
 #include <windows.h>
#include <string>
#include <vector>

using namespace std;

struct Testing
{
	int test_1;

	int test_2;

	int test_3;
};

void structureTesting(struct Testing &t)
{

	t.test_1 = 1;

	t.test_2 = 2;

	t.test_3 = 3;
}

void escapeTesting()
{
	
	_getch();

	char input = _getch();

	if (input ==  VK_ESCAPE)
	{
		printf("escape key detected\n");

		_getch();

		if (input == VK_ESCAPE)
		{
			printf("somethings up");
		}
		else
		{
			printf("WOOHOO IT WORKS");
		}
			

	}


}

void vectorTesting()
{
	vector <int> testing;

	testing.assign(1, 10);

}

int main()
{
	struct Testing t;

	t.test_1 = 0;

	t.test_2 = 0;

	t.test_3 = 0;

	structureTesting(t);

	cout << "Test_1: " << t.test_1 << endl;
	cout << "Test_2: " << t.test_2 << endl;
	cout << "Test_3: " << t.test_3 << endl;

	return 0;
}
