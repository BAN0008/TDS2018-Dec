#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <SFML/Graphics/RenderTarget.hpp>

class GameObject
{
public:
	virtual void update();
	virtual void draw(sf::RenderTarget *target);
};

#endif //_GAMEOBJECT_H