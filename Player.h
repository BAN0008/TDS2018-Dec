#ifndef _PLAYER_H
#define _PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(int x, int y);

	void update();
	void draw(sf::RenderTarget *target);
private:
	int x, y, hsp, vsp;
};

#endif //_PLAYER_H