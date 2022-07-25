// Include the library
#include <Servo.h>

// Create the servo object
Servo myservo;
int servoPinOut = 5;

// Setup section to run once
void setup() {
  myservo.attach(servoPinOut); // attach the servo to our servo object
  //Serial.begin(9600);
  myservo.write(90); 
}

// Loop to keep the motor turning!
void loop() {
  //analogWrite(analogOutPin, outputValue);
  myservo.write(65); // rotate the motor counterclockwise
  //analogWrite(2, 240);
  delay(8000); // keep rotating for 5 seconds (5000 milliseconds)
  //analogWrite(2, 0);
  myservo.write(90); // stop the motor
  //analogWrite(1, 200);
  delay(5000); // stay stopped
  //analogWrite(1, 0);
  myservo.write(115); // rotate the motor clockwise
  //analogWrite(0, 200);
  delay(8000); // keep rotating :D
  //analogWrite(0, 0);
}
