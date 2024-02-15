#include <canbus.h>

uint32_t previous = 0;
uint32_t counter = 0;

void sendCanBus()
{
    uint32_t current = millis();
    if (current - previous >= 10)
    {
        sendIgnition();
        sendLightning();

        if (counter % 7 == 0)
        {
            sendSpeed();
        }
        
        if (counter % 20 == 0)
        {
            sendRpm();
            sendAbs();
            sendAirbag();
            sendEngineTemperature();
            sendFuel();
            sendHandbrake();
            sendSeatbelt();
            sendIndicators();
        }

        if (counter % 100 == 0)
        {
            sendTime();
        }

        counter++;
        previous = current;
    }
}
