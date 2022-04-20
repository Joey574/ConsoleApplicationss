#pragma once

using namespace std;

struct enemyShip
{
	int health, healthMax;
	int minDamge, maxDamage;
	int ID;
	int weapons;
	int type;

	string enemTypeName;

	bool alive = true;
};

struct enemyGround
{
	int health, healthMax;
	int minDamge, maxDamage;
	int ID;
	int weapons;
	int type;

	string enemTypeName;

	bool alive = true;
};

struct cm
{
	vector <enemyShip> es;
	vector <enemyGround> eg;
};

class NPC
{
public:

	//setters
	void setShopID(int s);
	void setCurrent(int c);

	//getters
	int getShopID();
	int getCurrent();

	//accesories
	void shopMenu(struct gm& gm);
	void generalShop(struct gm& gm);
	void shipShop(struct gm& gm);
	void weaponShop(struct gm& gm);
	void miyoshiShop(struct gm& gm);
	void fuelPurch(struct gm& gm);
	void shipPurch(struct gm& gm);

private:

	int current;
	int shopID;
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


private:
	int enemyRace;
	int comType; // 0 = boarding, 1 = ship to ship
	int enemies; // # of enemies

	string enemRaceName;

	cm cm;

	enemyShip enemShip;
	enemyGround enemGround;
};