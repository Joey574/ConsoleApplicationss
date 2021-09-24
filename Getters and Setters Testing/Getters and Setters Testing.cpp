/*
Author: Joey Soroka
File Name: Getters and Setters Testing.cpp
Purpose: To work on Getters and Setters to be used in the RPG project
Pseudocode:
Maintenance Log:
9/23/21:    Started project, gonna start working on getters and setters
*/

#include <iostream>
#include <conio.h>

using namespace std;

class test
{
	private:
		int test;
	public:
		void testing(int t)
	{
		test = t;
	}
	int getTest()
	{
		return test;

	}
};

void test2()
{
	test myObj;

	myObj.testing();
	cout << myObj.getTest();
}

int main()
{
	test myObj;

	myObj.testing(10);
	cout << myObj.getTest();

	_getch();

	system("CLS");

	test2();


	return 0;
			
}


