// Measure temperatures from a waterproof DS18B20 temperature sensor
// Values are in Celsius
// Based on code from https://randomnerdtutorials.com/guide-for-ds18b20-temperature-sensor-with-arduino/
/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
  Based on the Dallas Temperature Library example
*********/

// Include libraries (need to be installed first via Sketch -> Include Library -> Manage Libraries...)
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to the Arduino digital pin 4
const int oneWireBus = 4;

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to the Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // Start serial communication for debugging purposes
  Serial.begin(9600);
  // Initialise the temperature sensor
  sensors.begin();
}

void loop(void){ 
  // Call sensors.requestTemperatures() to get the temperature of the devices on the bus
  sensors.requestTemperatures(); 
  
  //Serial.print("Temp in Celsius: ");
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.println(sensors.getTempCByIndex(0)); //Get and print the temperature in Celsius
  //delay(15000); //Introduce delay for a certain amount of time before requesting the next temperature reading
}
