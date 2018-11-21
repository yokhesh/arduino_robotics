// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

// Two grippers

#include <AFMotor.h>

AF_DCMotor gripper1(1);
AF_DCMotor gripper2(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  // turn on motor
  gripper1.setSpeed(220);
  gripper2.setSpeed(220);
   
  gripper1.run(RELEASE);
  gripper2.run(RELEASE);
}

void loop() {
  char c = ' ';

  
 // Gripper 1
  if (Serial.available()) {
    c  = Serial.read();
    if (c == 'q') {
      gripper1.run(FORWARD);
      delay(1000);
      gripper1.run(RELEASE);
      Serial.println("Close gripper 1!");
    }
    if (c == 'w') {
      gripper1.run(BACKWARD);
      delay(1000);
      gripper1.run(RELEASE);
      Serial.println("Open gripper 1!");
    }

 // Gripper 2
    
    if (c == 'a') {
      gripper2.run(FORWARD);
      delay(1000);
      gripper2.run(RELEASE);
      Serial.println("Close gripper 2!");
    }
    if (c == 's') {
      gripper2.run(BACKWARD);
      delay(1000);
      gripper2.run(RELEASE);
      Serial.println("Open gripper 2!");
    }
    }
 }

 
