#include "botcon.h"

struct stepmotor{
const char AIX;
const int PUL; //define Pulse pin
const int DIR; //define Direction pin
const int ENA; //define Enable Pin
int stp;
};
stepmotor sm[5] = {{'x',A0,A1,38,},{'y',A6,A7,A2,},{'z',46,48,A8,},{'e',26,28,24,},{'t',36,34,30,}};

void setup() {
  pinMode (sm[0].PUL, OUTPUT);
  pinMode (sm[0].DIR, OUTPUT);
  pinMode (sm[0].ENA, OUTPUT);
  pinMode (sm[1].PUL, OUTPUT);
  pinMode (sm[1].DIR, OUTPUT);
  pinMode (sm[1].ENA, OUTPUT);
  pinMode (sm[2].PUL, OUTPUT);
  pinMode (sm[2].DIR, OUTPUT);
  pinMode (sm[2].ENA, OUTPUT);
  pinMode (sm[3].PUL, OUTPUT);
  pinMode (sm[3].DIR, OUTPUT);
  pinMode (sm[3].ENA, OUTPUT);
  pinMode (sm[4].PUL, OUTPUT);
  pinMode (sm[4].DIR, OUTPUT);
  pinMode (sm[4].ENA, OUTPUT);
  // initialize serial:
  Serial.begin(9600);
  Serial.println("HELLOWORD!!!!!!!!!!!!!!!!!!!!");  
  digitalWrite(sm[0].ENA, HIGH);
  digitalWrite(sm[1].ENA, HIGH);
  digitalWrite(sm[2].ENA, HIGH);
  digitalWrite(sm[3].ENA, HIGH);
  digitalWrite(sm[4].ENA, HIGH);
}

void loop() {

  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    sm[0].stp = Serial.parseInt();
    // do it again:
    sm[1].stp = Serial.parseInt();
    sm[2].stp = Serial.parseInt();
    sm[3].stp = Serial.parseInt();
    sm[4].stp = Serial.parseInt();
    // look for the newlinsm[3]. That's the end of your sentence:
    if (Serial.read() == '\n') {
      move(sm);
    }
  }
}
