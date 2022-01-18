#pragma once

using namespace std;

struct player
{
	string name;

	int health, healthMax;
	int actionPoints, actionPointsMax;
	
	bool captain;
	bool alive;
};

struct ship
{
	string name;

	int health, healthMax;
	int shield, shieldMax;
	int shieldRegeneration;
	int actionPoints, actionPointsMax;
	int modules, modulesMax;
	int shipID;

	bool alive;
};

struct module
{
	int health, healthMax;
	int shield, shieldMax;
	int shieldRegeneration;
	int moduleID;

	bool boardable;
	bool powered;
	bool crewed;
};