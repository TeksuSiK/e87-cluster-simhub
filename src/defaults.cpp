#include <globals.h>

bool g_ignition = true;
bool g_engine_running = true;

bool g_lights_side = true;
bool g_lights_dip = false;
bool g_lights_main = false;
bool g_lights_front_fog = false;
bool g_lights_rear_fog = false;
uint8_t g_lights_indicators = 0;

uint16_t g_rpm = 1000;
uint16_t g_speed = 0;
uint8_t g_fuel = 35;

uint8_t g_engine_temperature = 90;

bool g_handbrake = false;
bool g_abs = false;
bool g_airbag = false;
bool g_seatbelt = false;

uint8_t g_time_hour = 0;
uint8_t g_time_minute = 0;
uint8_t g_time_second = 0;
uint8_t g_time_day = 0;
uint8_t g_time_month = 0;
uint16_t g_time_year = 0;