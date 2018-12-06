#include "Wall.h"

#include <SFML/Graphics/RectangleShape.hpp>

void Wall::draw(sf::RenderTarget *target)
{
	sf::RectangleShape rect(sf::Vector2f(32, 32));
	rect.setPosition(128, 128);
	target->draw(rect);
}