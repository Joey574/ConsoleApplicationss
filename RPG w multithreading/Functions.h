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

struct systems
{
    int dangerLevel;
    int supplies;
    int x, y;
    int systemID;
    bool explored;
    bool current = false;
    bool objective;
};

void gotoxy(int x, int y) // credit: Miyoshi
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void invalidInput()
{
	printf("Invalid input");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(200);
	printf(".");
	Sleep(500);
}

void exploredUpdater(vector<systems>& s)
{
    for (int xy = 0; xy < 100; xy++)
    {
        if (s[xy].current = true)
        {
            s[xy].explored = true;
            s[xy + 1].explored = true;
            s[xy + 10].explored = true;
            s[xy + 11].explored = true;
            break;
        }
    }

    for (int xy = 0; xy < 100; xy++)
    {
        if (s[xy].explored == true)
        {
            gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 1);
            cout << "Danger: " << s[xy].dangerLevel;
            gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 2);
            cout << "Supplies:";
            gotoxy((s[xy].x * 10) + 5, (s[xy].y * 6) + 3);
            cout << s[xy].supplies;
        }
        else
        {
            gotoxy((s[xy].x * 10) + 1, (s[xy].y * 6) + 3);
            printf("No Data");
        }
    }
}