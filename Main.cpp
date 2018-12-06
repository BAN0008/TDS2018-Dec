#include "Game.h"
#include "Wall.h"

int main(int argc, char *argv[])
{
	Game::objects.push_back(new Wall());

	Game::initialize();
	Game::loop();
	
	return 0;
}