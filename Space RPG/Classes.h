#pragma once

using namespace std;

class NPC
{
public:

	//setters
	void setShopID(int s);

	//getters
	int getShopID();

	//accesories
	void shopMenu(struct gm& gm);
	void fuelPurch(struct gm& gm);
	void shipPurch(struct gm& gm);

private:

	int shopID;
};