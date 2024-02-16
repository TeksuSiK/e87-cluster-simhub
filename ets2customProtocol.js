var ignition = $prop('EngineIgnitionOn');
var engine_running = $prop('EngineStarted');

var lights_side = Number($prop('GameRawData.TruckValues.CurrentValues.LightsValues.Parking'));
var lights_dip = Number($prop('GameRawData.TruckValues.CurrentValues.LightsValues.BeamLow'));
var lights_main = Number($prop('GameRawData.TruckValues.CurrentValues.LightsValues.BeamHigh'));
var lights_front_fog = Number($prop('GameRawData.TruckValues.CurrentValues.LightsValues.Beacon'));
var lights_rear_fog = 0;

var lights_indicators;
var lights_indicator_left_prop = $prop('GameRawData.TruckValues.CurrentValues.LightsValues.BlinkerLeftOn');
var lights_indicator_right_prop = $prop('GameRawData.TruckValues.CurrentValues.LightsValues.BlinkerRightOn');
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

var engine_temperature = $prop('GameRawData.TruckValues.CurrentValues.DashboardValues.WaterTemperature');

var handbrake = Number($prop('GameRawData.TruckValues.CurrentValues.MotorValues.BrakeValues.ParkingBrake'));
var abs = 0;
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
