#pragma once

using namespace std;

struct enemyShip
{
	int health, healthMax;
	int minDamge, maxDamage;
	int ID;
	int weapons;

	bool alive = true;
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



private:
	int comType; // 0 = boarding, 1 = ship to ship
	int enemies; // # of enemies
	enemyShip enemyShip;
};