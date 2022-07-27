#include <Servo.h>
#include <Arduino.h>

void contractionRoutine(Servo &servoMotor1, Servo &servoMotor2, int windingTime, int restingTime, double unwindingRatio);
void turningRoutine(Servo &servoMotor, int windingTime, int restingTime, double unwindingRatio);
