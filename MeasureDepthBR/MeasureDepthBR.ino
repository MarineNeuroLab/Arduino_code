// Based on code from BlueRobotics Keller LD Library -> KellerLD_Example

#include "Wire.h"
#include "KellerLD.h"

KellerLD sensor;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  Wire.begin();

  // Initialise sensor
  sensor.init();
  sensor.setFluidDensity(1029); // kg/m^3 (997 for freshwater, 1029 for seawater)

  if (sensor.isInitialized()) {
    Serial.println("Sensor connected.");
  } else {
    Serial.println("Sensor not connected.");
  }
}

void loop() {
  sensor.read();

  Serial.print("Temperature: "); 
  Serial.print(sensor.temperature()); 
  Serial.println(" degrees C");
  
  Serial.print("Pressure: "); 
  Serial.print(sensor.pressure()); 
  Serial.println(" mbar (uncalibrated)");
  
  Serial.print("Depth: "); 
  Serial.print(sensor.depth()); 
  Serial.println(" m (uncalibrated)");
  
  Serial.print("Altitude: "); 
  Serial.print(sensor.altitude()); 
  Serial.println(" m above mean sea level (uncalibrated)");

  Serial.println("---");

  //Serial.println(sensor.P_min);
  //Serial.println(sensor.P_max);
  //Serial.println(sensor.P_bar);
  //Serial.println(sensor.P_mode);

  delay(964); //Introduce a delay so measurements are printed roughly once per second
}
