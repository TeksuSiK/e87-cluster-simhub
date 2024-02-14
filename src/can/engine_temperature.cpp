#include <globals.h>
#include <canbus.h>

const uint32_t CAN_BUS_ID = 0x1D0;

uint8_t engineTemperatureFrame[8] = {0x00, 0xFF, 0x63, 0xCD, 0x5D, 0x37, 0xCD, 0xA8};

void sendEngineTemperature()
{
    uint16_t temperature = g_engine_temperature + 48;
    engineTemperatureFrame[0] = temperature;
    engineTemperatureFrame[2]++;

    CAN.sendMsgBuf(CAN_BUS_ID, 8, engineTemperatureFrame);
}