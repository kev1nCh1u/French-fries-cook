
#include <AccelStepper.h>
#include <MultiStepper.h>

#define X_PUL_PIN   A0
#define X_DIR_PIN   A1
#define X_ENA_PIN   38

#define Y_PUL_PIN   A6
#define Y_DIR_PIN   A7
#define Y_ENA_PIN   A2
#define Y_MIN_PIN   
#define Y_MAX_PIN   

#define Z_PUL_PIN   46
#define Z_DIR_PIN   48
#define Z_ENA_PIN   A8
#define Z_MIN_PIN   
#define Z_MAX_PIN   

#define E_PUL_PIN   26
#define E_DIR_PIN   26
#define E_ENA_PIN   24

#define T_PUL_PIN   36
#define T_DIR_PIN   34
#define T_ENA_PIN   30

// EG X-Y position bed driven by 2 steppers
// Alas its not possible to build an array of these with different pins for each :-(
AccelStepper motorx(1, X_PUL_PIN, X_DIR_PIN);
AccelStepper motory(1, Y_PUL_PIN, Y_DIR_PIN);
AccelStepper motorz(1, Z_PUL_PIN, Z_DIR_PIN);
AccelStepper motore(1, E_PUL_PIN, E_DIR_PIN);
AccelStepper motort(1, T_PUL_PIN, T_DIR_PIN);



// Up to 10 steppers can be handled as a group by MultiStepper
MultiStepper steppers;

int i, j, k;

void setup() {
  Serial.begin(115200);

  motorx.setMaxSpeed(200);
  motory.setMaxSpeed(200);
  motorz.setMaxSpeed(200);
  motore.setMaxSpeed(200);
  motort.setMaxSpeed(200);

  motorx.setAcceleration(200);
  motory.setAcceleration(200);
  motorz.setAcceleration(200);
  motore.setAcceleration(200);
  motort.setAcceleration(200);

  steppers.addStepper (motorx);
  steppers.addStepper (motory);
  steppers.addStepper (motorz);
  steppers.addStepper (motore);
  steppers.addStepper (motort);

  motorx.setEnablePin(X_ENA_PIN);
  motory.setEnablePin(Y_ENA_PIN);
  motorz.setEnablePin(Z_ENA_PIN);
  motore.setEnablePin(E_ENA_PIN);
  motort.setEnablePin(T_ENA_PIN);

  motorx.enableOutputs ();
  motory.enableOutputs ();
  motorz.enableOutputs ();
  motore.enableOutputs ();
  motort.enableOutputs ();

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
