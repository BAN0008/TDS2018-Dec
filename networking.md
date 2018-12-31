# Command Descriptions
| Name | Fields     | Description |
|------|------------|-------------|
| **JOIN_REQUEST**  | version, password hash, name | Request to join server sent by client |
| **JOIN_DENIED**   | reason(INCORRECT_VERSION, BANNED, WRONG_PASSWORD, OTHER) | Reply to **JOIN_REQUEST** to inform the client that it cannot join |
| **JOIN_ACCEPTED** | | Reply to **JOIN_REQUEST** |


# Connecting to server
Client -> Server ([**JOIN_REQUEST**](#command-descriptions))

Server [**JOIN_REQUEST**](#command-descriptions) checklist
- Suitable client version
- Client not blacklisted
- Client on whitelist(if configured)
- Correct password hash(if password configured)
- Ensure ping isn't too high

If above conditions not met
Server -> Client ([**JOIN_DENIED**](#command-descriptions))
otherwise
Server -> Client ([**JOIN_ACCEPTED**](#command-descriptions))
Server.client_list.append(Client(client_id, ip_address))

[Synchronize client game clock with servers](#time-synchronization)
Synchronize client world
Create client player

Create

# Time Synchronization
Measure ping 5 times
average pings excluding pings with a deviation of more than 1.5x the median