#include "botcon.h"

struct stepmotor{
char AIX;
int PUL; //define Pulse pin
int DIR; //define Direction pin
int ENA; //define Enable Pin
int stp;
};
int i, j=0;

  
void move(struct stepmotor sm[]){

      for (i = 0; i < 5; i++){
        Serial.print(sm[i].AIX);
        Serial.print(sm[i].stp);
        Serial.println("\t");

        if (sm[i].PUL >= 0) {
          digitalWrite(sm[i].DIR, HIGH);
        } else {
          digitalWrite(sm[i].DIR, LOW);
          sm[i].stp *= -1;
        }
      }
      while(!(j)){
        j = 1;
        for (i = 0; i < 5; i++) //Forward 5000 steps
        {
          if(sm[i].stp != 0){
            digitalWrite(sm[i].PUL, HIGH);
            delayMicroseconds(200);
            digitalWrite(sm[i].PUL, LOW);
            delayMicroseconds(200);
            sm[i].stp --;
            j = 0;
            Serial.print(sm[i].AIX);
            Serial.println(sm[i].stp);
          }
        }
      }
}
