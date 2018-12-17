#include <SFML/Network.hpp>
#include <iostream>

#define PORT 3366

int main(int argc, char *argv[])
{
	sf::UdpSocket socket;
	socket.setBlocking(false);
	socket.bind(PORT);

	sf::Clock clock;
	std::cout << clock.getElapsedTime().asMicroseconds() << std::endl;
	std::cout << clock.getElapsedTime().asMilliseconds() << std::endl;
	return 0;
}