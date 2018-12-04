#include "main.h"

struct stepmotor {
  const char AIX;
  const int PUL; //define Pulse pin
  const int DIR; //define Direction pin
  const int ENA; //define Enable Pin
  const long MAXI;
  long now, stp;
};
stepmotor sm[5] = {
  {'X', A0, A1, 38, 8000, 0},
  {'Y', A6, A7, A2, 1500, 0},
  {'Z', 46, 48, A8, 6000, 0},
  {'E', 26, 28, 24, 20000, 0},
  {'T', 36, 34, 30, 10000, 0}
};

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
  digitalWrite(sm[0].ENA, HIGH);
  digitalWrite(sm[1].ENA, HIGH);
  digitalWrite(sm[2].ENA, HIGH);
  digitalWrite(sm[3].ENA, HIGH);
  digitalWrite(sm[4].ENA, HIGH);
  Serial.begin(115200);
  Serial.println("enter x y z e t\n");
}

void loop() {

  int i, j;
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
      for (i = 0; i < 5; i++) {
        if (sm[i].stp > sm[i].MAXI) {
          sm[i].stp = sm[i].MAXI;
        } else if (sm[i].stp < (sm[i].MAXI * -1)) {
          sm[i].stp = sm[i].MAXI * -1;
        }
        j = sm[i].stp;
        sm[i].stp = sm[i].stp - sm[i].now;
        sm[i].now = j;
      }
      move(sm, 200);
      Serial.print("now:");
      for (i = 0; i < 5; i++) {
        Serial.print(sm[i].AIX);
        Serial.print(sm[i].now);
        Serial.print(" ");
      }
      Serial.println();
    }
  }
}
