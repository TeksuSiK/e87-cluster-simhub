#include <globals.h>
#include <canbus.h>

const uint32_t CAN_BUS_ID = 0x1F6;

uint8_t indicatorsFrame[2] = {0x80, 0xF0};

uint8_t lastIndicator = 0;
uint32_t lastIndicatorTime = 0;
uint32_t lastFrameTime = 0;

void sendIndicators()
{
    uint32_t current = millis();

    uint8_t lightIndicator = lastIndicator;
    if (g_lights_indicators == 0)
    {
        if (current - lastIndicatorTime >= 600)
        {
            lightIndicator = g_lights_indicators;
        }
    }
    else
    {
        lightIndicator = g_lights_indicators;
        lastIndicatorTime = current;
    }

    if ((lastIndicator != lightIndicator) || (current - lastFrameTime >= 600))
    {
        if (lightIndicator != 0)
        {
            switch (lightIndicator)
            {
            case 1:
                indicatorsFrame[0] = 0x91;
                break;
            case 2:
                indicatorsFrame[0] = 0xA1;
                break;
            case 3:
                indicatorsFrame[0] = 0xB1;
                break;
            }

            if (lastIndicator == lightIndicator)
            {
                indicatorsFrame[1] = 0xF1;
            }
            else
            {
                indicatorsFrame[1] = 0xF2;
            }
        }
        else
        {
            indicatorsFrame[0] = 0x80;
            indicatorsFrame[1] = 0xF0;
        }

        lastIndicator = lightIndicator;
        lastFrameTime = current;
        CAN.sendMsgBuf(CAN_BUS_ID, 2, indicatorsFrame);
    }
}