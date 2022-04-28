#pragma once

#include "Structs.h"

using namespace std;

class NPC
{
public:

	//setters
	void setShopID(vector <int> s);
	void setCurrent(vector <int> c);

	//accesories
	void shopManager(struct gm& gm, vector <systems>& t);
	void generalShop(struct gm& gm);
	void shipShop(struct gm& gm);
	void weaponShop(struct gm& gm);
	void miyoshiShop(struct gm& gm);
	void statDisplay(struct gm& gm);

	//purchases
	void fuelPurch(struct gm& gm);
	void shipPurch(struct gm& gm);
	void sWeapons(struct gm& gm);


private:

	vector <shops> sh;
	shops temp;
};

class combat
{
public:

	// setters
	void setComType(int c);
	void setEnemies(int e);

	// accessories
	void combatManager(struct gm &gm);
	void enemyTypes();
	void gStats();
	void sStats();
	void groundIntro();
	void spaceIntro();
	void sCombat(struct gm& gm);
	void esCombat(struct gm& gm);
	void gCombat(struct gm& gm);

private:
	int enemyRace;
	int comType; // 0 = boarding, 1 = ship to ship
	int enemies; // # of enemies

	string enemRaceName;

	cm cm;

	enemyShip enemShip;
	enemyGround enemGround;
};