
#include "main.h"

#define X_PUL_PIN   A0
#define X_DIR_PIN   A1
#define X_ENA_PIN   38
#define X_HOM_PIN   37

#define Y_PUL_PIN   A6
#define Y_DIR_PIN   A7
#define Y_ENA_PIN   A2
#define Y_HOM_PIN   22

#define Z_PUL_PIN   46
#define Z_DIR_PIN   48
#define Z_ENA_PIN   A8
#define Z_HOM_PIN   47

#define E_PUL_PIN   26
#define E_DIR_PIN   28
#define E_ENA_PIN   24
#define E_HOM_PIN   25

#define T_PUL_PIN   36
#define T_DIR_PIN   34
#define T_ENA_PIN   30
#define T_HOM_PIN   35

AccelStepper motorX(1, X_PUL_PIN, X_DIR_PIN);
AccelStepper motorY(1, Y_PUL_PIN, Y_DIR_PIN);
AccelStepper motorZ(1, Z_PUL_PIN, Z_DIR_PIN);
AccelStepper motorE(1, E_PUL_PIN, E_DIR_PIN);
AccelStepper motorT(1, T_PUL_PIN, T_DIR_PIN);

MultiStepper steppers;

int i, j, k;


void setup() {
  Serial.begin(115200);

  pinMode (X_HOM_PIN, INPUT_PULLUP);
  pinMode (Y_HOM_PIN, INPUT_PULLUP);
  pinMode (Z_HOM_PIN, INPUT_PULLUP);
  pinMode (E_HOM_PIN, INPUT_PULLUP);
  pinMode (T_HOM_PIN, INPUT_PULLUP);

  delay(5);
  motorX.setEnablePin(X_ENA_PIN);
  motorY.setEnablePin(Y_ENA_PIN);
  motorZ.setEnablePin(Z_ENA_PIN);
  motorE.setEnablePin(E_ENA_PIN);
  motorT.setEnablePin(T_ENA_PIN);

  motorX.enableOutputs ();
  motorY.enableOutputs ();
  motorZ.enableOutputs ();
  motorE.enableOutputs ();
  motorT.enableOutputs ();

  steppers.addStepper (motorX);
  steppers.addStepper (motorY);
  steppers.addStepper (motorZ);
  steppers.addStepper (motorE);
  steppers.addStepper (motorT);

  motorX.setMaxSpeed(100);
  motorY.setMaxSpeed(100);
  motorZ.setMaxSpeed(100);
  motorE.setMaxSpeed(100);
  motorT.setMaxSpeed(100);

  motorX.setAcceleration(100);
  motorY.setAcceleration(100);
  motorZ.setAcceleration(100);
  motorE.setAcceleration(100);
  motorT.setAcceleration(100);

  Serial.print("Steppers is Homing . . .");

  long initial_homing;
//X homing
  initial_homing = 0;

  while (!digitalRead(X_HOM_PIN)) {
    motorX.moveTo(initial_homing);
    motorX.run();
    initial_homing--;
    delay(5);
  }

  motorX.setCurrentPosition(0);
  initial_homing = 0;

  while (!digitalRead(X_HOM_PIN)) {
    motorX.moveTo(initial_homing);
    motorX.run();
    initial_homing++;
    delay(5);
  }

  Serial.println("Homing Completed\n");
  motorX.setMaxSpeed(1000.0);
  motorX.setAcceleration(1000.0);

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
