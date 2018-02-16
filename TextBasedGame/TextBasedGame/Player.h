#ifndef PLAYER
#define PLAYER

#include <vector>

#include "Global.h"

using namespace std;

class Dungeon;

class Player {
public:
	Player();

	int playerHP;// player hp
	int PlayerMaxHP; // player max hp
	int gold;
	bool gameOver;
	bool loop;

	const int PLYR_DMG_MODONE; //amount of damage player takes
	const int PLYR_DMG_MODTWO; //amount of damage player takes

	int getHP();
	int getMP();
	int getGold();
	void increaseHP();
	void reduceDMG();
	void giveHPPot();
	void useHPPot();
	int getAmtPots();
	void giveGold(int amount);
	void takeDamage();
	void resetHP();
	bool FightOutput(Dungeon dungeon, int fights);
private:
	int hp;
	int mp;
	int dmgMod;
	int dmgModTwo;
	int amtOfPots;
};

#endif // !PLAYER