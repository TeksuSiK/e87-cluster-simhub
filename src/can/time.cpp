#include <globals.h>
#include <canbus.h>

const uint32_t CAN_BUS_ID = 0x39E;

uint8_t timeFrame[8] = {0x0B, 0x10, 0x00, 0x0D, 0x1F, 0xDF, 0x07, 0xF2};

void sendTime()
{
    timeFrame[0] = g_time_hour;
    timeFrame[1] = g_time_minute;
    timeFrame[2] = g_time_second;

    timeFrame[3] = g_time_day;
    timeFrame[4] = (g_time_month << 4) | 0x0F;

    timeFrame[5] = g_time_year;
    timeFrame[6] = (g_time_year >> 8);

    CAN.sendMsgBuf(CAN_BUS_ID, 8, timeFrame);
}