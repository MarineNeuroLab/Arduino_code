
const int Pin=6; //Change depending on which LED to use 
//(3=blue, 5=green, 6=yellow, 9=red)
const int brightness=255; //Set brightness level for LED (0-255)
const int duration=500; //Set duration LED should be on for in ms
const int repetitions=10; //Set number of times the sequence should run
const int durationDelay=500; //Set delay between repetitions in ms

void setup() {
  // Loop through pins to set them as output and off
  for(int pinNumber=3; pinNumber<7; pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber,LOW);
    }

    //For each repetition...
    for (int n=0; n<repetitions; n++){
    //Turn LED on (to the brightness level specified), 
    //and then off after the specfied delay
    analogWrite(Pin,brightness);
    delay(duration);
    analogWrite(Pin,0);
    delay(durationDelay);
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
