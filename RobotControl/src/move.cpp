#include <Arduino.h>

struct stepmotor{
int PUL; //define Pulse pin
int DIR; //define Direction pin
int ENA; //define Enable Pin
int step;
};
stepmotor x = {A0,A1,38,};
stepmotor y = {A6,A7,A2,};
stepmotor z = {46,48,A8,};
stepmotor e = {26,28,24,};
stepmotor t = {36,34,30,};

void move(char Aix, int PUL, int DIR, int step);

void setup() {
  pinMode (x.PUL, OUTPUT);
  pinMode (x.DIR, OUTPUT);
  pinMode (x.ENA, OUTPUT);
  pinMode (y.PUL, OUTPUT);
  pinMode (y.DIR, OUTPUT);
  pinMode (y.ENA, OUTPUT);
  pinMode (z.PUL, OUTPUT);
  pinMode (z.DIR, OUTPUT);
  pinMode (z.ENA, OUTPUT);
  pinMode (e.PUL, OUTPUT);
  pinMode (e.DIR, OUTPUT);
  pinMode (e.ENA, OUTPUT);
  pinMode (t.PUL, OUTPUT);
  pinMode (t.DIR, OUTPUT);
  pinMode (t.ENA, OUTPUT);
  // initialize serial:
  Serial.begin(9600);
}

void loop() {
  digitalWrite(x.ENA, HIGH);
  digitalWrite(y.ENA, HIGH);
  digitalWrite(z.ENA, HIGH);
  digitalWrite(e.ENA, HIGH);
  digitalWrite(t.ENA, HIGH);
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    x.step = Serial.parseInt();
    // do it again:
    y.step = Serial.parseInt();
    z.step = Serial.parseInt();
    e.step = Serial.parseInt();
    t.step = Serial.parseInt();
    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      move('x', x.PUL, x.DIR, x.step);
      move('y', y.PUL, y.DIR, y.step);
      move('z', z.PUL, z.DIR, z.step);
      move('e', e.PUL, e.DIR, e.step);
      move('t', t.PUL, t.DIR, t.step);
    }
  }
}

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
