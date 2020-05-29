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
- Mongoose OS app intialization function
``` C
enum mgos_app_init_result mgos_app_init(void)
  {
    LOG(LL_INFO, ("TCU: Adding CAN interface."));
    mc = mgos_mcp2515_create(10); // cs pin as input
    while (CAN_OK != mgos_mcp2515_begin(mc, CAN_500KBPS))
    {
      LOG(LL_INFO, ("TCU: CAN init failed"));
    }

    LOG(LL_INFO, ("TCU: CAN init ok!"));

    return MGOS_APP_INIT_SUCCESS;
  }
}
```
