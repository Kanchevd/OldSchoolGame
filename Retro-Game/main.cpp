/*The whole file is written by Iliyan Mladenov */
#include "game.h"
#include "character.h"
#include "player.h"
#include "libsqlite.hpp"


int main()
{
    Game game;
    game.initialStart();
	game.initialize();
    
	while (game.getPlaying())
	{
		game.mainMenu();
	}

}