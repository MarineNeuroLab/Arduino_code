/* Log data from the Blue Robotics Celsius Fast-Response ±0.1°C Temperature Sensor 
  to an SD card using the SD library.

Adapted from File->Examples->SD->DataLogger
  (that was created 24 Nov 2010, modified 9 Apr 2012, by Tom Igoe)
  and the Blue Robotics example sketch for printing temperature measurements in the serial monitor
 
The circuit:
 sensor on SCL and SDA
 SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)
*/

// Include libraries
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "TSYS01.h"

// Declare the sensor and SD card pin
TSYS01 sensor;
const int chipSelect = 4;

// Declare the file
File dataFile;

// Declare a variable to use as a timestamp
unsigned long timestamp;

  
void setup() {
  // Open serial communications
  Serial.begin(9600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.println("Starting");
  Wire.begin();
  sensor.init();

  // See if the SD card is present and can be initialized:
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void loop() {
  // Open the file to save to
  dataFile = SD.open("CELSIUS.txt", FILE_WRITE); //The filename can be max 8 characters long
  
  // If the file opened ok, proceed
  if (dataFile) {
    // Read the sensor and timestamp, and print to Serial Monitor
    sensor.read();
    timestamp = millis();
    Serial.print("Temperature: ");
    Serial.print(sensor.temperature()); 
    Serial.print(" degrees C at ");
    Serial.println(timestamp); //Counts the number of ms after the program started
  
    // Write to and close the file
    dataFile.print(sensor.temperature());
    dataFile.print(", ");
    dataFile.println(timestamp);
    dataFile.close();
    
    } else {
      // if the file didn't open ok, print an error:
      Serial.println("error opening file - is the filename too long (max 8 characters)?");
    }
  
    delay(972); //Set a delay so measurements are saved roughly once a second (taking into account the time to write to file etc)
}
