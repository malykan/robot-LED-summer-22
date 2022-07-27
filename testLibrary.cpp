#include <Servo.h>
#include <Arduino.h>

void contractionRoutine(Servo &servoMotor1, Servo &servoMotor2, int windingTime, int restingTime, double unwindingRatio){
  servoMotor1.write(115); // (winding) rotate the motor clockwise
  servoMotor2.write(115); // (winding) rotate the motor clockwise
  delay(windingTime); // keep rotating :D
  
  servoMotor1.write(90); // stop the motor
  servoMotor2.write(90); // (unwinding) rotate the motor counterclockwise
  delay(restingTime); // stay stopped
  
  servoMotor1.write(65); // (unwinding) rotate the motor counterclockwise
  servoMotor2.write(65); // (unwinding) rotate the motor counterclockwise
  delay(int(double(windingTime)*unwindingRatio)); // keep rotating for 5 seconds (5000 milliseconds)
  
  servoMotor1.write(90); // stop the motor
  servoMotor2.write(90); // stop the motor
  delay(restingTime); // stay stopped
}

void turningRoutine(Servo &servoMotor, int windingTime, int restingTime, double unwindingRatio){
    //turn right 
  servoMotor.write(115); // (winding) rotate the motor clockwise
  delay(windingTime); // keep rotating :D

  servoMotor.write(90); // (unwinding) rotate the motor counterclockwise
  delay(restingTime); // stay stopped

  servoMotor.write(65); // (unwinding) rotate the motor counterclockwise
  delay(int(double(windingTime)*unwindingRatio)); // keep rotating for 5 seconds (5000 milliseconds)

  servoMotor.write(90); // stop the motor
  delay(restingTime); // stay stopped
}
