#ifndef GAME
#define GAME

#include "Player.h"
#include "Dungeon.h"

class Game {
public:
	void GameLoop();
	bool GameBool;
	bool gameBool();
	bool inn;
	bool skip;
	int choice;
	int gameChoice;
	int dungeonChoice;
	int storeChoice;
	int fights;
	int yOrN;
	Player* you;
	Dungeon* dungeon;
};

#endif // !GAME