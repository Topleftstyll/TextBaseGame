#include <iostream>
#include "Enemy.h"
#include "Functions.h"

using namespace std;

Enemy::Enemy() : enemyMaxHP(50), enemyMinHP(50){
	hp = rand() % enemyMaxHP + enemyMinHP;
}

void Enemy::takeDmg() {
	int dmg = rand() % 9 + 6;
	hp -= dmg;
	if (hp <= 0) {
		hp = 0;
	}
	else {
		cout << "An Enemy took " << dmg << " damage. It's HP remaining is " << hp;
		cout << endl;
	}
}

int Enemy::getHP() {
	return hp;
}