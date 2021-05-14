
// Motor settings
const int PinMotor=10 ; //The pin the vibration motor is connected to 
const int power=200; //Set power level for motor (0-255)

// LED settings
const int PinLED=9; //The pin the indicator LED is connected to 
const int brightness=500; //Set brightness of LED (0-255)

// Common settings
const long durationON=1000; //Set duration both motor and LED should be on for
const int repetitions=1; //Set number of repetitions
const long intervalDelay=1000; //Set delay between repetitions

void setup() {
  //Set pins to output and off
    pinMode(PinMotor,OUTPUT);
    digitalWrite(PinMotor,LOW);

    pinMode(PinLED,OUTPUT);
    digitalWrite(PinLED,LOW);
  
  //Loop through each repetition, turning motor and LED on 
  //and then off after the specfied delay
  for(int i=0; i<repetitions; i++){

    analogWrite(PinMotor,power);
    analogWrite(PinLED,brightness);
    delay(durationON);
    analogWrite(PinMotor,0);
    analogWrite(PinLED,0);

    //Introduce a delay before continuing to the next step in the loop
    unsigned long currentMillis = millis(); //Save the current time
    unsigned long nextEvent = currentMillis+intervalDelay; //Save the time at which to continue
    
    while (millis()<nextEvent); //Unless the current time has reached the nextEvent time, the code stays here
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
