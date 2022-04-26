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
	int supplies = 20;

	bool alive = true;
	bool victory = false;
};

struct ship
{
	string name;

	int health = 10, healthMax;
	int shield = 10, shieldMax;
	int shieldRegeneration;
	int modules = 1, modulesMax;
	int fuel = 25, fuelMax;

	int weapons = 1;
	int maxWeap = 5;
	vector<int> wID{ 0 };

	float evasion;

	int shipID = 0; // tells program which line of shipData to look at

	vector <vector<int>> shipData
	{
		{health, 10, shield, 10, 1, modules, 2, fuel, 25}, // health, healthMax, shield, shieldMax, shieldRegeneration, current module count, max modules, fuel, fuelMax
		{health, 15, shield, 15, 3, modules, 3, fuel, 40},
		{health, 20, shield, 20, 5, modules, 5, fuel, 50},
	};

	bool alive;
};

struct weaponData
{
	int minDamage, maxDamage;
	int type;
	int shots;
	int cost;
	float accuracy;

	string name;
};

struct module
{
	string name;

	int health, healthMax;
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
	vector <module> m;
	vector <weaponData> wD;

	bool inMenu = false;
	bool inGame = false;
	bool inShop = false;
};