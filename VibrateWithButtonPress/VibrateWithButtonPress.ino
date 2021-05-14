
// Motor settings
const int PinMotor=10 ; //The pin the vibration motor is connected to 
const int power=255; //Set power level for motor (0-255)

// LED settings
const int PinLED=9; //The pin the indicator LED is connected to 
const int brightness=100; //Set brightness of LED (0-255)

// General settings
const int durationON=2000; //Set duration that the motor and LED should be on for

// Button settings
const int PinButton=2;
int buttonState;

void setup() { 
  //Set pins to output/input and off
    pinMode(PinMotor,OUTPUT);
    digitalWrite(PinMotor,LOW);

    pinMode(PinLED,OUTPUT);
    digitalWrite(PinLED,LOW);

    pinMode(PinButton,INPUT);
  }

void loop() {
  // Monitor whether or not button is pressed
  buttonState=digitalRead(PinButton);

  //If pressed, turn on motor and LED for specified duration
  if (buttonState==HIGH){
      analogWrite(PinMotor,power);
      analogWrite(PinLED,brightness);
      
      delay(durationON);
      
      analogWrite(PinMotor,0);
      analogWrite(PinLED,0);
  }
}
