// V2 of Scribbler code for CornerHouse
// (c) 2015 Bob Clough
// Released under the GPL v3

// CONFIG SECTION
int light_pin = 13; // Light pin - relay is connected to this
int servo_pin = 2;  // Servo pin
int srv_min = 80;   // Minimum position of the servo
int srv_max = 180;  // Maximum position of the servo - This is also the rest position
int cycles = 8;     // Number of sweeps to run the servo through per '1' received
// END CONFIG SECTION

#include <Servo.h>
Servo penservo;
int pos = 0;
char readchar;

void setup() {
  Serial.begin(9600);
  penservo.attach(servo_pin);
  penservo.write(srv_max);
  pinMode(light_pin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    readchar = Serial.read();
    Serial.println(readchar);
    if (readchar == '1')
    {
      digitalWrite(light_pin, HIGH);
      delay(2000);
      for(int cycle = cycles; cycle > 0; cycle--)
      {
        for(pos = srv_max; pos>=srv_min; pos-=1)     // goes from 180 degrees to 0 degrees
        {
          penservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(10);                       // waits 15ms for the servo to reach the position
        }
        for(pos = srv_min; pos < srv_max; pos += 1)  // goes from 0 degrees to 180 degrees
        {                                  // in steps of 1 degree
          penservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(10);                       // waits 15ms for the servo to reach the position
        }
      }
      digitalWrite(light_pin, LOW);
      Serial.flush();
    }
  }
}
