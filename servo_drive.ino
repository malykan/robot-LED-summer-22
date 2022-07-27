// Include the library
#include <Servo.h>
#include "testLibrary.h"

#define N 6000 //just for define syntax example
// Create the servo object
Servo servoLeft;
int servoPinOutLeft = 4;

Servo servoRight;
int servoPinOutRight = 5;

const int windingTime =2600; // milliseconds
const int restingTime = 1500; // milliseconds 
const double unwindingRatio = 0.72;
// Setup section to run once
void setup() {
  servoLeft.attach(servoPinOutLeft); // attach the servo to our servo object
  servoRight.attach(servoPinOutRight); // attach the servo to our servo object

  //Serial.begin(9600);
  servoLeft.write(90); 
}

// Loop to keep the motor turning!
void loop() {
  turningRoutine(servoLeft, windingTime, restingTime, unwindingRatio);
  turningRoutine(servoRight, windingTime, restingTime, unwindingRatio);
  contractionRoutine(servoLeft, servoRight, windingTime, restingTime, unwindingRatio);
}
