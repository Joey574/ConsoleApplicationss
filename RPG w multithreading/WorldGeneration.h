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

    struct system s[100];


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
            worldSeedInserter.push_back(rand() % (11));
        }

        worldSeed.push_back(worldSeedInserter);
    }

    for (int i = 0; i < worldSeed.size(); i++) {
        for (int j = 0; j < worldSeed[i].size(); j++)
            cout << worldSeed[i][j] << " ";
        cout << endl;

        exit(0);
}