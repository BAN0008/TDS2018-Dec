#include "Player.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include "Game.h"
#include "Bullet.h"
#include "Wall.h"
#include "SFML/Audio.hpp"

Player::Player(int start_x, int start_y)
{
	x = start_x;
	y = start_y;
	w = 32;
	h = 32;
	hsp = 0;
	vsp = 0;
	collisionType = RECTANGLE;
	class_id = PLAYER;
}

void Player::update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		double vx = sf::Mouse::getPosition().x - (x + (w / 2));
		double vy = sf::Mouse::getPosition().y - (y + (h / 2));
		double length = sqrt((vx * vx) + (vy * vy));

		vx /= length;
		vy /= length;

		Game::objects.push_back(new Bullet(x + (w / 2), y + (h / 2), vx, vy));
		Game::objects[Game::objects.size() - 1]->index = Game::objects.size() - 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) hsp += 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) hsp += -2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) vsp += 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) vsp += -2;

	for (unsigned int i = 0; i < fabs(hsp); i++)
	{
		if (Game::checkCollisions(this, x + sgn(hsp), y, {WALL}).size() == 0)
		{
			x += sgn(hsp);
		}
		else
		{
			hsp = 0;
			break;
		}
	}
	for (unsigned int i = 0; i < fabs(vsp); i++)
	{
		if (Game::checkCollisions(this, x, y + sgn(vsp), {WALL}).size() == 0)
		{
			y += sgn(vsp);
		}
		else
		{
			vsp = 0;
			break;
		}
	}

	if (abs(hsp) > 0) hsp += -1 * sgn(hsp);
	if (abs(vsp) > 0) vsp += -1 * sgn(vsp);
}

void Player::draw(sf::RenderTarget *target)
{
	sf::CircleShape circle(w / 2);
	circle.setPosition(x, y);
	target->draw(circle);
}

void Player::updateServer(sf::Packet *buffer)
{
	buffer->operator<<(x);
	buffer->operator<<(y);
	buffer->operator<<(hsp);
	buffer->operator<<(vsp);
}