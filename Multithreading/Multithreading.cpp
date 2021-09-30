

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>


void gotoxy(int x, int y);
DWORD WINAPI InputThread(LPVOID data);

bool quitting = false;

int main()
{
	srand((unsigned)time(NULL));
	HANDLE threadHandle;
	DWORD threadID;

	threadHandle = CreateThread(NULL, 0, InputThread, (LPVOID)1, 0, &threadID);

	do
	{
		int r = rand() % 24, c = rand() % (80 - 27);
		gotoxy(c, r);
		printf("Where is the line? (%2i, % 2i)", r, c);
		Sleep(500);
		gotoxy(c, r);
		printf("                            ");
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
		gotoxy(0, 24);
		printf("PRESS the ESC key to exit: ");
		gotoxy(27, 24);
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