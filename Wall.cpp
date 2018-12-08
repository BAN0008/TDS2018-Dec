#include "Wall.h"

#include <SFML/Graphics/RectangleShape.hpp>

Wall::Wall(int start_x, int start_y)
{
	x = start_x;
	y = start_y;
	collisionType = RECTANGLE;
}

void Wall::draw(sf::RenderTarget *target)
{
	sf::RectangleShape rect(sf::Vector2f(32, 32));
	rect.setPosition(x, y);
	target->draw(rect);
}