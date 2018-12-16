
#include "main.h"



AccelStepper motorX(1, X_PUL_PIN, X_DIR_PIN);


MultiStepper steppers;

int i, j, k;


void setup() {
  Serial.begin(115200);

  pinMode (X_HOM_PIN, INPUT_PULLUP);


  delay(5);
  motorX.setEnablePin(X_ENA_PIN);
  steppers.addStepper (motorX);
  motorX.setMaxSpeed(2000);
  motorX.setSpeed(10);
  motorX.setAcceleration(1);


}

void loop() {
  for (i = 0; i < 5; i++) {
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
}
