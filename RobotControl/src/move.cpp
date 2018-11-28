#include <Arduino.h>

struct stepmotor{
int PUL; //define Pulse pin
int DIR; //define Direction pin
int ENA; //define Enable Pin
};
stepmotor x = {A0,A1,38};
stepmotor y = {A6,A7,A2};
stepmotor z = {A6,A7,A2};
stepmotor e = {A6,A7,A2};
stepmotor t = {A6,A7,A2};
void setup() {
  pinMode (x.PUL, OUTPUT);
  pinMode (x.DIR, OUTPUT);
  pinMode (x.ENA, OUTPUT);
  // initialize serial:
  Serial.begin(9600);

}

void loop() {

  digitalWrite(x.ENA, HIGH);
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int red = Serial.parseInt();
    // do it again:

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      Serial.println(red);

      if (red >= 0) {
        digitalWrite(x.DIR, HIGH);
      } else {
        digitalWrite(x.DIR, LOW);
        red *= -1;
      }

      for (int i = 0; i < 1000; i++) //Forward 5000 steps
      {
        digitalWrite(x.PUL, HIGH);
        delayMicroseconds(200);
        digitalWrite(x.PUL, LOW);
        delayMicroseconds(200);
      }
    }
  }
}
