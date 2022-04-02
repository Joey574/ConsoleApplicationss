#pragma once

using namespace std;

class NPC
{
public:

	NPC();


	//setters
	void setShopID(int s);

	//getters
	int getShopID();

	//accesories
	void shopMenu(struct gm& gm);

private:

	int shopID;


};