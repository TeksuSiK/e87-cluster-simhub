#include <mcp_can.h>

extern MCP_CAN CAN;

extern bool g_ignition;
extern bool g_engine_running;

extern bool g_lights_side;
extern bool g_lights_dip;
extern bool g_lights_main;
extern bool g_lights_front_fog;
extern bool g_lights_rear_fog;
extern uint8_t g_lights_indicators;

extern uint16_t g_rpm;
extern uint16_t g_speed;
extern uint8_t g_fuel;

extern uint8_t g_engine_temperature;

extern bool g_handbrake;
extern bool g_abs;
extern bool g_airbag;
extern bool g_seatbelt;

extern uint8_t g_time_hour;
extern uint8_t g_time_minute;
extern uint8_t g_time_second;
extern uint8_t g_time_day;
extern uint8_t g_time_month;
extern uint16_t g_time_year;