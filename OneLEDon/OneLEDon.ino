// This sketch turns one LED on and leaves it on
const int pin = 11; //LED pin in use
const int brightness = 70; //Set brightness level for LED (0-255)

void setup() {
  // put your setup code here, to run once:
    pinMode(pin,OUTPUT);
    analogWrite(pin,brightness);

}

void loop() {
  // put your main code here, to run repeatedly:

}
