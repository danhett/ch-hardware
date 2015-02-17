/**
 * CORNERHOUSE SCRIBBLER - Arduino sketch
 * This controller activates both the lights and motors for the Scribbler installation. 
 * Currently this logic is triggered by a python script called when printing.
 */

const int ledCount = 9;
const int confirmPin = 11; 
const int del = 100;
boolean isLighting = false;

//int ledPins[] = { 2, 3, 4, 5, 6, 7,8,9,10 }; // correct way round
int ledPins[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2 }; // backwards for installation! whoops. 


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
  
  Serial.begin(9600);
}


/**
 * LOOP
 */
void loop() 
{
  
  /*
  // loop over the LED array:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    } 
    // turn off all pins higher than the ledLevel:
    else {
      digitalWrite(ledPins[thisLed], LOW); 
    }
  }
  
  
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    digitalWrite(ledPins[thisLed], HIGH);
  }
  */
  
  /*
  digitalWrite(ledPins[0], HIGH);
  delay(1000);
  digitalWrite(ledPins[0], LOW);
  delay(1000);
  */
  
  //analogWrite(motorPin, 255);
  
  //killLights();
  

  if (Serial.available() > 0) 
  {
    //digitalWrite(ledPins[0], HIGH);
    
    int inByte = Serial.read();
    
    if(inByte == '1')
    {
      if(isLighting == false)
      {
        isLighting = true; 
        startLights();  
      } 
    }
  }

  /*
  if(isLighting == false)
  {
    isLighting = true; 
    startLights();  
  } 
  */
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
