/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground through 220 ohm resistor

  created 29 Dec. 2008
  modified 25 July 2022
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A1;  // Analog input pin that the potentiometer is attached to
int analogOutPin = 0; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)


//double sensor2Angle (double sensorValue);

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
   analogWrite(analogOutPin, 0);
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
 // outputValue = map(sensorValue, 400, 1023, 0, 255);
  double alpha = sensor2Angle(sensorValue);
  int lowerBound = 0;
  int upperBound = 0;
  LEDMapping(analogOutPin, lowerBound, upperBound, alpha);
  outputValue = map(alpha, lowerBound, upperBound, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);
  Serial.println("Angle ,LEDBrightness ");

  
  // print the results to the Serial Monitor:
  
//  Serial.print("sensor = ");
  //Serial.print(sensorValue);
  Serial.print(alpha);
//  Serial.print("\t output = ");
  Serial.print(",");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(50);
}

double sensor2Angle (double sensorValue){
  double alpha = PI*3/2;
  alpha = alpha*(1023/double(sensorValue) - 1);
  alpha = alpha*180/PI;
  return alpha;
}


void LEDMapping(int &analogOutPin, int &lowerBound, int &upperBound, double alpha){
//    if (alpha > 180){
//    outputValue = map(int(alpha),180,269,0,225);
//    analogOutPin=2;
//    
//  }
//  else{
//    if (alpha > 90){
//      outputValue = map(int(alpha),90,179,0,225);
//      analogOutPin=1;
//    }
//    else{
//      outputValue = map(int(alpha),0,89,0,225);
//      analogOutPin=0;
//    }      
//  }
  analogOutPin = int(alpha/90);
  analogOutPin = min(analogOutPin, 2);
  analogOutPin = max(analogOutPin, 0);

  lowerBound = 90*analogOutPin;
  upperBound = 90*(analogOutPin + 1);
  return;
}
