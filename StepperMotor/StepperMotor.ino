// Based on example code from https://learn.adafruit.com/adafruit-drv8833-dc-stepper-motor-driver-breakout-board/stepper-motor-usage

// Include stepper motor library
#include <Stepper.h>

// Define the number of steps on the motor 
// (for the "Small Reduction Stepper Motor - 12VDC 32-Step 1/16 Gearing (Adafruit product ID 918)"
// this is 516.096 steps per revolution)
#define STEPS 516.096

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 4, 5, 6, 7);

void setup()
{
  stepper.setSpeed(5); //Set the speed (rounds per minute)
}

void loop()
{
  stepper.step(STEPS); //let the motor move constantly
}
