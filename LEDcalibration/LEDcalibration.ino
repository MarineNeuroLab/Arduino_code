
//This sketch turns on 1 LED to a specified value and prints a value measured by a phototransistor (the sensor)

const int Pin=3; //LED pin in use
const int brightness=60; //Set brightness level for LED (0-255)

const int SensorPin=A0; //The pin the phototransistor is connected to
int SensorValue=0;

void setup() {
  // Set LED as output and off
    pinMode(Pin,OUTPUT);
    digitalWrite(Pin,LOW);

    // Start sensor reading
    Serial.begin(9600);

    //Turn LED on (to the brightness level specified), 
    analogWrite(Pin,brightness);
}


void loop() {
//Read the sensor value from the phototrasistor every 100 ms and print it in Serial Monitor
SensorValue = analogRead(SensorPin);
delay(100);

Serial.print("Sensor value is : ");
Serial.println(SensorValue);

}
