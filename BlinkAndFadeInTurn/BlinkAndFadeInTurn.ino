
//This sketch turns 5 LEDs on and fades them out in turn

int Pins[5] = {3,5,6,9,11}; //Specify the pins to use
//3=blue, 5=green, 6=yellow, 9=red, 11=white

const int brightness=255; //Set starting brightness level for LEDs (0-255)
const float fadeSpeed=1000; //Set duration the entire fade should last in ms
const long intervalDelay=200; //Set the duration in ms of the interval to wait between LEDs
const int repetitions=3; //Set number of times the sequence should run

void setup() {
  float fadeDelay=1.0/(brightness/fadeSpeed); //Calculate the delay between each fade step

  //Loop through pins to set them as output and off
  for(int i=0; i<5; i++){
  pinMode(Pins[i],OUTPUT);
  digitalWrite(Pins[i],LOW);
  }
  
  //For each repetition...
  for (int n=0; n<repetitions; n++){
    
    //...loop through the pins...
    for(int i=0; i<5; i++){
    
    //...to turn each pin on (to the brightness level specified), 
    //and then fade it off with a delay between each fade step 
      for (int j=brightness; j>0; j--){
        analogWrite(Pins[i],j);
        delay(fadeDelay);
      } 

    //Turn LED off 
    analogWrite(Pins[i],0);

    //Introduce a delay before continuing to the next LED
    unsigned long currentMillis = millis(); //Save the current time
    unsigned long nextEvent = currentMillis+intervalDelay; //Save the time at which to continue
    
    while (millis()<nextEvent); //Unless the current time has reached the nextEvent time, the code stays here
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
