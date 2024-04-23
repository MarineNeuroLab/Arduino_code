// Detect the presence of liquid (e.g. a spill) with a liquid sensor
// e.g. the Optomax Digital Liquid Level Sensor (product ID: 3397) from Adafruit
// Modified from code by Adafruit (see below) and code by ShawnHymel (https://gist.github.com/ShawnHymel/a7c6cd17f00dd10e4325f72f83842be1)

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

/************************** Hardware ***********************************/

//     Sensor    | Arduino
//  -------------|---------
//    Vs (RED)   |    5V
//   Out (GREEN) |   pin 5
//   GND (BLUE)  |    GND

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

/************************ Code *******************************/

// Pins
const int SENSOR_PIN = 5;

int sensor_state = 1; //if sensor is 1, it is dry. If 0, it's wet
int previous_sensor_state = 1;

// set up the 'spills' feed
AdafruitIO_Feed *spills = io.feed("spills");


void setup() {

  // set sensor pin as an input
  pinMode(SENSOR_PIN, INPUT);

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // set up a message handler for the count feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
 // led->onMessage(handleMessage);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  int isDry = digitalRead(SENSOR_PIN);

  if(isDry == 1)
    sensor_state=1;
    //Serial.print("Sensor is dry");
  else 
    sensor_state=0;
    //Serial.print("Sensor is wet");

  if(sensor_state == previous_sensor_state)
    return; 
  
  // save the sensor state to the 'Spills' feed on adafruit io
  Serial.print("sending sensor state -> "); Serial.println(sensor_state);
  spills ->save(sensor_state);

  // store last button state
  previous_sensor_state = sensor_state;

}
