byte noteOn = 144;
int ledPin = 9;

byte noteToCheck = 60;

//light up led at pin 13 when receiving noteON message with note = 60

void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}   

void loop(){
  checkForNote();
  delay(10);
}

void checkForNote(){
  while (Serial.available()){//while there is serial data availble
    
    byte incomingByte = Serial.read();//read first byte

    
    if (incomingByte>127){//if a command byte
    
      if (incomingByte == noteOn){//if note on message
        Serial.print("note on | ");
        Serial.print(Serial.read());
        byte noteByte = Serial.read();//read next byte
        byte velocityByte = Serial.read();//read final byte


        if (noteByte == noteToCheck && velocityByte > 0){//note on
          int brightness = map(velocityByte, 0, 127, 0, 255);//map velocity to a number between 0 and 255
          analogWrite(ledPin,brightness);//turn on led w brightness relative to velocity
        }


        if (noteByte == noteToCheck && velocityByte == 0){//note off
          digitalWrite(ledPin,LOW);//turn off led
        }
      }
    }
  }
}
