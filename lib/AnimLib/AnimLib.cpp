#include "AnimLib.h"

void AnimLib::init() {
	laser.init();
	scanner.init();
}

uint8_t AnimLib::add_anim_point(uint16_t x, uint16_t y, uint8_t laser) {
	if (anim_count+1 > MAX_ANIM_POINTS) return 1;
	AnimPoint p;
	p.x = x;
	p.y = y;
	p.laser = laser;
	anim[anim_count] = p;
	anim_count++;
	return 0;
}

void AnimLib::start_anim() {
	if (anim_count <= 0) return;
	anim_running = 1;
	scanner.enable();
}

void AnimLib::stop_anim() {
	anim_running = 0;
	scanner.disable();
	laser.turn_off();
}

void AnimLib::reset_anim() {
	anim_count = 0;
	anim_index = 0;
}

void AnimLib::update() {
	if (!anim_running) return;
	if (anim[anim_index].laser) laser.turn_on();
	scanner.move(anim[anim_index].x, anim[anim_index].y);
	anim_index = (anim_index + 1) % anim_count; // increment index counter with rollover
	if (!anim[anim_index].laser) laser.turn_off();
}

void AnimLib::load_anim(uint8_t id) {
	stop_anim();
	reset_anim();
	switch(id) {
	case 0:
		add_anim_point(0,0,1);
		add_anim_point(50,0,0);
		add_anim_point(50,50,1);
		add_anim_point(0,50,0);
		break;
	case 1:
		add_anim_point(0,0,1);
		add_anim_point(20,0,1);
		add_anim_point(20,20,1);
		add_anim_point(0,20,1);
		break;
	case 2:
		add_anim_point(0,0,1);
		add_anim_point(5,0,1);
		add_anim_point(5,5,1);
		add_anim_point(0,5,1);
		break;
	case 3:
		add_anim_point(0,0,1);
		add_anim_point(150,0,1);
		add_anim_point(150,150,1);
		add_anim_point(0,150,1);
		break;
	case 4:
		add_anim_point(0,0,0);

		add_anim_point(200,0,1);
		add_anim_point(200,200,1);
		add_anim_point(0,200,1);
		add_anim_point(0,0,1);

		add_anim_point(200,200,1);
		add_anim_point(200,0,0);
		add_anim_point(0,200,1);
		add_anim_point(0,200,0);
		break;
	}
	anim_id = id;
}
