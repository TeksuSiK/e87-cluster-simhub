#include <Arduino.h>

#include <globals.h>
#include <canbus.h>
#include <serial.h>

MCP_CAN CAN(10);

void setup()
{
    Serial.begin(115200);

    if (CAN.begin(MCP_ANY, CAN_100KBPS, MCP_8MHZ) == CAN_OK)
    {
        Serial.println("MCP2515 Initialized successfully");
    }

    CAN.setMode(MCP_NORMAL);
}

void loop()
{
    sendCanBus();
    readSerial();
}

