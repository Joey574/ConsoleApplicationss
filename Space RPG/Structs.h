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
    bool explored;
	bool encountered = false;
    bool current = false;
    bool objective;
};

struct player
{
	string name;

	int health, healthMax;
	int actionPoints, actionPointsMax;
	int difficulty;

	bool alive = true;
	bool victory = false;
};

struct ship
{
	string name;

	int health, healthMax;
	int shield, shieldMax;
	int shieldRegeneration;
	int actionPoints, actionPointsMax;
	int modules, modulesMax;
	int fuel, fuelMax;
	int shipID = 0; // tells program which line of shipData to look at

	vector <vector<int>> shipData
	{
		{},
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
};