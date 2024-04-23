// Detect the presence of liquid (e.g. a spill) with a liquid sensor
// e.g. the Optomax Digital Liquid Level Sensor (product ID: 3397) from Adafruit
// Code based on the original by ShawnHymel (https://gist.github.com/ShawnHymel/a7c6cd17f00dd10e4325f72f83842be1)


// Liquid level detection using an SST sensor
//
// When a liquid touches the tip of the sensor,
// the value 0 will be printed in the serial monitor
// 
// Hardware:
//     Sensor    | Arduino
//  -------------|---------
//    Vs (RED)   |    5V
//   Out (GREEN) |   pin 5
//   GND (BLUE)  |    GND

// Pins
const int LIQUID_SENSOR_PIN = 5;

void setup() { 
  Serial.begin(9600);
  pinMode(LIQUID_SENSOR_PIN, INPUT);
}

void loop() {

  // Read sensor and print the value. If liquid touches the tip, the sensor will 
  // read 0. If dry, the outpus is 1.
  int isDry = digitalRead(LIQUID_SENSOR_PIN);
  Serial.println(isDry);

  delay(200);
}
