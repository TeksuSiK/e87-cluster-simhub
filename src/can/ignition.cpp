#include <globals.h>
#include <canbus.h>

const uint32_t CAN_BUS_ID = 0x130;

uint8_t ignitionFrame[5] = {0x00, 0x40, 0x22, 0x8F, 0xFE};

void sendIgnition()
{
    if (g_engine_running)
    {
        ignitionFrame[0] = 0x45;
    }
    else if (g_ignition)
    {
        ignitionFrame[0] = 0x41;
    }
    else
    {
        ignitionFrame[0] = 0x00;
    }

    CAN.sendMsgBuf(CAN_BUS_ID, 5, ignitionFrame);
}