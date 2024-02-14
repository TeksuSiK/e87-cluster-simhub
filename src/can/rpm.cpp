#include <globals.h>
#include <canbus.h>

const uint32_t CAN_BUS_ID = 0x0AA;

uint8_t rpmFrame[8] = {0x5F, 0x59, 0xFF, 0x00, 0x00, 0x00, 0x80, 0x99};

void sendRpm()
{
    uint16_t rpm = g_rpm * 4;

    rpmFrame[4] = rpm;
    rpmFrame[5] = (rpm >> 8);

    CAN.sendMsgBuf(CAN_BUS_ID, 8, rpmFrame);
}