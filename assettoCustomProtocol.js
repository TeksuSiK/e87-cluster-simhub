var ignition = $prop('EngineIgnitionOn');
var engine_running = $prop('EngineStarted');

var lights_side = ignition;
var lights_dip = 0;
var lights_main = 0;
var lights_front_fog = 0;
var lights_rear_fog = 0;

var lights_indicators;
var lights_indicator_left_prop = 0;
var lights_indicator_right_prop = 0;
if (lights_indicator_left_prop && lights_indicator_right_prop) {
    lights_indicators = 3;
} else if (lights_indicator_left_prop) {
    lights_indicators = 1;
} else if (lights_indicator_right_prop) {
    lights_indicators = 2;
} else {
    lights_indicators = 0;
}

var rpm = $prop('Rpms');
var speed = $prop('SpeedKmh');
var currentFuel = $prop('Fuel');
var maxFuel = $prop('MaxFuel');
function calculate(current, max) {
    return (current / max) * 100;
}
var fuel = calculate(currentFuel, maxFuel);
if (isNaN(fuel)) {
    fuel = 0;
}

var engine_temperature = $prop('OilTemperature');

var handbrake = $prop('Handbrake');
var abs = Number($prop('ABSLevel') == 0);
var airbag = 0;
var seatbelt = 0;

var currentTime = new Date();
var hour = currentTime.getHours();
var minute = currentTime.getMinutes();
var second = currentTime.getSeconds();
var year = currentTime.getFullYear();
var month = currentTime.getMonth();
var day = currentTime.getDay();

return `SH;${ignition};${engine_running};${lights_side};${lights_dip};${lights_main};${lights_front_fog};${lights_rear_fog};${lights_indicators};${rpm};${speed};${fuel};${engine_temperature};${handbrake};${abs};${airbag};${seatbelt};${hour};${minute};${second};${day};${month};${year};\n`;
