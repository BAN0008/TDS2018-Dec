#include <unordered_map>

namespace ClientList
{
	namespace 
	{
		struct Client
		{
			uint32_t    ip;
			uint8_t     clid;
			std::string name;
			uint16_t port;
		};

		std::unordered_map<uint32_t, Client *> ip_map;
		std::unordered_map<uint8_t,  Client *> clid_map;

		void remove_client(Client *client)
		{
			ip_map.erase(client->ip);
			clid_map.erase(client->clid);
			delete client;
		}
	}

	void add(uint32_t ip, uint8_t clid, std::string name, uint16_t port)
	{
		Client *newClient = new Client();
		newClient->ip = ip;
		newClient->clid = clid;
		newClient->name = name;
		newClient->port = port;

		ip_map.emplace(ip, newClient);
		clid_map.emplace(clid, newClient);
	}

	uint8_t find_spare_clid()
	{
		for (uint8_t i = 0; i < 253; i++)
		{
			if (clid_map.count(i) <= 0)
			{
				return i;
			}
		}
	}

	bool containsName(std::string name)
	{
		for (auto i = clid_map.begin(); i != clid_map.end(); i++)
		{
			if (i->second->name.compare(name))
			{
				return true;
			}
		}
		return false;
	}

	bool containsIP(uint32_t ip)
	{
		return (ip_map.count(ip) > 0);
	}

	void remove_by_ip(uint32_t ip)
	{
		remove_client(ip_map[ip]);
	}
	void remove_by_clid(uint8_t clid)
	{
		remove_client(clid_map[clid]);
	}

	uint32_t find_ip(uint8_t clid)
	{
		return clid_map[clid]->ip;
	}
}