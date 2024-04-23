// Based on (i.e. just stripped down from) the tsl2591 example from the Adafruit TSL2591 Library
// In this version, the TSL2591 sensor is connected to a Metro ESP32-S2 via a STEMMA QT connector

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"

Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); // pass in a number for the sensor identifier (for your use later)


// SETTINGS ///////////////////////////////////////////////////
// Choose which sensor gain and integration time to use

void configureSensor(void)
{
  // You can change the gain on the fly, to adapt to brighter/dimmer light situations
  // tsl.setGain(TSL2591_GAIN_LOW);    // 1x gain (for bright light)
  tsl.setGain(TSL2591_GAIN_MED);      // 25x gain
  // tsl.setGain(TSL2591_GAIN_HIGH);   // 428x gain (for dim light)
  
  // Changing the integration time gives you a longer time over which to sense light
  // longer timelines are slower, but are good in very low light situtations!
  tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);  // shortest integration time (bright light)
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_200MS);
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_400MS);
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_500MS);
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_600MS);  // longest integration time (dim light)
}
///////////////////////////////////////////////////////////////


void setup() 
{
  Serial.begin(9600);
  tsl.begin();
  configureSensor(); //Configure the sensor
}

void loop() 
{ 
  //Perform a read using the Adafruit Unified Sensor API.
  sensors_event_t event; //Get a new sensor event
  tsl.getEvent(&event);
  
  float light_data = event.light; //Get the lux value
  
  Serial.println(light_data); //Print the value to the serial monitor

    /* If event.light = 0 lux the sensor is probably saturated */
    /* and no reliable data could be generated! */
    /* if event.light is +/- 4294967040 there was a float over/underflow */
    
  delay(500);
}
