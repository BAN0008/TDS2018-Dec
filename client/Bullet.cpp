#include "Bullet.h"
#include <SFML/Graphics/CircleShape.hpp>
#include "Game.h"
#include "Wall.h"
#include <math.h>

Bullet::Bullet(int start_x, int start_y, double start_hsp, double start_vsp)
{
	x = start_x;
	y = start_y;
	w = 32;
	h = 32;
	hsp = start_hsp * 12.0f;
	vsp = start_vsp * 12.0f;
	collisionType = POINT;
	class_id = BULLET;
	//collisionType = RECTANGLE;
}

void Bullet::update()
{
	for (unsigned int i = 0; i < ceil(std::fabs(hsp)); i++)
	{
		auto collisions = Game::checkCollisions(this, x + sgn(hsp), y, {WALL});
		for (unsigned int j = 0; j < collisions.size();j++)
		{
			static_cast<Wall *>(collisions[j])->bulletHit(this, x + sgn(hsp), y);
		}
		//x += sgn(hsp);
		if ((i + 1) == ceil(std::fabs(hsp)))
		{
			if (hsp < 0)
			{
				x += hsp - ceil(hsp);
			}
			else
			{
				x += hsp - floor(hsp);
			}
		}
		else
		{
			x += sgn(hsp);
		}
	}
	//x += hsp;

	for (unsigned int i = 0; i < ceil(std::fabs(vsp)); i++)
	{
		auto collisions = Game::checkCollisions(this, x, y + sgn(vsp), {WALL});
		for (unsigned int j = 0; j < collisions.size();j++)
		{
			static_cast<Wall *>(collisions[j])->bulletHit(this, x, y + sgn(vsp));
		}
		//y += sgn(vsp);
		if ((i + 1) == ceil(std::fabs(vsp)))
		{
			if (vsp < 0)
			{
				y += vsp - ceil(vsp);
			}
			else
			{
				y += vsp - floor(vsp);
			}
		}
		else
		{
			y += sgn(vsp);
		}
	}

	if (x < 0 || y < 0 || x + w > 2000 || y + h > 2000)
	{
		delete_me = true;
	}
	//y += vsp;
}

void Bullet::draw(sf::RenderTarget *target)
{
	sf::Vertex line[] =
	{
	    sf::Vertex(sf::Vector2f(x, y), sf::Color(255, 255, 0)),
	    sf::Vertex(sf::Vector2f(x + (hsp * 2), y + (vsp * 2)), sf::Color(255, 255, 0))
	};

	target->draw(line, 2, sf::Lines);
}