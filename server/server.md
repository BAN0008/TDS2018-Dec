# Server Pseudo Code

```
while true
{
	//Process Incoming Events
	data = receive()
	if data.notEmpty()
		if ip_map.contains(data.ip)
			data.process()
		else
			if (JOIN_REQUEST)
				...

	if (timeToSend)
		//Simulate past ~50ms of time
		...

		//Send events
		...
}
```