#include "Player.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window.hpp>
#include "Wall.h"

short sgn(int a)
{
	if (a > 0)
	{
		return 1;
	}
	if (a < 0)
	{
		return -1;
	}
	return 0;
}

Player::Player(int start_x, int start_y)
{
	x = start_x;
	y = start_y;
	collisionType = CIRCLE;
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) hsp = 10;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) hsp = -10;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) vsp = 10;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) vsp = -10;

	for (unsigned int i = 0; i < abs(hsp); i++)
	{
		if (true)
		{
			x += sgn(hsp);
		}
	}
	for (unsigned int i = 0; i < abs(vsp); i++)
	{
		if (true)
		{
			y += sgn(vsp);
		}
	}

	if (abs(hsp) > 0) hsp += -1 * sgn(hsp);
	if (abs(vsp) > 0) vsp += -1 * sgn(vsp);
}

void Player::draw(sf::RenderTarget *target)
{
	sf::CircleShape circle(16);
	circle.setPosition(x, y);
	target->draw(circle);
}