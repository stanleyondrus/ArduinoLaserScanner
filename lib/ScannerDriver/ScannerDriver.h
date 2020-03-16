#ifndef SCANNER_DRIVER_H
#define SCANNER_DRIVER_H
#include <Arduino.h>
#include "../StepperDriver/BasicStepperDriver.h"
#include "../StepperDriver/MultiDriver.h"
#include "../StepperDriver/SyncDriver.h"

#define MOTOR_STEPS 200
#define MOTOR_RPM 300

#define DIR_X 4
#define STEP_X 0
#define EN_X 14

#define DIR_Y 12
#define STEP_Y 13
#define EN_Y 14

#define MICROSTEPS 1

#define POS_X_MIN 0
#define POS_X_MAX 1800
#define POS_Y_MIN 0
#define POS_Y_MAX 1800

class ScannerDriver {
public:
	void init();
	void move(uint16_t x, uint16_t y);
	uint8_t home();
	void setHome();
	void enable();
	void disable();
	void setSpeed(uint16_t s);
	uint16_t speed = MOTOR_RPM;
private:
	uint16_t pos_x = 0;
	uint16_t pos_y = 0;
};
#endif // SCANNER_DRIVER_H
