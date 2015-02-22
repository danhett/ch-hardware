/**
 * CORNERHOUSE SCRIBBLER - Arduino sketch
 * This controller activates both the lights and motors for the Scribbler installation. 
 * Currently this logic is triggered by a python script called when printing.
 */

#include <Servo.h> 

const int ledCount = 9;
const int confirmPin = 11; 
const int del = 100;
boolean isLighting = false;

//int ledPins[] = { 2, 3, 4, 5, 6, 7,8,9,10 }; // correct way round
int ledPins[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2 }; // backwards for installation! whoops. 

Servo myservo;
int pos = 0;
int servoSpeed = 6;

/**
 * SETUP
 */
void setup() 
{
  for (int thisLed = 0; thisLed < ledCount; thisLed++) 
  {
    pinMode(ledPins[thisLed], OUTPUT); 
  }
  
  pinMode(confirmPin, OUTPUT);
  digitalWrite(confirmPin, HIGH);
  
  myservo.attach(13);
  
  Serial.begin(9600);
}


/**
 * LOOP
 */
void loop() 
{
  
  if(isLighting == false)
  {
    if (Serial.available() > 0) 
    {
        int inByte = Serial.read();
      
        if(inByte == '1')
        {
            isLighting = true; 
            startLights();
        } 

    }  
  }
  
  for(pos = 0; pos < 180; pos += servoSpeed)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-= servoSpeed)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}


/**
 * LIGHT ACTIVATION
 */
void startLights()
{
  digitalWrite(confirmPin, LOW);
  
  // simple left to right example
  digitalWrite(ledPins[0], HIGH);
  delay(del);
  digitalWrite(ledPins[1], HIGH);
  delay(del);
  digitalWrite(ledPins[2], HIGH);
  delay(del);
  digitalWrite(ledPins[3], HIGH);
  delay(del);
  digitalWrite(ledPins[4], HIGH);
  delay(del);
  digitalWrite(ledPins[5], HIGH);
  delay(del);
  digitalWrite(ledPins[6], HIGH);
  delay(del);
  digitalWrite(ledPins[7], HIGH);
  delay(del);
  digitalWrite(ledPins[8], HIGH);
  delay(del);
  digitalWrite(ledPins[9], HIGH);
  delay(del);
  
  delay(100);
  
  // and off again
  digitalWrite(ledPins[0], LOW);
  delay(del);
  digitalWrite(ledPins[1], LOW);
  delay(del);
  digitalWrite(ledPins[2], LOW);
  delay(del);
  digitalWrite(ledPins[3], LOW);
  delay(del);
  digitalWrite(ledPins[4], LOW);
  delay(del);
  digitalWrite(ledPins[5], LOW);
  delay(del);
  digitalWrite(ledPins[6], LOW);
  delay(del);
  digitalWrite(ledPins[7], LOW);
  delay(del);
  digitalWrite(ledPins[8], LOW);
  delay(del);
  digitalWrite(ledPins[9], LOW);
  delay(del);
  
  delay(100);
  
  // flash the whole lot off and on a few times
  flashOn();
  delay(200);
  flashOff();
  delay(200);
  flashOn();
  delay(200);
  flashOff();
  delay(200);
  flashOn();
  delay(200);
  flashOff();
  
  delay(2000);
  
  resetLights();
}


/**
 * RESET LIGHTS
 * Turn everything off again, reset state
 */
void resetLights()
{ 
  for (int thisLed = 0; thisLed < ledCount; thisLed++) 
  {
     digitalWrite(ledPins[thisLed], LOW);
  }
  
  isLighting = false;
  
  digitalWrite(confirmPin, HIGH);
}


/**
 * LIGHT EVERYTHING ON/OFF
 */
void flashOn()
{
  for (int thisLed = 0; thisLed < ledCount; thisLed++) 
  {
    digitalWrite(ledPins[thisLed], HIGH);
  }
}

void flashOff()
{
  for (int thisLed = 0; thisLed < ledCount; thisLed++) 
  {
    digitalWrite(ledPins[thisLed], LOW);
  }
}
