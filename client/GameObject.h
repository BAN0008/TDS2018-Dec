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
	bool delete_me = false;
	double x, y;
	int w, h;
	int collisionType = NONE;
	int index;
	unsigned int class_id;
	virtual void update();
	virtual void draw(sf::RenderTarget *target);
	virtual void updateServer(sf::Packet *buffer);

	~GameObject();
};

float sgn(float a);

#endif //_GAMEOBJECT_H