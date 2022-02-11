/*
Author: Joey Soroka
File Name: Multithreading.cpp
Project Name: Personal
Purpose: To help me understand and use multithreading, the most complicated subject I've attempted to tackle so far
Pseudocode: 
Maintenance Log:
9/30/21:	So far just copied code from C++ with miyoshi book, currently trying to understand what it does and how to manipulate it
*/

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <thread>

using namespace std;

void gotoxy(int x, int y);
DWORD WINAPI InputThread(LPVOID data);

bool quitting = false;
int r;
int c;


int main()
{
	srand((unsigned)time(NULL));
	HANDLE threadHandle;
	DWORD threadID;

	threadHandle = CreateThread(NULL, 0, InputThread, (LPVOID)1, 0, &threadID);

	do
	{
		r = rand() % 24, c = rand() % (80 - 27);
		gotoxy(c, r);
		printf("Where is the line? (%2i, % 2i)", r, c);
		Sleep(500);
		gotoxy(c, r);
		printf("                            ");
		gotoxy(0, 24);
		printf("PRESS the ESC key to exit:");		

		} 
	while (!quitting);
	
	_getch();
	 
	return 0;
}



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

DWORD WINAPI InputThread(LPVOID data)
{
	const char ESC = 27;
	char input;
	while (1)
	{
		
		input = _getche();
		//flushall();
		if (input == ESC)
		{
			quitting = true;
			break;
		}
	}
	return 0;
}

