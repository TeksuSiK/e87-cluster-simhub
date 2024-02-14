#include <globals.h>
#include <canbus.h>

const uint32_t CAN_BUS_ID = 0x349;

uint8_t fuelFrame[5] = {0x00, 0x00, 0x00, 0x00, 0x00};

void sendFuel()
{
    // E87 114i - 52 liters max
    // 52 * 160 = 8320
    // This could depend on car the cluster comes from
    uint16_t fuel = map(g_fuel, 0, 100, 0, 8320);

    fuelFrame[0] = fuel;
    fuelFrame[1] = (fuel >> 8);

    fuelFrame[2] = fuelFrame[0];
    fuelFrame[3] = fuelFrame[1];

    CAN.sendMsgBuf(CAN_BUS_ID, 8, fuelFrame);
}