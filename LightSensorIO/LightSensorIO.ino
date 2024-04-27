// Save data from a TSL2591 light sensor connected to a Metro ESP32-S2 Express via a STEMMA QT connector (all from Adafruit)
// Modified from code by Adafruit (see below) and the tsl2591 Arduino example code by Adafruit

/*********************** Adafruit credit ********************************************/
// Adafruit IO Publish & Subscribe, Digital Input and Output Example
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Modified by Brent Rubell for Adafruit Industries
// Copyright (c) 2020 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Initial steps ***********************************/

#include "config.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); // pass in a number for the sensor identifier (for your use later)

/***************************** INPUT ****************************************/
// STEP 1
// Edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi clients.

// STEP 2
// Decide how frequently to record light values
// NOTE: lux values are rounded to the nearest integer and only sent to Adafruit IO when this value changes
int interval=500;

// STEP 3
// Choose which gain and integration time to use:

void configureSensor(void)
{
  // You can change the gain on the fly, to adapt to brighter/dimmer light situations
  tsl.setGain(TSL2591_GAIN_LOW);    // 1x gain (bright light)
  //tsl.setGain(TSL2591_GAIN_MED);      // 25x gain
  //tsl.setGain(TSL2591_GAIN_HIGH);   // 428x gain
  
  // Changing the integration time gives you a longer time over which to sense light
  // longer timelines are slower, but are good in very low light situtations!
  //tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);  // shortest integration time (bright light)
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_200MS);
  tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_400MS);
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_500MS);
  // tsl.setTiming(TSL2591_INTEGRATIONTIME_600MS);  // longest integration time (dim light)
}

/***************************** Code *****************************************/

float rounded_lux_value = 1.00;
float previous_rounded_lux_value = 1.00;

// set up the 'light' feed
AdafruitIO_Feed *light = io.feed("light");


void setup() {
  // start the serial connection
  Serial.begin(9600); 

  // wait for serial monitor to open
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  tsl.begin();
  configureSensor(); //Configure the sensor based on the input provided above
}


void loop() {
  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  //Perform a read using the Adafruit Unified Sensor API.
  sensors_event_t event; //Get a new sensor event
  tsl.getEvent(&event);
  float rounded_lux_value = round(event.light); //Round the lux value to the closest integer
  
  Serial.println(rounded_lux_value); //Print the value to the serial monitor

  //If the light level has not changed since the previously recorded light level, restart the loop
  if(rounded_lux_value == previous_rounded_lux_value)
  return;

  // save the rounded lux value to the 'light' feed on adafruit io
  Serial.print(rounded_lux_value); Serial.println("-> sending rounded lux value"); 
  light ->save(rounded_lux_value);

  // store the current lux value
  previous_rounded_lux_value = rounded_lux_value;
  delay(interval);

}
