#ifndef DUNGEONS
#define DUNGEONS

#include <vector>
#include <list>

#include "Enemy.h"
#include "Player.h"
#include "Boss.h"

class Dungeon {
public:
	Dungeon(void);
	~Dungeon();
	int numMonsters() const;
	list<Enemy*>* getEnemies() const;
	void createEnemies();
	void createBoss(int health);
	void enemiesTakeDmg(Player you, int fights);
private:
	 list<Enemy*>* enemies;
};

#endif // !DUNGEONS