/* Log data from the Blue Robotics Bar100 Sensor 
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
 ** CS - pin 4
*/

// Include libraries
#include <SPI.h>
#include <SD.h>
#include "Wire.h"
#include "KellerLD.h"

// Declare the sensor and SD card pin
KellerLD sensor;
const int chipSelect = 4;

// Declare the files
File dataFile;
File metaFile;

// Declare a variable to use as a timestamp and specify which fluid density to use
unsigned long timestamp;
const int DensityToUse = 1029; // kg/m^3 (997 for freshwater, 1029 for seawater)

  
void setup() {
  // Open serial communications
  Serial.begin(9600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.println("Starting");
  Wire.begin();
  
  // Initialise sensor
  sensor.init();
  sensor.setFluidDensity(DensityToUse); // kg/m^3 (997 for freshwater, 1029 for seawater)

  if (sensor.isInitialized()) {
    Serial.println("Sensor connected.");
  } else {
    Serial.println("Sensor not connected.");
  }

  // See if the SD card is present and can be initialized:
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");

  // Open the file to save metadata to
   metaFile = SD.open("META.txt", FILE_WRITE); //The filename can be max 8 characters long
   
  // If the file opened ok, proceed
  if (metaFile) {
    // Read the sensor and print to Serial Monitor
    sensor.read();
    Serial.println("Writing metadata to file"); 
  
    // Write to and close the file
    metaFile.print("Fluid density (kg/m^3): ");
    metaFile.println(DensityToUse);
    metaFile.print("P_min: ");
    metaFile.println(sensor.P_min);
    metaFile.print("P_max:  ");
    metaFile.println(sensor.P_max);
    metaFile.print("P_bar: ");
    metaFile.println(sensor.P_bar);
    metaFile.print("P_mode: ");
    metaFile.println(sensor.P_mode);
    metaFile.println();
    metaFile.println("Headings for DEPTH.txt file:");
    metaFile.println("Timestamp (ms since program started), Temperature in degrees C, Pressure in mbar, Depth in meters, Altitude in meters above sea level");
    metaFile.println();
    metaFile.println("!!NOTE: mbar, depth and altitude measurements are not absolute and require calibration!!");
    
    metaFile.close();
  }
}

void loop() {
  // Open the file to save to
  dataFile = SD.open("DEPTH.txt", FILE_WRITE); //The filename can be max 8 characters long
  
  // If the file opened ok, proceed
  if (dataFile) {
    // Read the sensor and timestamp, and print to Serial Monitor
    sensor.read();
    timestamp = millis();
    Serial.print("Temperature: "); 
    Serial.print(sensor.temperature()); 
    Serial.println(" degrees C");
    Serial.print("Pressure: "); 
    Serial.print(sensor.pressure()); 
    Serial.println(" mbar");
    Serial.print("Depth: "); 
    Serial.print(sensor.depth()); 
    Serial.println(" m");
    Serial.print("Altitude: "); 
    Serial.print(sensor.altitude()); 
    Serial.println(" m above mean sea level"); 
    Serial.print("Measured at ");
    Serial.println(timestamp); //Counts the number of ms after the program started
    Serial.println("---");
  
    // Write to and close the file
    dataFile.print(timestamp);
    dataFile.print(", ");
    dataFile.print(sensor.temperature()); //in degrees C
    dataFile.print(", ");
    dataFile.print(sensor.pressure()); //in mbar
    dataFile.print(", ");
    dataFile.print(sensor.depth()); //in meters
    dataFile.print(", ");
    dataFile.println(sensor.altitude()); //m above sea level
    dataFile.close();
    
    } else {
      // if the file didn't open ok, print an error:
      Serial.println("error opening file - is the filename too long (max 8 characters)?");
    }
  
    delay(971); //Set a delay so measurements are saved roughly once a second (taking into account the time to write to file etc)
}
