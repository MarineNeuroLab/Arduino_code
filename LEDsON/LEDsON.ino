// This sketch turns up tp 5 LEDs to max brightness and leaves them on

int Pins[5] = {3,5,6,9,11}; //Specify which pins to use
//3=blue, 5=green, 6=yellow, 9=red, 11=white

void setup() {
  //Loop through pins to set them as output and on
    for(int i=0; i<5; i++){
    pinMode(Pins[i],OUTPUT);
    digitalWrite(Pins[i],HIGH);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
