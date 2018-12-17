#include "Game.h"
#include "Player.h"
#include "Wall.h"

int main(int argc, char *argv[])
{
	Game::objects.push_back(new Player(64, 64));
	Game::objects.push_back(new Wall(128, 128));

	Game::initialize();
	Game::loop();
	
	return 0;
}