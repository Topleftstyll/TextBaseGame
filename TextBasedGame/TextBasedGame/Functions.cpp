#include <sstream>
#include <string>
#include <iostream>
#include <vector>

#include "Functions.h"

using namespace std;

int askForInt(const string& question, int high, int low) {
	int ret;
	do {
		cout << question << endl;
		string str;
		getline(cin, str);
		stringstream ss(str);
		ss >> ret;
		if ((ss) && (ret >= low && ret <= high)) {
			break;
		}
		else {
			cout << "Try Again." << endl;
			continue;
		}
	} while (true);
	return ret;
}

//story
void fightSequence(int monsters, int num) {
	switch (num) {
		case 1: {
			cout << "You walk up the stairs after killing the demons and you notice a door to your left" << endl;
			cout << "You enter the door and find " << monsters << " demons(s)\n" << endl;
			break;
		}
		case 2: {
			cout << "You continue on your journey through the castle, you leave the room and walk down the hall, " << endl;
			cout << "you pass some weird statues. Suddenly " << monsters << " statue(s) come to life!\n" << endl;
			break;
		}
		case 3: {
			cout << "The walls start to shake, you're getting close to the Demon King... You contninue..." << endl;
			cout << "You notice " << monsters << " demon(s) up ahead.\n" << endl;
			break;
		}
		case 4: {
			cout << "You get to then end of the hallway and it opens up into a huge room and WHATTTTT?!?!" << endl;
			cout << "you find the Demon Kings strongest fighter Bombo Man!\n" << endl;
			break;
		}
		case 5: {
			cout << "WOW you actually killed Bombo Man you might actually be able to kill the Demon King!" << endl;
			cout << "You continue on your journey entering a room as soon as you enter the room you're ambushed by" << endl;
			cout << monsters <<" demon(s)!" << endl;
			break;
		}
		case 6: {
			cout << "Weew you must be tired after killing all those demons and Bombo Man, Good work so far!" << endl;
			cout << "You feel tired from all the killing and decide to take alittle break....." << endl;
			cout << "Rumble.... whats that noise? you go to check the shelf. WTF " << monsters << endl;
			cout << "tiny demons jump off the shelf and start to fight you." << endl;
			break;
		}
		case 7: {
			cout << "What the hell were those small demons? never seen or heard of those before." << endl;
			cout << "You continue into the next room and find " << monsters << " waiting for you." << endl;
			break;
		}
		case 8: {
			cout << "The next room you enter is a a big fancy room with 2 massive doors being guarded by " << monsters << endl;
			cout << "demons. The Demon King must be behind those doors!!!!" << endl;
			break;
		}
		case 9: {
			cout << "You open the 2 doors and what...? THERES THE DEMON KING!!" << endl;
			cout << "ARE YOU READY FOR THE FINAL FIGHT? ARE YOU A HERO??" << endl;
			break;
		}
		default: {
			cout << "As soon as you enter the castle you notice " << endl;
			cout << monsters << " demon(s) waiting for you\n" << endl;
			break;
		}
	}
}