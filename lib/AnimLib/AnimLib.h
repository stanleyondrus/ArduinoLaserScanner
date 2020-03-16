#ifndef ANIM_LIB_H
#define ANIM_LIB_H
#include <Arduino.h>
#include "../ScannerDriver/ScannerDriver.h"
#include "../LaserDriver/LaserDriver.h"

#define MAX_ANIM_POINTS 64

struct AnimPoint {
	uint16_t x;
	uint16_t y;
	uint8_t laser; // 0-OFF 1-ON
};

class AnimLib {
public:
	AnimLib(ScannerDriver& scanner_a, LaserDriver laser_a) : scanner(scanner_a), laser(laser_a) {}
	void init();
	AnimPoint anim[MAX_ANIM_POINTS];
	uint8_t add_anim_point(uint16_t x, uint16_t y, uint8_t laser);
	void start_anim();
	void stop_anim();
	void reset_anim();
	void update();
	void load_anim(uint8_t id);
	uint8_t mode = 0;
	uint8_t anim_id = 0;
private:
	ScannerDriver& scanner;
	LaserDriver& laser;
	uint16_t anim_count = 0; // animation count
	uint16_t anim_index = 0; // animation count
	uint8_t anim_running = 0;
};
#endif // ANIM_LIB_H
