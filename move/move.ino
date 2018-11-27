
int PUL = A0; //define Pulse pin
int DIR = A1; //define Direction pin
int ENA = A2; //define Enable Pin
void setup() {
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
  // initialize serial:
  Serial.begin(9600);

}

void loop() {
  digitalWrite(ENA, HIGH);
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int red = Serial.parseInt();
    // do it again:

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      Serial.println(red);

      if (red >= 0) {
        digitalWrite(DIR, HIGH);
      } else {
        digitalWrite(DIR, LOW);
        red *= -1;
      }

      for (int i = 0; i < 1000; i++) //Forward 5000 steps
      {
        digitalWrite(PUL, HIGH);
        delayMicroseconds(200);
        digitalWrite(PUL, LOW);
        delayMicroseconds(200);
      }
    }
  }
}
