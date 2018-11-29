#include <Arduino.h>
#include <botcon.h>

void move(char Aix, int PUL, int DIR, int step){
      Serial.print(Aix);
      Serial.print(step);
      Serial.println("\t");

      if (PUL >= 0) {
        digitalWrite(DIR, HIGH);
      } else {
        digitalWrite(DIR, LOW);
        step *= -1;
      }

      for (int i = 0; i < step; i++) //Forward 5000 steps
      {
        digitalWrite(PUL, HIGH);
        delayMicroseconds(200);
        digitalWrite(PUL, LOW);
        delayMicroseconds(200);
      }
}
