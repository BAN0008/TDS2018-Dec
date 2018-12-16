#include "GameObject.h"
#include "Game.h"
#include <vector>
#include <math.h>
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
		//Respond to winow events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		//Update objects and screen
		window.clear();
		for (unsigned int i = 0; i < objects.size(); i++)
		{
			objects[i]->update();
			objects[i]->draw(&window);
		}
		window.display();

		//Add object data to network buffer
		for (unsigned int i = 0; i < objects.size(); i++)
		{
			objects[i]->network();
		}
	}
}

bool Game::checkCollision(GameObject *object1, int x1, int y1, GameObject *object2, int x2, int y2)
{
	//Make sure that object1 has the lower collisionType
	if (object1->collisionType > object2->collisionType)
	{
		GameObject *objectTemp = object1;
		object1 = object2;
		object2 = objectTemp;
		int xTemp = x1, yTemp = y1;
		x1 = x2;
		y1 = y2;
		x2 = xTemp;
		y2 = yTemp;
	}


	//Point v Point
	if (object1->collisionType == POINT && object2->collisionType == POINT)
	{
		if (x1 == x2 && y1 == y2)
		{
			return true;
		}
	}
	//Point v Rectangle
	if (object1->collisionType == POINT && object2->collisionType == RECTANGLE)
	{
		if (x1 > x2 && x1 < x2 + object2->w && y1 > y2 && y1 < y2 + object2->h)
		{
			return true;
		}
	}
	//Rectangle v Rectangle
	if (object1->collisionType == RECTANGLE && object2->collisionType == RECTANGLE)
	{
		if
		(
			x1 + object1->w > x2 &&
			y1 + object1->h > y2 &&
			x2 + object2->w > x1 &&
			y2 + object2->h > y1
		)
		{
			return true;
		}
	}
	//Point v Circle
	if (object1->collisionType == POINT && object2->collisionType == CIRCLE)
	{
		int vx = abs(x2 - x1);
		int vy = abs(y2 - y1);

		float distance = sqrt((vx * vx) + (vy * vy));

		if (distance < (object2->w / 2))
		{
			return true;
		}
	}
	//Rectangle v Circle(only checks for collision with the rectangle corners)
	if (object1->collisionType == RECTANGLE && object2->collisionType == CIRCLE)
	{
		int points_x[] = {x1, x1 + object1->w, x1 + object1->w, x1};
		int points_y[] = {y1, y1 + object1->h, y1, y1 + object1->h};
		for (unsigned int i = 0; i < 4; i++)
		{
			int vx = abs(x2 - points_x[i]);
			int vy = abs(y2 - points_y[i]);

			float distance = sqrt((vx * vx) + (vy * vy));

			if (distance < (object2->w / 2))
			{
				return true;
			}
		}
	}
	//Circle v Circle
	if (object1->collisionType == CIRCLE && object2->collisionType == CIRCLE)
	{
		int vx = abs(x2 - x1);
		int vy = abs(y2 - y1);

		float distance = sqrt((vx * vx) + (vy * vy));

		if (distance < (object1->w / 2) + (object2->w / 2))
		{
			return true;
		}
	}
	return false;
}

std::vector<GameObject *> Game::checkCollisions(GameObject *object, int x, int y, std::initializer_list<unsigned int> class_ids)
{
	std::vector<GameObject *> collided_objects;
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		for (unsigned int j = 0; j < class_ids.size(); j++)
		{
			if (objects[i]->class_id == *(class_ids.begin() + j))
			{
				if (checkCollision(object, x, y, objects[i], objects[i]->x, objects[i]->y))
				{
					collided_objects.push_back(objects[i]);
				}
				break;
			}
		}
	}
	return collided_objects;
}