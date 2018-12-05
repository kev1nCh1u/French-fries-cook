#include "botcon.h"

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

void move5(struct stepmotor sm[], int spe) {
  int i, j = 0;
  
  Serial.print("MoveTo: ");
  for (i = 0; i < 5; i++) {
    Serial.print(sm[i].AIX);
    Serial.print(sm[i].prestp);
    Serial.print(" ");
      
    if (sm[i].prestp > sm[i].MAXI) {
      sm[i].prestp = sm[i].MAXI;
    } 
    else if (sm[i].prestp < (sm[i].MAXI * -1)) {
        sm[i].prestp = sm[i].MAXI * -1;
    }
  }
  Serial.println();
  while (!(j)) {
    j = 1;
    Serial.print("Moving: ");
    for (i = 0; i < 5; i++) //Forward 5000 steps
    {
      if (sm[i].prestp != sm[i].now) {
        digitalWrite(sm[i].PUL, HIGH);
        delayMicroseconds(spe);
        digitalWrite(sm[i].PUL, LOW);
        delayMicroseconds(spe);
        if (sm[i].prestp >= sm[i].now){
          digitalWrite(sm[i].DIR, HIGH);
          sm[i].now ++;
        }
        else{
          digitalWrite(sm[i].DIR, LOW);
          sm[i].now --;
        }
        j = 0;
        Serial.print(sm[i].AIX);
        Serial.print(sm[i].now);
        Serial.print(" ");
      }
    } 
    Serial.println();
  }
  Serial.println();
}
