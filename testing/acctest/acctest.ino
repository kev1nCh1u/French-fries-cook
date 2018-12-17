#include <SPI.h>
#include "AccelStepper.h"
#include <MultiStepper.h>


#define X_PUL_PIN   A0
#define X_DIR_PIN   A1
#define X_ENA_PIN   38
#define X_HOM_PIN   37


AccelStepper motorX(1, X_PUL_PIN, X_DIR_PIN);

int i = 0, j, k;


void setup() {
	Serial.begin(115200);
	pinMode (X_HOM_PIN, INPUT_PULLUP);
	delay(5);

	motorX.setMaxSpeed(500);
	motorX.setAcceleration(2000);

	Serial.println("Steppers is Homing . . .");

	long initial_homing;
//X homing
	initial_homing = 0;

	while (digitalRead(X_HOM_PIN)) {
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
	motorX.setCurrentPosition(200);

	Serial.println("Homing Completed\n");
	motorX.setMaxSpeed(1000.0);
	motorX.setAcceleration(1000.0);


}

void loop() {
	while (Serial.available() > 0) {

		float st = Serial.parseFloat();
		if (Serial.read() == '\n') {
			motorX.moveTo(st);
			motorX.runToPosition(); // Blocks until all are in position
			delay(100);
		}
	}
}
