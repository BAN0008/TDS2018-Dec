#include <SFML/Network.hpp>
#include <unordered_map>
#include <string>
#include <iostream>

#define PORT 3366

enum Commands {JOIN_REQUEST, JOIN_DENIED, JOIN_ACCEPTED};

int main(int argc, char *argv[])
{
	sf::UdpSocket socket;
	socket.setBlocking(true);
	socket.bind(PORT);

	sf::Packet buffer;
	sf::IpAddress client_ip;
	uint16_t client_port;
	uint8_t command;

	sf::Packet outgoing_packet;

	while (true)
	{
		outgoing_packet.clear();
		buffer.clear();
		socket.receive(buffer, client_ip, client_port);
		buffer >> command;
		switch (command)
		{
			case JOIN_REQUEST:
				outgoing_packet << JOIN_ACCEPTED;
				socket.send(outgoing_packet, client_ip, client_port);
				break;
		}
	}
	return 0;
}