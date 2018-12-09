#ifndef _PLAYER_H
#define _PLAYER_H

#define PLAYER 0

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(int x, int y);

	void update();
	void draw(sf::RenderTarget *target);
	int hsp, vsp;
};

#endif //_PLAYER_H