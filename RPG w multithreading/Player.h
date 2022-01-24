#pragma once

using namespace std;

struct player
{
	string name;

	int health, healthMax;
	int actionPoints, actionPointsMax;
	int difficulty;
	
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
	int fuel, fuelMax;
	int shipID = 0; // tells program which line of shipData to look at

	vector <vector<int>> shipData { { 20, 50, 5, 8, 5, 50 }, // healthMax, shieldMax, shieldRegeneration, actionPointsMax, modulesMax, fuelMax
									{ 25, 55, 8, 10, 8, 70 }, // each new row is a different ship, each row is a different shipID from 0-3
									{ 30, 60, 10, 10, 10, 80},
									{ 35, 65, 10, 12, 10, 100} };

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