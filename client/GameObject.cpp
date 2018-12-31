#include "GameObject.h"

void GameObject::update() {}
void GameObject::draw(sf::RenderTarget *target) {}
void GameObject::updateServer(sf::Packet *buffer) {};

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