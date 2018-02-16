#include <iostream>

#include "Dungeon.h"
#include "Global.h"

using namespace std;

Dungeon::Dungeon(void) {
	createEnemies();
}

Dungeon::~Dungeon() {
	delete enemies;
}

void Dungeon::createEnemies() {
	enemies = new list<Enemy*>();

	int numToSpawn = rand() % 3 + 1;
	for (int i = 0; i < numToSpawn; ++i) {
		enemies->push_back(new Enemy());
	}
}

void Dungeon::createBoss(int health) {
	enemies = new list<Enemy*>();

	enemies->push_back(new Boss(health));
}

int Dungeon::numMonsters() const {
	return enemies->size();
}

list<Enemy*>* Dungeon::getEnemies() const {
	return enemies;
}

void Dungeon::enemiesTakeDmg(Player you, int fights) {
	bool isBombo = false;
	bool isKing = false;
	list<Enemy*>::iterator it;
	for (it = enemies->begin(); it != enemies->end(); ++it) {
		(*it)->takeDmg();
		if (fights == 9) {
			isKing = true;
		}
		if (fights == 4) {
			isBombo = true;
		}
		if ((*it)->getHP() == 0 && isKing) {
			enemies->erase(it);
			cout << "You recieve 10000 gold!\n" << endl;
			cout << endl;
			cout << WIN_TEXT << endl;
		} else if ((*it)->getHP() == 0 && isBombo) {
			enemies->erase(it);
			cout << "You killed Bombo Man!\n" << endl;
			cout << "You recieve 200 gold!\n" << endl;
		} else if ((*it)->getHP() == 0) {
			enemies->erase(it);
			cout << "You killed an enemy!\n" << endl;
			cout << "You recieve 50 gold!\n" << endl;
		}
		break;
	}
}