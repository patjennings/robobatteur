#include <Servo.h>

Servo myservo1, myservo2;  // on crée les deux servos
int const potPin = A0; // le potard
int potVal; // la valeur récupérée du potard
int tempoDelay; // la valeur qui sera controlée par le potard
int value;

void setup()
{
  Serial.begin(9600);

  myservo1.attach(6, 500, 1000);
  myservo1.write(0);
  myservo2.attach(7);
  myservo2.write(170);

  value = 0;
}

void loop() {
//  potVal = analogRead(potPin);
//  Serial.println("potval :");
//  Serial.print(potVal);  
//  tempoDelay = map(potVal, 0, 1023, 700, 125);7
  

//   caisse claire
  myservo2.write(240); // la baguette s'abaisse
  delay(120);
  myservo2.write(170);  // la baguette se relève
  delay(100);

//  // kick
//  myservo2.write(0);  // la baguette s'abaisse
//  delay(20);
//  myservo2.write(60); // la baguette se relève
//  delay(100);
}
