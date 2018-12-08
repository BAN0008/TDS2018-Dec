#ifndef _WALL_H
#define _WALL_H

#include "GameObject.h"

class Wall : public GameObject
{
public:
	Wall(int x, int y);
	void draw(sf::RenderTarget *target);
private:
	int x, y;
};

#endif //_WALL_H