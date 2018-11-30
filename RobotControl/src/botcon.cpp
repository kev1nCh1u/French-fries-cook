#include <Arduino.h>
#include <botcon.h>

struct stepmotor{
char AIX;
int PUL; //define Pulse pin
int DIR; //define Direction pin
int ENA; //define Enable Pin
int step;
};

void move(struct stepmotor sm[]){
  int i, j;
      for (i = 0; i < 5; i++){
        Serial.print(sm[i].AIX);
        Serial.print(sm[i].step);
        Serial.println("\t");

        if (sm[i].PUL >= 0) {
          digitalWrite(sm[i].DIR, HIGH);
        } else {
          digitalWrite(sm[i].DIR, LOW);
          sm[i].step *= -1;
        }
      }
      while(!j){
        j = 1;
        for (i = 0; i < 5; i++) //Forward 5000 steps
        {
          if(sm[i].step != 0){
            digitalWrite(sm[i].PUL, HIGH);
            delayMicroseconds(200);
            digitalWrite(sm[i].PUL, LOW);
            delayMicroseconds(200);
            sm[i].step --;
            j = 0;
          }
        }
      }
}
