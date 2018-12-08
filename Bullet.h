#ifndef _BULLET_H
#define _BULLET_H

#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(int x, int y, double hsp, double vsp);
	void update();
	void draw(sf::RenderTarget *target);
	double hsp, vsp;
};

#endif //_BULLET_H