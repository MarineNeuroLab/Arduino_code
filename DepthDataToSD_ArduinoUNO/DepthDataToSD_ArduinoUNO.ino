/* Log data from the Blue Robotics Bar100 Sensor 
  to an SD card using and Arduino UNO with a datalogging Arduino Shield from Adafruit
  and the SD library.

  Adapted from File->Examples->SD->DataLogger 
*/

// Include libraries, declare the sensor and SD card pin and files
#include <SPI.h>
#include <SD.h>
#include "Wire.h"
#include "KellerLD.h"

KellerLD sensor;
const int chipSelect = 10;

File dataFile;
File metaFile;

// Declare a variable to use as a timestamp and specify which fluid density to use
unsigned long timestamp;
const int DensityToUse = 1029; // kg/m^3 (997 for freshwater, 1029 for seawater)
  
void setup() {
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
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("SD card initialized.");

  // Open the file to save metadata to
  metaFile = SD.open("M.txt", FILE_WRITE);
   
  // If the file opened ok, proceed to read the sensory, write to and close the file
  if (metaFile) {
    sensor.read();
  
    metaFile.print("Fluid density (kg/m^3), P_min, P_max, P_bar, P_mode: ");
    String sep = ", ";
    metaFile.println(DensityToUse+sep+sensor.P_min+sep+sensor.P_max+sep+sensor.P_bar+sep+sensor.P_mode);
    metaFile.println("Headings for D.txt: Timestamp (ms since program started), Temp (C), Pressure (mbar), Depth (m)");
    metaFile.println("(mbar and depth measurements are not absolute and require calibration)");
    metaFile.close();
  }
}

void loop() {
  // Open the file to save to
  dataFile = SD.open("D.txt", FILE_WRITE);
  
  // If the file opened ok, proceed to read the sensor and timestamp
  if (dataFile) {
    sensor.read();
    timestamp = millis();
    
    dataFile.print(timestamp);
    dataFile.print(", ");
    dataFile.print(sensor.temperature()); //in degrees C
    dataFile.print(", ");
    dataFile.print(sensor.pressure()); //in mbar
    dataFile.print(", ");
    dataFile.println(sensor.depth()); //in meters
    dataFile.close();
    } 
    else {
      // if the file didn't open ok, print an error:
      Serial.println("error opening file");
    }
  
    delay(971); //Set a delay so measurements are saved roughly once a second (taking into account the time to write to file etc)
}
