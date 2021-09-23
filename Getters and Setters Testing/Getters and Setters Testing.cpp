/*
Author: Joey Soroka
File Name: Getters and Setters Testing.cpp
Purpose: To work on Getters and Setters to be used in the RPG project
Pseudocode:
Maintenance Log:
9/23/21:    Started project, gonna start working on getters and setters
*/

#include <iostream>

using namespace std;

class test
{
	private:
		int test;
	public:
		void testing()
	{
		test = 1;
	}
	int getTest()
	{
		return test;

	}
};

int main()
{
	test myObj;

	myObj.testing();
	cout << myObj.getTest();

	return 0;
			
}


