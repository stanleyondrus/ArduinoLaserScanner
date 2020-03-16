#include "ScannerDriver.h"

BasicStepperDriver stepperX(MOTOR_STEPS, DIR_X, STEP_X);
BasicStepperDriver stepperY(MOTOR_STEPS, DIR_Y, STEP_Y);

//MultiDriver controller(stepperX, stepperY);
SyncDriver controller(stepperX, stepperY);

void ScannerDriver::init() {
	pinMode(EN_X, OUTPUT);
	pinMode(EN_Y, OUTPUT);
	digitalWrite(EN_X, HIGH);
	digitalWrite(EN_Y, HIGH);
	stepperX.begin(MOTOR_RPM, MICROSTEPS);
	stepperY.begin(MOTOR_RPM, MICROSTEPS);
}

void ScannerDriver::move(uint16_t x, uint16_t y) {
	int16_t to_move_x = ((x <= POS_X_MIN) ? POS_X_MIN : (x >= POS_X_MAX) ? POS_X_MAX : x) - pos_x;
	int16_t to_move_y = ((y <= POS_Y_MIN) ? POS_Y_MIN : (y >= POS_Y_MAX) ? POS_Y_MAX : y) - pos_y;
	//	Serial.print(to_move_x);
	//	Serial.print("\t");
	//	Serial.println(to_move_y);
	controller.move(to_move_x * MICROSTEPS, to_move_y * MICROSTEPS);
	pos_x = x;
	pos_y = y;
}

uint8_t ScannerDriver::home() {
	// perform homing
	if (true) {
		setHome();
		return 0;
	}
	return 1;
}

void  ScannerDriver::setHome() {
	pos_x = 0;
	pos_y = 0;
}

void ScannerDriver::enable() {
	digitalWrite(EN_X, LOW);
	digitalWrite(EN_Y, LOW);
}

void ScannerDriver::disable() {
	digitalWrite(EN_X, HIGH);
	digitalWrite(EN_Y, HIGH);
}

void ScannerDriver::setSpeed(uint16_t s) {
	stepperX.setRPM(s);
	stepperY.setRPM(s);
	speed = s;
}
