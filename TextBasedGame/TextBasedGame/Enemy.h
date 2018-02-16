#ifndef ENEMY
#define ENEMY

class Enemy {
public:
	//constructor will make a random enemy
	Enemy();
	void takeDmg();
	int getHP();
	int enemyMinHP;
	int enemyMaxHP;
protected:
	int hp;
};

#endif // !ENEMY