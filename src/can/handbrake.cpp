#include <globals.h>
#include <canbus.h>

const uint32_t CAN_BUS_ID = 0x34F;

uint8_t handbrakeFrame[2] = {0xFE, 0xFF};

void sendHandbrake()
{
    if (g_handbrake)
    {
        handbrakeFrame[0] = 0xFE;
    }
    else
    {
        handbrakeFrame[0] = 0xFD;
    }

    CAN.sendMsgBuf(CAN_BUS_ID, 5, handbrakeFrame);
}