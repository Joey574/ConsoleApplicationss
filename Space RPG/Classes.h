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
	void miyoshiShop(struct gm& gm, vector<systems>& t);
	void statDisplay(struct gm& gm);

	//purchases
	void fuelPurch(struct gm& gm);
	void shipPurch(struct gm& gm);
	void modules(struct gm& gm);
	void sWeapons(struct gm& gm);
	void gWeapons(struct gm& gm);
	void repair(struct gm& gm);
	void genesisLoc(vector<systems>& t, struct gm& gm);
	void miyoshiBucks(struct gm& gm);
	void solidWorks(struct gm& gm);

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

	// getters
	bool getEscape();

	// accessories
	void combatManager(struct gm &gm, vector <systems>&s);
	void enemyTypes(struct gm& gm, vector <systems>& t);
	void gStats();
	void sStats();
	void groundIntro();
	void spaceIntro();
	void cSD(int enemyAttack);
	void mS(struct gm& gm);
	void sCombat(struct gm& gm, vector <systems>& s);
	void sACombat(struct gm& gm, int enemyAttack, vector <systems>& s);
	void esCombat(struct gm& gm);
	void gCombat(struct gm& gm);

private:
	int enemyRace;
	int comType; // 0 = boarding, 1 = ship to ship
	int enemies; // # of enemies
	bool cloaked = false;
	bool escape = false;

	string enemRaceName;

	cm cm;

	enemyShip enemShip;
	enemyGround enemGround;
};