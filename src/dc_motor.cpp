#include "dc_motor.h"

DC_Motor::DC_Motor() {
	speed = 0;
	direction = 0;
	pwm = PWM();
}

void DC_Motor::setSpeed(uint8_t speed) {
	this->speed = speed;
}

void DC_Motor::setDirection(uint8_t direction) {
	this->direction = direction;
}