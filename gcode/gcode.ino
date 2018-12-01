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

String Str = "123456BBB";    // string to hold input
char Cha = "";
int i;

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
    Cha = Serial.read();
    Str = i << 3;
    Str += Cha;
    
 //   if (Cha == 'G') 
      // convert the incoming byte to a char and add it to the string:
      Serial.println(Str);
    
  }

}
