
//This sketch turns 4 LEDs on at the same time

int Pins[4] = {3,5,6,9}; //Specify the pins to use
//3=blue, 5=green, 6=yellow, 9=red

const int brightness=255; //Set brightness level for LEDs (0-255)
const int durationON=1000; //Set duration LED should be on for in ms
const int repetitions=10; //Set number of times the sequence should run
const long intervalDelay=15000; //Set duration of the delay in ms between repetitions

void setup() {
  //Loop through pins to set them as output and off
    for(int i=0; i<4; i++){
    pinMode(Pins[i],OUTPUT);
    digitalWrite(Pins[i],LOW);
    }
  
  //For each repetition...
  for (int n=0; n<repetitions; n++){
    
    //...to turn each pin on (to the brightness level specified), 
    //and then off after the specfied delay
    analogWrite(Pins[0],brightness);
    analogWrite(Pins[1],brightness);
    analogWrite(Pins[2],brightness);
    analogWrite(Pins[3],brightness);
    delay(durationON);
    analogWrite(Pins[0],0);
    analogWrite(Pins[1],0);
    analogWrite(Pins[2],0);
    analogWrite(Pins[3],0);

    //Introduce a delay before continuing to the next step in the loop
    unsigned long currentMillis = millis(); //Save the current time
    unsigned long nextEvent = currentMillis+intervalDelay; //Save the time at which to continue
    
    while (millis()<nextEvent); //Unless the current time has reached the nextEvent time, the code stays here
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
