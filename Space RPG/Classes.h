#pragma once

using namespace std;

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