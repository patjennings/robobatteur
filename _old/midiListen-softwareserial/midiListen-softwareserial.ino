#include <SoftwareSerial.h>
#include <Servo.h>

const byte rxPin = 0;
const byte txPin = 10; // not used for the moment

SoftwareSerial mySerial(rxPin, txPin);

Servo myservo1, myservo2;  // on crée les deux servos


// SETUP ///////////////////////////////////////////
void setup()
{
  pinMode( rxPin, INPUT );
  pinMode( txPin, OUTPUT);
  mySerial.begin( 31250 );

  Serial.begin( 9600 );

  myservo1.attach(6);
  myservo1.write(150);
//  myservo2.attach(7);
//  myservo2.write(170);
}


// LOOP ////////////////////////////////////////////
void loop()
{
  while ( mySerial.available() > 0 )
  {
    unsigned char c = mySerial.read();
    Serial.println( c, DEC );

    if (c == 153) {
      Serial.println("kick");
    }
    if (c == 154) {
      Serial.println("snare");
      myservo1.write(240); // la baguette s'abaisse
      delay(60);
      myservo1.write(150);  // la baguette se relève
      delay(100);
    }
  }
}
