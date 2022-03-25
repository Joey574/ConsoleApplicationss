#pragma once

using namespace std;

class person
{
public:

	person();

	void setN(int name);
	void setH(int health);
	void setHM(int healthMax);
	void setAxP(int actionPoints);
	void setAxM(int actionPointsMax);
	void setD(int difficulty);

private:

	string name;

	int health, healthMax;
	int actionPoints, actionPointsMax;
	int difficulty;

	bool alive = true;
};
