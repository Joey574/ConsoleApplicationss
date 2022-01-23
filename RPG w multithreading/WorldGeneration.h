#pragma once

#include <stdlib.h> // Needed for srand
#include <time.h> // Needed for srand
#include <iostream>

using namespace std;

void world (int diffuculty)
{
    string input;
    string worldSeed = "";
    int seed;


    printf("World Seed: ");
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        seed = (int)input[i];
    }
  
	srand(seed);

    while (worldSeed.length() < 100)
    {
        worldSeed += to_string(rand() % 201 + 50);
    }
    worldSeed.erase(100);
    cout << worldSeed << "\n" << worldSeed.length();

    exit(0);
}