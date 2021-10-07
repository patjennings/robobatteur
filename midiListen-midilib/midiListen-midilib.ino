#include <MIDI.h>  // Add Midi Library
#include <Servo.h> // Add servo lib

#define LED 13    // Arduino Board LED is on Pin 13
Servo srvKick1, srvKick2, srvSnare1, srvSnare2, srvHh1, srvHh2, srvMisc1, srvMisc2;  // on crée les servos
int initPos[] = {160, 160, 95, 101, 45, 43, 85, 85}; // position initiale des servos, dans l'ordre de déclaration présent ci-avant

int rotationAngle = 45; // coefficient de rotation#1

//int initPos[] = {70, 70, 95, 98, 75, 70, 85, 85}; // test hh remplace kick
boolean toggleSnare = true;
boolean toggleHH = true;
boolean toggleKick = true;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  pinMode (LED, OUTPUT);
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(MyHandleNoteOn);
  MIDI.setHandleNoteOff(MyHandleNoteOff);
  Serial.begin(31250);


  // sorties 1 & 2
  srvKick1.attach(11); // kick 1
  srvKick1.write(initPos[0]);

  srvKick2.attach(10); // kick 2
  srvKick2.write(initPos[1]);

  // sorties 3 & 4
  srvSnare1.attach(9); // snare 1
  srvSnare1.write(initPos[2]);
  
  srvSnare2.attach(8); // snare 2
  srvSnare2.write(initPos[3]);

  // sorties 5 & 6
  srvHh1.attach(7); // hh 1
  srvHh1.write(initPos[4]);
  
  srvHh2.attach(6); // hh 2
  srvHh2.write(initPos[5]);

  // sortie 7 
  srvMisc1.attach(5); // misc 1
  srvMisc1.write(initPos[6]);

  // sortie 8
  srvMisc2.attach(4); // misc 2
  srvMisc2.write(initPos[7]);
}

void loop() { // Main loop
  MIDI.read();
}

void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  digitalWrite(LED,HIGH);
  Serial.write("midi spotted");

  int rotAng = map(velocity, 0, 127, 35, 45);

  // c'est ici qu'on décide querlle note active quel moteur
  if(pitch == 36){  // DO 1
    hitKick();
  }
  if(pitch == 38){  // RE 1
    hitSnare(rotAng);
  }
  if(pitch == 42){  // FA#1
    hitHH();
  }
  if(pitch == 49){ // DO#2
    hitMisc1();
  }
  if(pitch == 51){ // RE#2
    hitMisc2();
  }
}
void hitKick(){
  if(toggleKick == true){
    srvKick1.write(initPos[0]-rotationAngle); // la baguette s'abaisse
    delay(40);
    srvKick1.write(initPos[0]);  // la baguette se relève
    toggleKick = false;
  } else {
    srvKick2.write(initPos[1]-rotationAngle); // la baguette s'abaisse
    delay(40);
    srvKick2.write(initPos[1]);  // la baguette se relève
    toggleKick = true;
  }  
  
}
void hitSnare(int ra){
  if(toggleSnare == true){
    srvSnare1.write(initPos[2]+ra); // la baguette s'abaisse
    delay(40);
    srvSnare1.write(initPos[2]);  // la baguette se relève
    toggleSnare = false;
  } 
  else {
    srvSnare2.write(initPos[3]+ra); // la baguette s'abaisse
    delay(40);
    srvSnare2.write(initPos[3]);  // la baguette se relève
    toggleSnare = true;
  }
}
void hitHH(){
  if(toggleHH == true){
    srvHh1.write(initPos[4]+rotationAngle); // la baguette s'abaisse
    delay(40);
    srvHh1.write(initPos[4]);  // la baguette se relève
    toggleHH = false;
  } else {
    srvHh2.write(initPos[5]+rotationAngle); // la baguette s'abaisse
    delay(40);
    srvHh2.write(initPos[5]);  // la baguette se relève
    toggleHH = true;
  }
}
void hitMisc1(){
  srvMisc1.write(initPos[6]+rotationAngle); // la baguette s'abaisse
  delay(40);
  srvMisc1.write(initPos[6]);  // la baguette se relève
}
void hitMisc2(){
  srvMisc2.write(initPos[7]+rotationAngle); // la baguette s'abaisse
  delay(40);
  srvMisc2.write(initPos[7]);  // la baguette se relève
}
void MyHandleNoteOff(byte channel, byte pitch, byte velocity) { 
  digitalWrite(LED,LOW);  //Turn LED off
}
