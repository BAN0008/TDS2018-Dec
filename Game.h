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

	bool checkCollision(GameObject *object1, int x1, int y1, GameObject *object2, int x2, int y2);
}

#endif //_GAME_H