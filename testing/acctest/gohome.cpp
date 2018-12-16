#include "funsion.h"




void gohome(AccelStepper motor, float speed) {

	long initial_homing;
	Serial.print("Steppers is Homing . . .");

//X homing
	initial_homing = 0;

	while (!digitalRead(X_HOM_PIN)) {
		motor.moveTo(initial_homing);
		motor.run();
		initial_homing--;
		delay(5);
	}

	motor.setCurrentPosition(0);
	initial_homing = 0;

	while (!digitalRead(X_HOM_PIN)) {
		motor.moveTo(initial_homing);
		motor.run();
		initial_homing++;
		delay(5);
	}

	Serial.println("Homing Completed\n");
	motor.setMaxSpeed(1000.0);
	motor.setAcceleration(1000.0);

// Print out Instructions on the Serial Monitor at Start
	Serial.println("Enter Travel distance (Positive for CW / Negative for CCW and Zero for back to Home): ");
}
