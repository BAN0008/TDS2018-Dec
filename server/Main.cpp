#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include "ClientList.h"

#define PORT 3366

enum Commands {JOIN_REQUEST, JOIN_DENIED, JOIN_ACCEPTED};
enum JOIN_DENIED_reasons {ALREADY_CONNECTED, DUPLICATE_NAME, INCORRECT_VERSION, BANNED, WRONG_PASSWORD, OTHER};
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
			{
				std::string name;
				buffer >> name;

				if (ClientList::containsIP(client_ip.toInteger()))
				{
					outgoing_packet << JOIN_DENIED << ALREADY_CONNECTED;
					socket.send(outgoing_packet, client_ip, client_port);
					break;
				}
				if (ClientList::containsName(name))
				{
					outgoing_packet << JOIN_DENIED << DUPLICATE_NAME;
					socket.send(outgoing_packet, client_ip, client_port);
					break;
				}

				uint8_t clid = ClientList::find_spare_clid();
				ClientList::add(client_ip.toInteger(), clid, name, client_port);
				outgoing_packet << JOIN_ACCEPTED;
				socket.send(outgoing_packet, client_ip, client_port);
				std::cout << name << " has joined" << std::endl;
				std::cout << "The Client ID " << (unsigned int)clid << " has been assigned" << std::endl;
				std::cout << "Test " << (unsigned long int)ClientList::find_ip(clid) << std::endl;
				break;
			}
		}
	}
	return 0;
}