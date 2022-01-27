#pragma once

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
#include <iterator>

using namespace std;



struct system
{
    int dangerLevel;
    int supplies;
    int x, y;
    int systemID;
    bool explored;
    bool objective;
};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void worldConstructor(struct system s[100], int difficulty, vector<int> worldSeed)
{
    int line = 196;
    int upLine = 179;
    int horSep = 10;
    int vertSep = 6;
    int temp = 1;
    int horDist = 100;
    int vertDist = 61;
    int topLeftCorner = 218;
    int topRightCorner = 191;
    int botLeftCorner = 192;
    int botRightCorner = 217;
    int rightT = 195;
    int leftT = 180;
    int bottomT = 193;
    int upT = 194;
    int junction = 197;
    int xy = 0;
    
    for (int x = 0; x < 10; x++)
    {
        cout << (char)topLeftCorner;
        for (int i = 1; i < horDist; i++)
        {
            cout << (char)line;
        }
        cout << (char)topRightCorner << endl;
        for (int p = 1; p < vertSep; p++)
        {
            for (int i = 0; i <= horDist; i += horSep)
            {
                gotoxy(i, p + (x * 6));
                cout << (char)upLine;
            }
        }
        cout << endl;
    }
    cout << (char)botLeftCorner;
    for (int p = 6; p < 60; p += 6)
    {
        gotoxy(0, p);
        cout << (char)rightT;
        for (int i = 10; i < horDist; i += 10)
        {
            gotoxy(i, p);
            cout << (char)junction;
        }
        gotoxy(100, p);
        cout << (char)leftT;
    }
    gotoxy(1, 60);
    for (int p = 0; p < 10; p++)
    {
        for (int i = 0; i < 9; i++)
        {
            cout << (char)line;
        }
        cout << (char)bottomT;
    }
    gotoxy(100, 60);
    cout << (char)botRightCorner;
    for (int i = 10; i < horDist; i += 10)
    {
        gotoxy(i, 0);
        cout << (char)upT;
    }
    gotoxy(100, 0);
    cout << (char)topRightCorner;
    gotoxy(0, 61);

    for (int p = 1; p < vertDist; p += 6)
    {
        for (int i = 1; i <= horDist; i += 10)
        {
            gotoxy(i, p);
            cout << "Danger: " << s[xy].dangerLevel;
            gotoxy(i, p + 1);
            cout << "(" << s[xy].x << ", " << s[xy].y << ")";
            gotoxy(i, p + 2);
            cout << "Supplies:";
            gotoxy(i, p + 3);
            cout << s[xy].supplies;
            xy++;
        }
    }
    


    _getch();
    exit(0);
}

void world (int difficulty)
{
    string input;
    vector <int> worldSeed;
  
    int seed;
    int xy = 0;

   struct system s[100];

   for (int y = 0; y < 10; y++)
   {
       for (int x = 0; x < 10; x++)
       {
           s[xy].x = x;
           s[xy].y = y;
           s[xy].systemID = xy;
           xy++;
       }
   }

    /*  //System x, y error checking
  for (int i = 0; i < 100; i++)
   {
       cout << i << ":\t" <<s[i].x << ", " << s[i].y << endl;
   }
    */ 

    system("CLS");
    printf("World Seed: ");
    cin >> input;
    system("CLS");

    for (int i = 0; i < input.length(); i++)
    {
        seed = (int)input[i];
    }
  
	srand(seed);

    for (int p = 0; p < 100; p++)
    {
        worldSeed.push_back(rand() % (10));
    }


   /*   //World Seed vector error checking
    for (int i = 0; i < worldSeed.size(); i++) 
    {
       cout << worldSeed[i] << "\n";
    }
    cout << "Vector size: " << worldSeed.size();
    */
    
    xy = 0;

    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            if (worldSeed[xy] <= 2) // safe / no danger
            {
                s[xy].dangerLevel = 0;
                s[xy].supplies = rand() % (5);
            }
            else if (worldSeed[xy] <= 5 && worldSeed[xy] > 2) // low danger
            {
                s[xy].dangerLevel = 1;
                s[xy].supplies = rand() % (8);
            }
            else if (worldSeed[xy] <= 8 && worldSeed[xy] > 5) // medium danger
            {
                s[xy].dangerLevel = 2;
                s[xy].supplies = rand() % (10);
            }
            else if (worldSeed[xy] = 9) // lots of danger
            {
                s[xy].dangerLevel = 3;
                s[xy].supplies = rand() % (15);
            }
            xy++;
        }
    }

    s[0].dangerLevel = 0; // setting adjacent tiles to safe to avoid death on spawn
    s[1].dangerLevel = 0;
    s[10].dangerLevel = 0;
    s[11].dangerLevel = 0;

   /*  //system danger level and supplies error checking
    for (int i = 0; i < 100; i++)
    {
        cout << i << ":\t" << s[i].x << ", " << s[i].y << " Danger Level: " << s[i].dangerLevel << " Supplies: " << s[i].supplies << endl;
    }
  */

    s[50 + rand() % 99].objective = true;

    worldConstructor(s, difficulty, worldSeed);
}
