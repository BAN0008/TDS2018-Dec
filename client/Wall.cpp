#include "Wall.h"

#include <SFML/Graphics/RectangleShape.hpp>

Wall::Wall(int start_x, int start_y)
{
	x = start_x;
	y = start_y;
	w = 32;
	h = 32;
	collisionType = RECTANGLE;
	class_id = WALL;
}

void Wall::draw(sf::RenderTarget *target)
{
	sf::RectangleShape rect(sf::Vector2f(w, h));
	rect.setPosition(x, y);
	target->draw(rect);
}

void Wall::bulletHit(GameObject *bullet, float x, float y)
{

}