#include "botcon.h"

struct stepmotor {
  const char AIX;
  const int PUL; //define Pulse pin
  const int DIR; //define Direction pin
  const int ENA; //define Enable Pin
  const long MAXI;
  long now, stp;
};

void move(struct stepmotor sm[], int spe) {
  int i, j = 0;
  
  Serial.print("move:");
  for (i = 0; i < 5; i++) {
    Serial.print(sm[i].AIX);
    Serial.print(sm[i].now);
    Serial.print(" ");
    if (sm[i].stp >= 0) {
      digitalWrite(sm[i].DIR, HIGH);
    } else {
      digitalWrite(sm[i].DIR, LOW);
      sm[i].stp *= -1;
    }
  }
  Serial.println();
  while (!(j)) {
    j = 1;
    for (i = 0; i < 5; i++) //Forward 5000 steps
    {
      if (sm[i].stp != 0) {
        digitalWrite(sm[i].PUL, HIGH);
        delayMicroseconds(spe);
        digitalWrite(sm[i].PUL, LOW);
        delayMicroseconds(spe);
        sm[i].stp --;
        j = 0;
        Serial.print(sm[i].AIX);
        Serial.print(sm[i].stp);
        Serial.print(" ");
      }
    } Serial.println();
  }
}
