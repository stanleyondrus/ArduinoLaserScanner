#include "LaserDriver.h"

void LaserDriver::init() {
	pinMode(LASER_PIN, OUTPUT);
	digitalWrite(LASER_PIN, LOW);
}

void LaserDriver::turn_on() {
	analogWrite(LASER_PIN, laser_intensity);
	//digitalWrite(LASER_PIN, HIGH);
	state = 1;
}

void LaserDriver::turn_off() {
	digitalWrite(LASER_PIN, LOW);
	state = 0;
}

void LaserDriver::set_intensity(uint16_t intensity) {
	laser_intensity = intensity;
	if (state) turn_on();
}
