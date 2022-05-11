#pragma once

#include <vector>

using namespace std;

struct systems
{
	vector <int> enemyTypes;
	int enemies = 0;
	int allies = 0;
	int enemyRace;
	int combatT;
	bool esc = false;

    int dangerLevel;
    int supplies;
    int x, y;
    int systemID;
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
	int difficulty;
	int supplies = 20;
	int miyoshiB = 0;
	int score = 0;

	bool alive = true;
	bool victory = false;
};

struct crew
{
	vector <bool> weapon;

	int health = 10, healthMax = 10;

	bool alive = true;
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
		{health, 20, shield, 10, 1, modules, 2, fuel, 25, 90}, // health, healthMax, shield, shieldMax, shieldRegeneration, current module count, max modules, fuel, fuelMax, evasion
		{health, 30, shield, 15, 3, modules, 3, fuel, 40, 80},
		{health, 40, shield, 20, 5, modules, 4, fuel, 50, 70},
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

struct items
{
	int mBC = 10; // miyoshi buck cost
	int gLC = 20; // genesis location cost
	int fC = 1; // fuel cost
	int sUC = 20; // ship upgrade cost
	int rC = 2; // repair cost
	int rMC = 15; // repair module cost
	int cMC = 15; // combat module cost
	int sMC = 15; // shield module cost
	int clMC = 20; // cloak module cost
	int clMCo = 3; // cloak module cooldown
	int sWT = 10; // solid works tip
	int eJD = 5; // emergency jump damage
	int ejC = 3; // emergency jump fuel cost
	int ejCh = 30; // emergency jump chance
	int shopNum; // # of shops (user defined)
};

struct gm
{
	player p;
	ship s;
	items i;
	vector <weaponData> wD;
	vector <crew> cr;
	vector <bool> mod;

	string seed;

	bool inMenu = false;
	bool inGame = false;
	bool inShop = false;
};

struct enemyShip
{
	int health, healthMax;
	int minDamge, maxDamage;
	int ID;
	int weapons;
	int type;

	float accuracy;
	float evasion;

	string enemTypeName;
};

struct enemyGround
{
	int health, healthMax;
	int minDamge, maxDamage;
	int ID;
	int weapons;
	int type;
	int evasion;
	int accuracy;

	string enemTypeName;

	bool alive = true;
};

struct cm
{
	vector <enemyShip> es;
	vector <enemyGround> eg;
};

struct shops
{
	int shopID;
	int current;
};