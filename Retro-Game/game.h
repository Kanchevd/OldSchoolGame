/*The whole file is written by Iliyan Mladenov */
#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "character.h"
#include<iomanip>
#include<ctime>
#include <typeinfo>

using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();

	//Operators


	//Functions
	void initialStart();
	void mainMenu();
	void initialize();


	//Accessors
	inline bool getPlaying() const { return this->playing; }

	//Modifiers

private:
	int choice;
	bool playing;

	Player player;
};
#endif