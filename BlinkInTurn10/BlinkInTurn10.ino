
//This sketch turns 10 LEDs on and off in turn

int Pins[10] = {2,4,6,8,10,3,5,7,9,11}; //Specify the pins to use
//2,3=blue, 4,5=green, 6,7=yellow, 8,9=red, 10,11=white

const int brightness=255; //Set brightness level for LEDs (0-255) NOTE: CHANGING THIS VALUE FROM 255 WILL ONLY HAVE EFFECT ON LEDS ATTACHED TO PWM PINS (i.e. pins labelled ~)
const int durationON=500; //Set duration LED should be on for in ms
const long intervalDelay=500; //Set duration of the delay in ms between LED activations
const int repetitions=1; //Set number of times the sequence should run

void setup() {
  //Loop through pins to set them as output and off
    for(int i=0; i<10; i++){
    pinMode(Pins[i],OUTPUT);
    digitalWrite(Pins[i],LOW);
    }
  
  //For each repetition...
  for (int n=0; n<repetitions; n++){
    
    //...loop through the pins...
    for(int i=0; i<10; i++){ 
    
    //...to turn each pin on (to the brightness level specified), 
    //and then off after the specfied delay
    analogWrite(Pins[i],brightness);
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
