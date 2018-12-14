
#include <AccelStepper.h>
#include <MultiStepper.h>

struct stepmotor {
  const char AIX;
  const int PUL; //define Pulse pin
  const int DIR; //define Direction pin
  const int ENA; //define Enable Pin
  const int MAXI, QDEG;
  float deg;
  int now;
  long prestp;
};
stepmotor sm[5] = {
  {'X', A0, A1, 38, 8000, 9000, 0, 0},
  {'Y', A6, A7, A2, 3000, 1500, 0, 0},
  {'Z', 46, 48, A8, 6000, 4000, 0, 0},
  {'E', 26, 28, 24, 10000, 10000, 0, 0},
  {'T', 36, 34, 30, 10000, 8000, 0, 0}
};


// EG X-Y position bed driven by 2 steppers
// Alas its not possible to build an array of these with different pins for each :-(
AccelStepper joint1(1, sm[0].PUL, sm[0].DIR);
AccelStepper joint2(1, sm[1].PUL, sm[1].DIR);
AccelStepper joint3(1, sm[2].PUL, sm[2].DIR);
AccelStepper joint4(1, sm[3].PUL, sm[3].DIR);
AccelStepper joint5(1, sm[4].PUL, sm[4].DIR);



// Up to 10 steppers can be handled as a group by MultiStepper
MultiStepper steppers;

int i, j, k;

void setup() {
  Serial.begin(115200);

  // Configure each stepper
  joint1.setMaxSpeed(200);
  joint2.setMaxSpeed(200);
  joint3.setMaxSpeed(200);
  joint4.setMaxSpeed(200);
  joint5.setMaxSpeed(200);


  // Then give them to MultiStepper to manage
  steppers.addStepper(joint1);
  steppers.addStepper(joint2);
  steppers.addStepper(joint3);
  steppers.addStepper(joint4);
  steppers.addStepper(joint5);

  for (i = 0; i < 5; i++) {
    pinMode (sm[i].ENA, OUTPUT);
    digitalWrite(sm[i].ENA, HIGH);
  }
}

void loop() {
  long positions[5]; // Array of desired stepper positions

  // Back of the envelope calculation for microsteps/revolution, where positions[i] is the number of steps (or microsteps).
  positions[0] = 2000; //4100 microsteps is 1/8 revolutions ----> 32800 microsteps/rev
  positions[1] = 2000; //2000 is 40/360 revolutions ---> 18000 microsteps/rev
  positions[2] = 2000; //4000 is 20/360 revolutions ---> 72000 microsteps/rev
  positions[3] = 2000; //820 is 1/4 revolution (200steps/revolution * 16microsteps/step (since microstepping) ~= 32800 microsteps/rev)
  positions[4] = 2000; //2000 is 50/360 revolution ---> 14400

  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  delay(1);

  // Move to a different coordinate
  positions[0] = 0;
  positions[1] = 0;
  positions[2] = 0;
  positions[3] = 0;
  positions[4] = 0;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition(); // Blocks until all are in position
  delay(1);
}
