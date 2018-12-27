#include <SFML/Network.hpp>
#include <iostream>

#define PORT 3366
#define SYNC 0
#define PING 1

int main(int argc, char *argv[])
{
	sf::UdpSocket socket;
	socket.setBlocking(true);
	socket.bind(PORT);

	sf::Packet ping;
	ping << (uint8_t)PING;

	sf::Packet buffer;
	sf::IpAddress remoteIP;
	sf::IpAddress newRemoteIP;
	unsigned short remotePort;
	sf::Socket::Status status;

	sf::Clock clock;
	//std::cout << clock.getElapsedTime().asMicroseconds() << std::endl;
	//std::cout << clock.getElapsedTime().asMilliseconds() << std::endl;

	uint8_t command;

	while (true)
	{
		status = socket.receive(buffer, remoteIP, remotePort);
		if (status == sf::Socket::Status::Done)
		{
			buffer >> command;
			if (command == SYNC)
			{
				sf::Clock ping_clock;
				socket.send(ping, remoteIP, PORT);
				while (true)
				{
					status = socket.receive(buffer, newRemoteIP, remotePort);
					if (status == sf::Socket::Status::Done && newRemoteIP.toInteger() == remoteIP.toInteger())
					{
						buffer >> command;
						if (command == PING)
						{
							sf::Time latency = ping_clock.getElapsedTime();
							std::cout << latency.asMilliseconds() << std::endl;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}