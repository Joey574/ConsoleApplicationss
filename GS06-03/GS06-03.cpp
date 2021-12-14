/*
Author: Joey Soroka
File Name: GS06-03.cpp
Project Name: GS06-03 (fortune cookie)
Purpose:
Pseudocode:
Maintenance Log:
12/10/21:   Started project
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

string fortune(num);

int main()
{
    int num;
    while(1)
    {
        
    printf("Enter a number from 1-10");
    cin >> num;
    
    string fort = fortune(num);
    cout << fort;
    }
}

string fortune(num)
{
    string fort;

    if (num = 1)
    {
        fort = "You will be rich one day";
    }
    else if (num = 2)
    {
        fort = "You will become an astrnaut!";
    }
    else if (num = 3)
    {
        fort = "You will die a slow and painful death!";
    }
    else if (num = 4)
    {
        fort = "Uh oh... this isn't good, let's just move on shall we?";
    }
    else if (num = 5)
    {
        fort = "Elon musk is gonna pass his company on to you";
    }
    else if (num = 6)
    {
        fort = "You're gonna trip and fall in a volcano";
    }
    else if (num = 7)
    {
        fort = "You're gonna live through a real life sharknado!";
    }
    else if (num = 8)
    {
        fort = "You're gonna be responsible for the end of the world!";
    }
    else if (num = 9)
    {
        fort = "You will be adbucted by aliens!";
    }
    else if (num = 10)
    {
        fort = "You will abduct aliens!";
    }

    return fort;
}
