#include <iostream>
#include <ctime>

#include "Game.h"

using namespace std;

int main() {
	srand(time(NULL));

	Game* game = new Game;

	while (game->GameBool) {
		game->GameLoop();
	}
	delete game;

	return 0;
}