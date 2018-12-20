#include "main.h"

struct stepmotor {
  const char AIX;
  const int PUL; //define Pulse pin
  const int DIR; //define Direction pin
  const int ENA; //define Enable Pin
  const int MAXI, QDEG;
  float deg;
  int now;
  long prestp;
};
stepmotor sm[5] = {
  {'X', A0, A1, 38, 8000, 7000, 0, 0},
  {'Y', A6, A7, A2, 3000, 1500, 0, 0},
  {'Z', 46, 48, A8, 6000, 4000, 0, 0},
  {'E', 26, 28, 24, 10000, 10000, 0, 0},
  {'T', 36, 34, 30, 10000, 8000, 0, 0}
};
int i, j;

void setup() {
  Serial.begin(115200);
  Serial.println("Enter X Y Z E T\n");
  Serial.print("Now: ");
  for (i = 0; i < 5; i++) {
    pinMode (sm[i].PUL, OUTPUT);
    pinMode (sm[i].DIR, OUTPUT);
    pinMode (sm[i].ENA, OUTPUT);
    digitalWrite(sm[i].ENA, HIGH);
    Serial.print(sm[i].AIX);
    Serial.print(sm[i].now);
    Serial.print(" ");
  }
  Serial.println();
}

void loop() {


  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
/*  for (i = 0; i < 5; i++) {
    sm[i].prestp = Serial.parseInt();
  }*/
    // do it again:
  for (i = 0; i < 5; i++) {
    sm[i].deg = Serial.parseFloat();
    sm[i].prestp = map((int)(sm[i].deg*100), 0, 90*100, 0, sm[i].QDEG);
  }
    // look for the newlinsm[3]. That's the end of your sentence:
    if (Serial.read() == '\n') {
      move5(sm, 200);
      Serial.print("Now: ");
      for (i = 0; i < 5; i++) {
        Serial.print(sm[i].AIX);
        Serial.print(sm[i].now);
        Serial.print(" ");
      }
      Serial.println();
      Serial.print("NowDeg: ");
      for (i = 0; i < 5; i++) {
        Serial.print(sm[i].AIX);
        Serial.print(sm[i].deg);
        Serial.print(" ");
      }
      Serial.println();

    }
  }
}
