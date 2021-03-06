#include "mgos.h"
#include "mgos_mcp2515.h"
#include "mgos_spi.h"

/*! \mainpage MCP2515 testing
 *
 * \section Documentation
 *
 * This is a test app to communicate to CAN transceiver. 
 */

struct MCP_CAN *mc;



void can_send(void *arg)
{
  unsigned char message[2] = {0, 1};
  int id = mgos_mcp2515_getCanId(mc);
  mgos_mcp2515_sendMsgBuf(mc, id, 0, 2, message);
}
/**< Send message to CAN transciever */



void can_recieve(void *arg)
{

  unsigned char len = 0;
  unsigned char buf[8];
  if (CAN_MSGAVAIL == mgos_mcp2515_checkReceive(mc))
  {
    LOG(LL_INFO, ("TCU: CAN message received"));
    mgos_mcp2515_readMsgBuf(mc, &len, buf); // message is read in buf, to see message print the buf
  }
  else
  {
    LOG(LL_INFO, ("TCU: No CAN message received"));
  }

}
/**< Recieve messages from other CAN controller */

extern "C"
{
  enum mgos_app_init_result mgos_app_init(void)
  {
    LOG(LL_INFO, ("TCU: Adding CAN interface."));

    struct mgos_spi *spi;
    
    spi = mgos_spi_get_global();

    if (spi == NULL)
    {
      LOG(LL_ERROR, ("SPI is not configured, make sure spi.enable is true"));
    }

    mc = mgos_mcp2515_create(10); // cs pin as input
    while (CAN_OK != mgos_mcp2515_begin(mc, CAN_500KBPS))
    {
      LOG(LL_INFO, ("TCU: CAN init failed"));
    }

    LOG(LL_INFO, ("TCU: CAN init ok!"));

    return MGOS_APP_INIT_SUCCESS;
  }
  /**< Mongoose OS intialization app function */
}