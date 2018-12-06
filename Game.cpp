#include "GameObject.h"
#include "Game.h"
#include <vector>
#include <SFML/Window.hpp>

std::vector<GameObject *> Game::objects;
sf::RenderWindow Game::window;

void Game::initialize()
{
	window.create(sf::VideoMode(640, 480), "TDS2018-Dec");
	window.setVerticalSyncEnabled(true);
}

void Game::loop()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		window.clear();
		for (unsigned i = 0; i < objects.size(); i++)
		{
			objects[i]->update();
			objects[i]->draw(&window);
		}
		window.display();
	}
}