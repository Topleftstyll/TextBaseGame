#include <iostream>
#include "BossEnemy.h"

using namespace std;

BossEnemy::BossEnemy() : enemyMaxHP(100), enemyMinHP (100){
	hp = rand() % enemyMaxHP + enemyMinHP;
}

void BossEnemy::takedmg() {
	int dmg = rand() % 9 + 6;
	hp -= dmg;
	if (hp <= 0) {
		hp = 0;
	} else {
		cout << "Bombo Man took " << dmg << " damage. His HP remaining is " << hp;
		cout << endl;
	}
}

int BossEnemy::getHP() {
	return hp;
}