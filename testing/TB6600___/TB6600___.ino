int PUL=A0; //define Pulse pin
int DIR=A1; //define Direction pin
int ENA=38; //define Enable Pin
void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);

}

void loop() {
  for (int i=0; i<5000; i++)    //Forward 5000 steps
  {
    digitalWrite(DIR,LOW);
    digitalWrite(ENA,HIGH);
    digitalWrite(PUL,HIGH);
    delayMicroseconds(200);
    digitalWrite(PUL,LOW);
    delayMicroseconds(200);
  }
  for (int i=0; i<5000; i++)   //Backward 5000 steps
  {
    digitalWrite(DIR,HIGH);
    digitalWrite(ENA,HIGH);
    digitalWrite(PUL,HIGH);
    delayMicroseconds(200);
    digitalWrite(PUL,LOW);
    delayMicroseconds(200);
  }
}
