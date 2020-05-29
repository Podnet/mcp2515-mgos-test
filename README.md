# MCP2515 testing Mongoose OS app
Mongoose os app to test mcp2515 CAN library ported from Arduino.


- Create MCP object 
``` C
struct MCP_CAN *mc; 
```
- Send message to CAN controller
```C
void can_send(void *arg)
```
- Recieve messages from other CAN controller
```C
void can_recieve(void *arg)
```
