/*
Author: Joey Soroka
File Name: Switch Testing.cpp
Project Name: Personal
Purpose: To test out switches
Pseudocode: detects player input, if number from 1-3 will output the same number, if not says "Not 1-3"
Maintenance Log:
9/30/21:    Completed the program, testing out how switches work
        
*/

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
    int input;

    cin >> input;

    _getch();
        
    switch (input)
    {
    case 1:

        printf("1");

        _getch();

        system("CLS");

        break;

    case 2:

        printf("2");

        _getch();

        system("CLS");

        break;

    case 3:

        printf("3");

        _getch();

        system("CLS");

        break;

    default:

        printf("Not 1-3");

        _getch();

        system("CLS");

        break;

    }

    return 0;

}


