#include "Game.h"
#include "Player.h"
#include "Wall.h"

int main(int argc, char *argv[])
{
	Game::objects.push_back(new Player());
	Game::objects.push_back(new Wall());

	Game::initialize();
	Game::loop();
	
	return 0;
}