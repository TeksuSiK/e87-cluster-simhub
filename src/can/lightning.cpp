#include <globals.h>
#include <canbus.h>
#include <lights.h>

const uint32_t CAN_BUS_ID = 0x21A;

uint8_t lightningFrame[3] = {0x00, 0x00, 0xF7};

void sendLightning()
{
    uint8_t lights = 0;

    if (g_lights_side)
    {
        lights |= SIDE;
    }

    if (g_lights_dip)
    {
        lights |= DIP;
    }

    if (g_lights_main)
    {
        lights |= MAIN;
    }

    if (g_lights_front_fog)
    {
        lights |= FRONT_FOG;
    }

    if (g_lights_rear_fog)
    {
        lights |= REAR_FOG;
    }

    lightningFrame[0] = lights;

    CAN.sendMsgBuf(CAN_BUS_ID, 3, lightningFrame);
}