#include <globals.h>
#include <canbus.h>

const uint32_t CAN_BUS_ID_ABS = 0x19E;
const uint32_t CAN_BUS_ID_ABS_COUNTER = 0x0C0;

uint8_t absFrame[8] = {0x00, 0xE0, 0xB3, 0xFC, 0xF0, 0x43, 0x00, 0x65};
uint8_t absCounterFrame[2] = {0xF0, 0xFF};

void sendAbs()
{
    if (!g_abs)
    {
        absFrame[2] = ((((absFrame[2] >> 4) + 3) << 4) & 0xF0) | 0x03;
        CAN.sendMsgBuf(CAN_BUS_ID_ABS, 8, absFrame);

        CAN.sendMsgBuf(CAN_BUS_ID_ABS_COUNTER, 2, absCounterFrame);
        absCounterFrame[0] = ((absCounterFrame[0] + 1) | 0xF0);
    }
}