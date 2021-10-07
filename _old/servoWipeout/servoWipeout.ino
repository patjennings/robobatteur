/* #include "servo.h" */
#include <Servo.h>
// servo drummer Jim Demello June 2018
Servo myservo1,myservo2;
int servoPin1 = 6; //servo
int servoPin2 = 7;

void myServo(int servoPosition, int servoNumber) {
  if (servoNumber == 1) {
    myservo1.write(servoPosition);
  }
  if (servoNumber == 2) {
    myservo2.write(servoPosition);
  }
}
void doOneEighthNote(int servoNumber,int beat) {
  int delayVal = 60;
  if (servoNumber == 1) {
    /* if (beat) { */
    /*   beat = 10; // if beat = 1 then add a little more servo down for stronger thump */
    /* }  */
    myServo(20 + beat,servoNumber); //down
    delay(delayVal);
    myServo(0,servoNumber);//up
    delay(delayVal);
  }
//  if (servoNumber == 2) {
//    if (beat) beat = -10;
//    myServo(30 + beat,servoNumber); //down
//    delay(delayVal);
//    myServo(0,servoNumber);//up
//    delay(delayVal);
//  }
}
void setup()
{
  // Serial.begin(9600);
  /* myservo1.attach(servoPin1, 1000, 2000);  */
  /* myservo1.write(300); */
  /* myservo2.attach(servoPin2, 1000, 2000);  */
  /* myservo2.write(0); */

  myservo1.attach(servoPin1, 500, 1250); 
  myservo1.write(0);
  myservo2.attach(servoPin2, 1250, 2250); 
  myservo2.write(0);
}

void wipeout() {
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0); // first parm is servo number and second parm is beat (1=beat, 0=no beat)
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,0); doOneEighthNote(1,0); doOneEighthNote(2,1); doOneEighthNote(1,0);
  doOneEighthNote(2,0); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,1); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
  doOneEighthNote(2,0); doOneEighthNote(1,0); doOneEighthNote(2,1); doOneEighthNote(1,0);
  doOneEighthNote(2,0); doOneEighthNote(1,0); doOneEighthNote(2,1); doOneEighthNote(1,0);
  doOneEighthNote(2,0); doOneEighthNote(1,0); doOneEighthNote(2,0); doOneEighthNote(1,0);
}
void loop() {
//  wipeout(); // wipeout drum routine
  doOneEighthNote(1,1);

  myServo(20 + beat,servoNumber); //down
  delay(delayVal);
  myServo(0,servoNumber);//up
  delay(delayVal);
  /* delay(50); */
  /* myservo1.write(0); */
  /* delay(10); */
  /* myservo1.write(10); */
}
