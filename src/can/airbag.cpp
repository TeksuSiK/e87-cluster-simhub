#include <globals.h>
#include <canbus.h>

const uint32_t CAN_BUS_ID = 0x0D7;

uint8_t airbagFrame[2] = {0xC3, 0xFF};

void sendAirbag()
{
    if (!g_airbag)
    {
        CAN.sendMsgBuf(CAN_BUS_ID, 5, airbagFrame);
        airbagFrame[0]++;
    }
}