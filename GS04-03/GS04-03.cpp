/*
Author: Joey Soroka
Project Name: GS04-03
Purpose: Create a program to count # of characters in a string
Pseudocode: 
Maintenance Log:
12/2/21:    Started project
*/

#include <stdio.h>
#include <iostream>
#include <string> // Needed for string
#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <conio.h>
#include <vector>
#include <windows.h>
using namespace std;

int main()
{
    string input;

    printf("Enter string to be counted\n");
    cin >> input;
    cout << input.size() << endl;
}
