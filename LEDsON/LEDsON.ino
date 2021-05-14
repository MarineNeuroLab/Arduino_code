// This sketch turns 4 LEDs to max brightness and leaves them on

int Pins[4] = {3,5,6,9}; //Specify the pins to use
//3=blue, 5=green, 6=yellow, 9=red

void setup() {
  //Loop through pins to set them as output and on
    for(int i=0; i<4; i++){
    pinMode(Pins[i],OUTPUT);
    digitalWrite(Pins[i],HIGH);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
