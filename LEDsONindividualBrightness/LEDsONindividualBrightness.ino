// This sketch turns up tp 5 LEDs to a defined brightness level and leaves them on

int Pins[5] = {3,5,6,9,11}; //Specify which pins to use, 2,4,6,8
//3=blue, 5=green, 6=yellow, 9=red, 11=white
int brightness[5] = {255,40,65,115,85}; //Specify which brightness to use for each LED

void setup() {
  //Loop through pins to set them as output and on
    for(int i=0; i<5; i++){
    pinMode(Pins[i],OUTPUT);
    analogWrite(Pins[i],brightness[i]);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
