# Arduino code
 Code for various Arduino projects. 
 Some code is finished and ready to use (these typically have a fritzing diagram to show wiring) and some are still work in progress. 
 
### Using LEDs
| Folder                            | Description  | Microcontroller |
|:----------------------------------|:-------------|:----------------|
| BlinkAll                          | turn on one or more LEDs at the same time | Arduino UNO |
| BlinkAndFadeInTurn                | turn on and fade out one or more LEDs in turn | Arduino UNO |
| BlinkInTurn                       | as BlinkAndFadeInTurn but without fading | Arduino UNO |
| BlinkInTurn10                     | as BlinkInTurn but for 10 LEDs | Arduino UNO |
| BlinkInTurnIndividualBrightness   | as BlinkAndFadeInTurn but specifying the brightness for each LED individually | Arduino UNO |
| BlinkOnce                         | blink a single LED | Arduino UNO |
| LEDcalibration                    | measures the light output from one LED with a phototransistor | Arduino UNO |
| LEDsON                            | turn on one or more LEDs and leave them on | Arduino UNO |
| LEDsONindividualBrightess         | turn on one or more LEDs and leave them with each LEDs brightness set individually| Arduino UNO |
| OneLEDon                          | turn on one LED and leave it on | Arduino UNO |

 ### Using motors
| Folder                 | Description  | Microcontroller |
|:-----------------------|:-------------|:----------------|
| VibrateOnce            | turn on a vibration motor and indicator LED | Arduino UNO |
| VibrateWithButtonPress | turn on a vibration motor and indicator LED whenever a button is pressed | Arduino UNO |
| StepperMotor           | continuously run a [stepper motor](https://www.adafruit.com/product/918) in one direction at a set speed via a [breakout board](https://www.adafruit.com/product/3297) | Arduino UNO |

### Using a temperature sensor
| Folder                 | Description  | Microcontroller |
|:-----------------------|:-------------|:----------------|
| MeasureTemp            | measure the temperature in Celsius | Arduino UNO |

### Using sensors from Blue Robotics
| Folder                 | Description  | Microcontroller |
|:-----------------------|:-------------|:----------------|
| MeasureTempBR          | display temperature values (in Serial Monitor) captured in real time with the [Celsius Fast-Response, ±0.1°C Temperature Sensor](https://bluerobotics.com/store/sensors-sonars-cameras/sensors/celsius-sensor-r1/) | Adafruit Feather M0 Adalogger |
| CelsiusDataToSD        | capture temperature data from the [Celsius Fast-Response, ±0.1°C Temperature Sensor](https://bluerobotics.com/store/sensors-sonars-cameras/sensors/celsius-sensor-r1/) and save to a .txt file on an SD card | Adafruit Feather M0 Adalogger |
| MeasureDepthBR         | display temperature, pressure, depth, and altitude values (in Serial Monitor) captured in real time with the [Bar100 High-Resolution 1000m Depth/Pressure sensor](https://bluerobotics.com/store/sensors-sonars-cameras/sensors/bar100-sensor-r2-rp/) | Adafruit Feather M0 Adalogger |
| DepthDataToSD          | capture pressure and temperature data from the [Bar100 High-Resolution 1000m Depth/Pressure sensor](https://bluerobotics.com/store/sensors-sonars-cameras/sensors/bar100-sensor-r2-rp/) and save to a .txt file on an SD card | Adafruit Feather M0 Adalogger |
| DepthDataToSD_ArduinoUNO          | capture pressure and temperature data from the [Bar100 High-Resolution 1000m Depth/Pressure sensor](https://bluerobotics.com/store/sensors-sonars-cameras/sensors/bar100-sensor-r2-rp/) and save to a .txt file on an SD card | Arduino Uno with Adafruit Datalogger Arduino Shield|
