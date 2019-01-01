#include "GameObject.h"
#include "Game.h"

void GameObject::update() {}
void GameObject::draw(sf::RenderTarget *target) {}
void GameObject::updateServer(sf::Packet *buffer) {};

GameObject::~GameObject()
{
	Game::objects.erase(Game::objects.begin() + index);
	for (unsigned int i = index; i < Game::objects.size();i++)
	{
		Game::objects[i]->index--;
	}
}

float sgn(float a)
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