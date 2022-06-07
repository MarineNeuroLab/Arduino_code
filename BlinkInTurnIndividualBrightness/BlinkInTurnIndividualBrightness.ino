
//This sketch turns 5 LEDs on and off in turn

int Pins[5] = {3,5,6,9,11}; //Specify the pins to use
//3=blue, 5=green, 6=yellow, 9=red, 11=white

int brightness[5] = {75,24,40,130,70}; //Specify which brightness to use for each LED
const int durationON=5000; //Set duration LED should be on for in ms
const long intervalDelay=30000; //Set duration of the delay in ms between LED activations
const int repetitions=1; //Set number of times the sequence should run

void setup() {
  //Loop through pins to set them as output and off
    for(int i=0; i<5; i++){
    pinMode(Pins[i],OUTPUT);
    analogWrite(Pins[i],0);
    }
  
  //For each repetition...
  for (int n=0; n<repetitions; n++){
    
    //...loop through the pins...
    for(int i=0; i<5; i++){ 
    
    //...to turn each pin on (to the brightness level specified), 
    //and then off after the specfied delay
    analogWrite(Pins[i],brightness[i]);
    //delay(durationON);
    unsigned long currentMillis = millis(); //Save the current time
    unsigned long OffTime = currentMillis+durationON; //Save the time at which to turn off the LED
    while (millis()<OffTime); //Unless the current time has reached the OffTime, the code stays here
    analogWrite(Pins[i],0);

    //Introduce a delay before continuing to the next step in the loop
    unsigned long currentMillis2 = millis(); //Save the current time
    unsigned long nextEvent = currentMillis2+intervalDelay; //Save the time at which to continue
    
    while (millis()<nextEvent); //Unless the current time has reached the nextEvent time, the code stays here
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
