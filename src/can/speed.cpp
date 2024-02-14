#include <globals.h>
#include <canbus.h>

const uint32_t CAN_BUS_ID = 0x1A6;

uint8_t speedFrame[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0};

uint16_t lastSpeed = 0;

void sendSpeed()
{
    uint16_t speed = g_speed + lastSpeed;

    uint16_t counter = (speedFrame[6] | (speedFrame[7] << 8));
    counter += 315;

    speedFrame[0] = speed;
    speedFrame[1] = (speed >> 8);
    speedFrame[2] = speedFrame[0];
    speedFrame[3] = speedFrame[1];
    speedFrame[4] = speedFrame[0];
    speedFrame[5] = speedFrame[1];
    speedFrame[6] = counter;
    speedFrame[7] = ((counter >> 8) | 0xF0);

    CAN.sendMsgBuf(CAN_BUS_ID, 8, speedFrame);

    lastSpeed = speed;
}