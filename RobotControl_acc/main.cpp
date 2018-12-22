
#include "main.h"

AccelStepper motorX(1, X_PUL_PIN, X_DIR_PIN);
AccelStepper motorY(1, Y_PUL_PIN, Y_DIR_PIN);
AccelStepper motorZ(1, Z_PUL_PIN, Z_DIR_PIN);
AccelStepper motorE(1, E_PUL_PIN, E_DIR_PIN);
AccelStepper motorT(1, T_PUL_PIN, T_DIR_PIN);

MultiStepper steppers;

struct stepmotor {
  const char AIX;
  const int MAXI, QDEG;
  long pos, deg;
};
stepmotor sm[5] = {
  {'X', 8000, 7000, 0, 0},
  {'Y', 3000, 1500, 0, 0},
  {'Z', 6000, 4000, 0, 0},
  {'E', 10000, 10000, 0, 0},
  {'T', 10000, 8000, 0, 0}
};

int i, j, k;


void setup() {
  Serial.begin(115200);

  pinMode(X_PUL_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENA_PIN, OUTPUT);
  pinMode(X_HOM_PIN, INPUT_PULLUP);

  pinMode(Y_PUL_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENA_PIN, OUTPUT);
  pinMode(Y_HOM_PIN, INPUT_PULLUP);

  pinMode(Z_PUL_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENA_PIN, OUTPUT);
  pinMode(Z_HOM_PIN, INPUT_PULLUP);

  pinMode(E_PUL_PIN, OUTPUT);
  pinMode(E_DIR_PIN, OUTPUT);
  pinMode(E_ENA_PIN, OUTPUT);
  pinMode(E_HOM_PIN, INPUT_PULLUP);

  pinMode(T_PUL_PIN, OUTPUT);
  pinMode(T_DIR_PIN, OUTPUT);
  pinMode(T_ENA_PIN, OUTPUT);
  pinMode(T_HOM_PIN, INPUT_PULLUP);

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

  motorX.setMinPulseWidth(20);
  motorY.setMinPulseWidth(20);
  motorZ.setMinPulseWidth(20);
  motorE.setMinPulseWidth(20);
  motorT.setMinPulseWidth(20);

  motorX.setMaxSpeed(500);
  motorY.setMaxSpeed(500);
  motorZ.setMaxSpeed(500);
  motorE.setMaxSpeed(500);
  motorT.setMaxSpeed(500);

  motorX.setAcceleration(100);
  motorY.setAcceleration(100);
  motorZ.setAcceleration(2000);
  motorE.setAcceleration(100);
  motorT.setAcceleration(100);

  Serial.println("Steppers is Homing . . .");



  Serial.println("Ready...Enter X Y Z E T");

}

void loop() {
  long positions[5]; // Array of desired stepper positions

  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    /*  for (i = 0; i < 5; i++) {
        sm[i].pos = Serial.parseInt();
      }*/
    // do it again:
    for (i = 0; i < 5; i++) {
      sm[i].deg = Serial.parseFloat();
      sm[i].pos = map((int)(sm[i].deg * 100), 0, 90 * 100, 0, sm[i].QDEG);
    }

    // look for the newlinsm[3]. That's the end of your sentence:
    if (Serial.read() == '\n') {

      Serial.print("NowStPos: ");
      for (i = 0; i < 5; i++) {
        positions[i] = sm[i].pos;
        Serial.print(sm[i].AIX);
        Serial.print(sm[i].pos);
        Serial.print(" ");
      }
      Serial.println();
      Serial.print("NowDeg: ");
      for (i = 0; i < 5; i++) {
        Serial.print(sm[i].AIX);
        Serial.print(sm[i].deg);
        Serial.print(" ");
      }
      steppers.moveTo(positions);
      steppers.runSpeedToPosition(); // Blocks until all are in position
      delay(1);
      Serial.println("\n======MoveFinish=====");
    }
  }
}
