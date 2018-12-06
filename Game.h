#ifndef _GAME_H
#define _GAME_H

#include "GameObject.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Game
{
	extern std::vector<GameObject *> objects;
	extern sf::RenderWindow window;

	void initialize();
	void loop();
}

#endif //_GAME_H