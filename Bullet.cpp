#include "Bullet.h"
#include <SFML/Graphics/CircleShape.hpp>

Bullet::Bullet(int start_x, int start_y, double start_hsp, double start_vsp)
{
	x = start_x;
	y = start_y;
	w = 32;
	h = 32;
	hsp = start_hsp;
	vsp = start_vsp;
	collisionType = CIRCLE;
	class_id = BULLET;
	//collisionType = RECTANGLE;
}

void Bullet::update()
{
	
	x += hsp * 12.0f;
	y += vsp * 12.0f;
}

void Bullet::draw(sf::RenderTarget *target)
{
	sf::Vertex line[] =
	{
	    sf::Vertex(sf::Vector2f(x, y)),
	    sf::Vertex(sf::Vector2f(x + (hsp * 24), y + (vsp * 24)))
	};

	target->draw(line, 2, sf::Lines);
}