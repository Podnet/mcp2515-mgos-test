# MCP2515 testing Mongoose OS app
Mongoose os app to test mcp2515 CAN library ported from Arduino.


- Create MCP object 
```
struct MCP_CAN *mc; 
```
- Send message to CAN controller
```
void can_send(void *arg)
```
