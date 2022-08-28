// Based on example code from Blue Robotics (BlueRobotics TSYS01 Library -> TSYS01_example)

#include <Wire.h>
#include "TSYS01.h"

TSYS01 sensor;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  Wire.begin();
  sensor.init();
}

void loop() {
  sensor.read();
  Serial.print("Temperature: ");
  Serial.print(sensor.temperature()); 
  Serial.println(" deg C");

  delay(1000);
}
