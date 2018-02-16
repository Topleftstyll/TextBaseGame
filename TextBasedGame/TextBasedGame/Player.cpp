#include <iostream>
#include "Player.h"
#include "Dungeon.h"

using namespace std;

Player::Player() : playerHP(250), PlayerMaxHP(250), PLYR_DMG_MODONE(6), PLYR_DMG_MODTWO(6), gold(0), gameOver(false), loop(true), amtOfPots(0){
	hp = playerHP;
	mp = PlayerMaxHP;
	dmgMod = PLYR_DMG_MODONE;
	dmgModTwo = PLYR_DMG_MODTWO;
}

void Player::takeDamage() {
	int dmg = rand() % dmgMod + dmgModTwo;
	hp -= dmg;
	if (hp <= 0) {
		hp = 0;
	}
	else {
		cout << "You take " << dmg << " points of damage. Your remaining hp is " << hp;
		cout << endl;
	}
}

int Player::getHP() {
	return hp;
}

int Player::getMP() {
	return mp;
}

int Player::getGold() {
	return gold;
}

void Player::increaseHP() {
	if (gold >= 200) {
		mp += 50;
		hp = mp;
		gold -= 200;
		cout << "Your max HP is now " << mp << endl;
		cout << "You now have " << gold << " gold left." << endl;
	} else {
		cout << "You do not have enough gold for that!" << endl;
		cout << "Current Gold: " << gold << endl;
	}
}

void Player::reduceDMG() {
	if (gold >= 250) {
		if (dmgModTwo > 0) {
			dmgModTwo -= 1;
			gold -= 250;
			cout << "You now take 1 less dmg." << endl;
			cout << "You now have " << gold << " gold left." << endl;
		} else {
			cout << "You cant reduce your damage taken anymore!" << endl;
		}
	} else {
		cout << "You do not have enough gold for that!" << endl;
		cout << "Current Gold: " << gold << endl;
	}
}

void Player::giveHPPot() {
	if (gold >= 50) {
		amtOfPots += 1;
		gold -= 50;
		cout << "You just bought 1 Health Potion, you now have " << amtOfPots << " potions." << endl;
		cout << "You now have " << gold << " gold left." << endl;
	} else {
		cout << "You do not have enough gold for that!" << endl;
		cout << "Current Gold: " << gold << endl;
	}
}

void Player::useHPPot() {
	if (amtOfPots > 0) {
		hp += 50;
		if (hp > mp) {
			hp = mp;
		}
		amtOfPots -= 1;
		cout << "Your hp has gone up by 50!" << endl;
		cout << "Your hp is now " << hp << endl;
		cout << "You now have " << amtOfPots << " health potion(s) left." << endl;
	} else {
		cout << "You dont not have any health potions to use. Buy some from the store if you" << endl;
		cout << "would like to use a health potion." << endl;
	}
}

int Player::getAmtPots() {
	return amtOfPots;
}

bool Player::FightOutput(Dungeon dungeon, int fights) {
	cout << "You Chose to fight!\n" << endl;
	list<Enemy*> *enemies = (dungeon.getEnemies());
	do {
		if (getHP() <= 0) {
			cout << GAMEOVER << endl;
			gameOver = true;
			return false;
		}
		
		if (enemies->size() == 0) {
			cout << "You have slain the group of demons!\n" << endl;
			return true;
		} else {
			if (getHP() > 0) {
				takeDamage();
			}
			if (enemies->size() != 0) {
				dungeon.enemiesTakeDmg(*this, fights);
			}
		}
	} while (loop);
	return false;
}

void Player::resetHP() {
	hp = mp;
	gold -= 50;
}

void Player::giveGold(int amount) {
	gold += amount;
}