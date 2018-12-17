#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#define NONE 0
#define POINT 1
#define RECTANGLE 2
#define CIRCLE 3

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Network/Packet.hpp>

class GameObject
{
public:
	double x, y;
	int w, h;
	int collisionType = NONE;
	unsigned int class_id;
	virtual void update();
	virtual void draw(sf::RenderTarget *target);
	virtual void updateServer(sf::Packet *buffer);
};

#endif //_GAMEOBJECT_H