#ifndef LASER_DRIVER_H
#define LASER_DRIVER_H
#include <Arduino.h>

#define LASER_PIN 5

class LaserDriver {
public:
	void init();
	void turn_on();
	void turn_off();
	void set_intensity(uint16_t intensity);
	uint16_t get_intensity() {return laser_intensity;};
	uint8_t get_state() {return state;};
private:
	uint16_t laser_intensity = 1023;
	uint8_t state = 0;
};
#endif // LASER_DRIVER_H
