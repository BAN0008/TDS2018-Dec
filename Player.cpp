#include "Player.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include "Game.h"
#include "Bullet.h"

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
	w = 32;
	h = 32;
	hsp = 0;
	vsp = 0;
	collisionType = CIRCLE;
	//collisionType = RECTANGLE;
}

void Player::update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		double vx = sf::Mouse::getPosition().x - x;
		double vy = sf::Mouse::getPosition().y - y;
		float length = sqrt((vx * vx) + (vy * vy));

		vx /= length;
		vy /= length;

		Game::objects.push_back(new Bullet(x, y, vx, vy));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) hsp += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) hsp += -1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) vsp += 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) vsp += -1;

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
	if (Game::checkCollision(Game::objects[0], Game::objects[0]->x, Game::objects[0]->y, Game::objects[1], Game::objects[1]->x, Game::objects[1]->y))
	{
		hsp = 15;
		vsp = 15;
	}
}

void Player::draw(sf::RenderTarget *target)
{
	sf::CircleShape circle(w / 2);
	circle.setPosition(x - 16, y - 16);
	target->draw(circle);
}