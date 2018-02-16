#include <iostream>

#include "Game.h"
#include "Enemy.h"
#include "Functions.h"
#include "Global.h"

using namespace std;

void Game::GameLoop() {
	int choice = 0;
	int gameChoice = 0;
	int dungeonChoice = 0;
	int storeChoice = 0;
	int fights = 0;
	int yOrN = 0;
	bool inn = false;
	bool GameBool = true;
	bool enemiesAlive = true;
	bool skip = false;

	you = new Player();

	cout << TITLE << endl;

	do {
		choice = askForInt(MAIN_MENU, ABOUT, EXIT);
		switch (choice) {
			case PLAY: {
				cout << INTRO;

				//game loop start
				do {
					gameChoice = askForInt(INN_MENU, CONSUMABLES, EXIT);
					switch (gameChoice) {
						case DUNGEON: {
							cout << DUNGEON_INTRO << endl;
							dungeon = new Dungeon();
							do {
								inn = false;
								skip = false;

								fightSequence(dungeon->numMonsters(), fights);
								dungeonChoice = askForInt(DUNGEON_MENU, CONSUMABLES, EXIT);
								switch (dungeonChoice) {
									case INN: {
										if (you->getGold() < 50) {
											cout << "You dont have enough gold for that yet!\n" << endl;
											skip = true;
										} else {
											inn = true;
											fights = 0;
											skip = true;
											you->resetHP();
											delete dungeon;
											cout << "\nCurrnet Gold: " << you->getGold() << endl;
										}
										break;
									}
									case FIGHT: {
										if (fights == 4) {
											you->giveGold((dungeon->numMonsters()) * 250);
										} else if (fights == 9) {
											you->giveGold((dungeon->numMonsters()) * 10000);
										} else {
											you->giveGold((dungeon->numMonsters()) * 50);
										}

										if (you->FightOutput(*dungeon, fights)) {
											if (fights == 3) {
												dungeon->createBoss(200);
											} else if (fights == 8) {
												dungeon->createBoss(250);
											} else {
												dungeon->createEnemies();
											}
										} else {
											dungeonChoice = 0;
										}
										cout << "\nCurrent Gold: " << you->getGold() << endl;
										break;
									}
									case CONSUMABLES: {
										cout << "You currently have " << you->getAmtPots() << " health potions." << endl;
										if (you->getHP() != you->getMP()) {
											cout << "Would you like to use a health potion?" << endl;
											cout << "	1) yes" << endl;
											cout << "	2) no" << endl;
											cin >> yOrN;
											if (yOrN == 1) {
												you->useHPPot();
											}
										}
										skip = true;
										break;
									}
								}
								if (!skip) {
									fights++;
								}
							} while (dungeonChoice != EXIT && inn == false && fights != 10);

							if (dungeonChoice == EXIT) { //exit game
								choice = 0;
								gameChoice = 0;
								GameBool = false;
							}
							break;
						}
						case STORE: {
							do {
								storeChoice = askForInt(STORE_MENU, BACK, EXIT);
								switch (storeChoice) {
									case BUYHP: {
										you->increaseHP();
										break;
									}
									case REDUCEDMG: {

										you->reduceDMG();
										break;
									}
									case BUYHPPOT: {
										you->giveHPPot();
										break;
									}
									case BACK: {
										storeChoice = 0;
										break;
									}
									default: {
										cout << "Please enter a valid number!" << endl;
										break;
									}
								}
							} while (storeChoice != 0);
							break;
						}
						case CONSUMABLES: {
							cout << "You currently have " << you->getAmtPots() << " health potions." << endl;
							break;
						}
					}
				} while (gameChoice != EXIT);

				if (gameChoice == EXIT) { //exit game
					choice = 0;
					GameBool = false;
				}
				break;
			}
			case TIPS: {
				cout << GAME_TIPS << endl;
				break;
			}
			case ABOUT: {
				cout << ABOUT_TEXT << endl;
				break;
			}
		}
	} while (choice != EXIT);

	if (choice == EXIT) { //TODO: exit game
		GameBool = false;
	}
}