#ifndef GLOBAL
#define GLOBAL 

#include <string>

//menu stuff
const char MAIN_MENU[] =	"\nPlease choose an option from the following\n"
							"   0) Quit Game\n"
							"   1) Play The Game.\n"
							"   2) Tips.\n"
							"   3) About.\n";

const int EXIT = 0;
const int PLAY = 1;
const int TIPS = 2;
const int ABOUT = 3;

const char INN_MENU[] =		"\nWhat would you like to do?\n"
							"   0) Quit Game\n"
							"   1) Go To Dungeon\n"
							"   2) Store\n"
							"   3) View Consumables\n";

const int DUNGEON = 1;
const int STORE = 2;
const int CONSUMABLES = 3;

const char STORE_MENU[] =	"\nWhat would you like to buy?\n"
							"   0) Quit Game\n"
							"   1) 50 HP Cost: 200 gold\n"
							"   2) +1 Reduced Damage Cost: 250 gold\n"
							"   3) Health Potion Restores 50 HP Cost: 50 gold\n"
							"   4) Back\n";

const int BUYHP = 1;
const int REDUCEDMG = 2;
const int BUYHPPOT = 3;
const int BACK = 4;

const char DUNGEON_MENU[] =	"\nWhat would you like to do?\n"
							"   0) Quit Game\n"
							"   1) Return to the inn. Your HP will be restored for 50 gold.\n"
							"   2) Fight\n"
							"   3) View Consumables\n";

const int INN = 1;
const int FIGHT = 2;

// game text
const char INTRO[] =		"\nYou are the hero of this story, your job is to slay the evil \n"
							"Demon King. The Demon King has a special demon thats almost \n"
							"as strong as him named Bombo Man. You'll have to defeat him and \n"
							"all the mini demons before you can fight the strongest demon.... \n"
							"the demon king. You can enter the dungeons as many times as you want\n"
							"and leave whenever you want. Enter the dungeons kill some things, get\n"
							"gold then return to the inn to upgrage your HP and reduce damage taken.\n"
							"Remember that if you die its all over though! Good-luck!! \n\n";

const char TITLE[] =		"Are You A Hero?";

const char GAME_TIPS[] =	"\n\n-----------TIPS-----------\n"
							"This game is a better safe than sorry type of game.\n"
							"You'll want to kill a few guys get some gold then go back and upgrade.\n"
							"then rinse and repeat until you can clear more and more and become super \n"
							"strong! thats about the only tip youll need.\n";

const char GAMEOVER[] =		"GAME OVER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
							"Seems You died a horrible horrible death! better luck next time!\n\n"
							"press enter to continue...\n";

const char WIN_TEXT[] =		"\nCONGRADULATIONS!!, you have finally killed the Demon King and saved the\n"
							"world. You are now known as the strongest person alive and are rewarded \n"
							"by your king and get to marry the princess (cliche right?).\n\n"
							"Press Enter if you would like to play again! Thanks for playing. \n\n";

const char ABOUT_TEXT[] =	"This game was made by Josh Brackett as a TriOS Student. \n"
							"All content in this game is original content and is not\n"
							"assosiated with anyone or thing in outside of the game itself\n";

const char DUNGEON_INTRO[] ="\nYou have just entered the dungeon. Find the Demon King and kill him!\n";

#endif // !GLOBAL