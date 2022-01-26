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
    bool explored;
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
    int temp = 1;

    cout << (char)218;
    for (int i = 0; i < 108; i++)
    {
        cout << (char)line;
    }
    cout << (char)191;
    cout << endl;

    for (int i = 0; i < 59; i++)
    {
        cout << (char)upLine << endl;
    }

    for (int i = 0; i < 54; i += 6)
    {
        gotoxy(0, i + 6);
        cout << char(195);
        for (int i = 0; i < 108; i++)
        {
            cout << (char)line;
        }
    }

    gotoxy(0, 60);
    cout << char(192);
    for (int i = 0; i < 108; i++)
    {
        cout << (char)line;
    }
   
    gotoxy(109, 1);
    for (int p = 0; p < 10; p++)
    {
        for (int i = 0; i < 5; i++)
        {
            cout << (char)upLine << endl;
            temp += 1;
            gotoxy(109, temp);
        }
        cout << (char)180 << endl;
        temp += 1;
        gotoxy(109, temp);
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

   worldConstructor(s, difficulty, worldSeed);

   for (int y = 0; y < 10; y++)
   {
       for (int x = 0; x < 10; x++)
       {
           s[xy].x = x;
           s[xy].y = y;
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

}

