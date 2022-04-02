#pragma once

#include <vector>

using namespace std;

struct systems
{
    int dangerLevel;
    int supplies;
    int x, y;
    int systemID;
	int enemies = 0;
	int addedSup = 0;
    bool explored;
	bool encountered = false;
    bool current = false;
	bool shop = false;
    bool objective;
};

struct player
{
	string name;

	int health = 10, healthMax = 10;
	int actionPoints, actionPointsMax;
	int difficulty;
	int supplies = 10;

	bool alive = true;
	bool victory = false;
};

struct ship
{
	string name;

	int health, healthMax;
	int shield, shieldMax;
	int shieldRegeneration;
	int modules, modulesMax;
	int fuel, fuelMax;
	int shipID = 0; // tells program which line of shipData to look at

	vector <vector<int>> shipData
	{
		{10, 10, 10, 10, 1, 1, 2, 20, 20}, // health, healthMax, shield, shieldMax, shieldRegeneration, current module count, max modules, fuel, fuelMax
		{},
		{},

	};

	bool alive;
};

struct module
{
	string name;

	int health, healthMax;
	int shield, shieldMax;
	int shieldRegeneration;
	int moduleID;

	bool boardable;
	bool powered;
	bool crewed;
};

struct gm
{
	player p;
	ship s;
	struct module m;

	bool inGame = false;
};