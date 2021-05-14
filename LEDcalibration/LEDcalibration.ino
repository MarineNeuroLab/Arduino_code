
const int Pin=3; //LED pin in use
const int brightness=60; //Set brightness level for LED (0-255)

const int SensorPin=A0;
int SensorValue=0;

void setup() {
  // Set LED as output and off
    pinMode(Pin,OUTPUT);
    digitalWrite(Pin,LOW);

    // Start sensor reading
    Serial.begin(9600);

    //Turn LED on (to the brightness level specified), 
    //and then off after the specfied delay
    analogWrite(Pin,brightness);
   
}



void loop() {
  // put your main code here, to run repeatedly:
SensorValue = analogRead(SensorPin);
delay(100);

Serial.print("Sensor value is : ");
Serial.println(SensorValue);

}
