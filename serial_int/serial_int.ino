void setup() {
  // put your setup code here, to run once:
  // initialize serial:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    long red = Serial.parseInt();
    // do it again:

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      Serial.println(red);
    }
  }
}
