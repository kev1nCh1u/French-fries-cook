/*
  String to Integer conversion

  Reads a serial input string until it sees a newline, then converts the string
  to a number if the characters are digits.

  The circuit:
  - No external components needed.

  created 29 Nov 2010
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/StringToInt
*/

String str = "";    // string to hold input
char cha = "", pcha = "";
byte gs;
int incha, i;
int x, y, z, e, t;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  Serial.println("gcode test");
}

void loop() {
  // Read serial input:
  while (Serial.available() > 0) {
    cha = Serial.read();

    if (!(cha == '\n')) {
      str += cha;
      if (str == "G0 ") {
        if (cha == 'X' || x) {
          x = Serial.parseInt();
        }
      }
    } else {
      // convert the incoming byte to a char and add it to the string:
      i = atoi(str.c_str());
      Serial.println(x);
      str = "";
    }
  }
}
