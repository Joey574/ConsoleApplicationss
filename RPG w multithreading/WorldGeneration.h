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
};

void world (int diffuculty)
{
    string input;
    vector<vector <int> > worldSeed;
    vector <int> worldSeedInserter;
    int seed;
    int xy = 0;

   struct system s[100];

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

    printf("World Seed: ");
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        seed = (int)input[i];
    }
  
	srand(seed);

    for (int p = 0; p < 10; p++)
    {
        worldSeedInserter.clear();
        for (int i = 0; i < 10; i++)
        {
            worldSeedInserter.push_back(rand() % (10));
        }
        worldSeed.push_back(worldSeedInserter);
    }

    /*  World Seed vector error checking
    for (int i = 0; i < worldSeed.size(); i++) 
    {
        for (int j = 0; j < worldSeed[i].size(); j++)
            cout << worldSeed[i][j] << " ";
        cout << endl;
    }
    */
    
    xy = 0;

    for (int y = 0; y < 10; y++) // BROKEN
    {
        for (int x = 0; x < 10; x++)
        {
            if (worldSeed[x][y] <= 2) // safe / no danger
            {
                s[xy].dangerLevel = 0;
                s[xy].supplies = rand() % (5);
            }
            else if (worldSeed[x][y] <= 5 && worldSeed[x][y] > 2) // low danger
            {
                s[xy].dangerLevel = 1;
                s[xy].supplies = rand() % (8);
            }
            else if (worldSeed[x][y] <= 8 && worldSeed[x][y] > 5) // medium danger
            {
                s[xy].dangerLevel = 2;
                s[xy].supplies = rand() % (10);
            }
            else if (worldSeed[x][y] = 9) // lots of danger
            {
                s[xy].dangerLevel = 3;
                s[xy].supplies = rand() % (15);
            }
            xy++;
        }

        for (int i = 0; i < 100; i++)
        {
            cout << i << ":\t" << s[i].x << ", " << s[i].y << " Danger Level: " << s[i].dangerLevel << " Supplies: " << s[i].supplies << endl;
        }
    }

    _getch();
    exit(0);
}