const int sensorPin = A0; //Specify the pin to use

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float sensorVal = analogRead(sensorPin); //Read values from the sensor
  Serial.print("Sensor value: "); //Print the value
  Serial.println(sensorVal);
  delay(100);
}
