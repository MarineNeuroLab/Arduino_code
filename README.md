# Arduino code
 Code for various Arduino projects. 
 Some code is finished and ready to use (these typically have a fritzing diagram to show wiring) and some are still work in progress. 
 
### Using LEDs
| Folder                            | Description  |
|:----------------------------------|:-------------|
| BlinkAll                          | turn on one or more LEDs at the same time |
| BlinkAndFadeInTurn                | turn on and fade out one or more LEDs in turn |
| BlinkInTurn                       | as BlinkAndFadeInTurn but without fading |
| BlinkInTurn10                     | as BlinkInTurn but for 10 LEDs |
| BlinkInTurnIndividualBrightness   | as BlinkAndFadeInTurn but specifying the brightness for each LED individually |
| BlinkOnce                         | blink a single LED |
| LEDcalibration                    | work in progress |
| LEDsON                            | turn on one or more LEDs and leave them on |
| LEDsONindividualBrightess         | turn on one or more LEDs and leave them with each LEDs brightness set individually|
| OneLEDon                          | turn on one LEDs and leave it on |

 ### Using motors
| Folder                 | Description  |
|:-----------------------|:-------------|
| VibrateOnce            | turn on a vibration motor and indicator LED |
| VibrateWithButtonPress | turn on a vibration motor and indicator LED whenever a button is pressed |
| StepperMotor           | continuously run a stepper motor in one direction at a set speed |

### Using a temperature sensor
| Folder                 | Description  |
|:-----------------------|:-------------|
| MeasureTemp            | measure the temperature in Celsius |

### Using sensors from Blue Robotics
| Folder                 | Description  |
|:-----------------------|:-------------|
| MeasureTempBR          | display temperature values (in Serial Monitor) captured in real time with the [Celsius Fast-Response, ±0.1°C Temperature Sensor](https://bluerobotics.com/store/sensors-sonars-cameras/sensors/celsius-sensor-r1/) |
| CelsiusDataToSD        | capture temperature data from the [Celsius Fast-Response, ±0.1°C Temperature Sensor](https://bluerobotics.com/store/sensors-sonars-cameras/sensors/celsius-sensor-r1/) and save to a .txt file on an SD card |
| MeasureDepthBR         | display temperature, pressure, depth, and altitude values (in Serial Monitor) captured in real time with the [Bar100 High-Resolution 1000m Depth/Pressure sensor](https://bluerobotics.com/store/sensors-sonars-cameras/sensors/bar100-sensor-r2-rp/) |
| DepthDataToSD          | capture pressure and temperature data from the [Bar100 High-Resolution 1000m Depth/Pressure sensor](https://bluerobotics.com/store/sensors-sonars-cameras/sensors/bar100-sensor-r2-rp/) and save to a .txt file on an SD card |
