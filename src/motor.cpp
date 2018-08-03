#include "motor.h"

Motor::Motor() {
	enabled = false;
	side = Side::UNKNOWN;
	dutyCyclePtr = nullptr;
}

Motor::Motor(Side side) {
	enabled = false;
	this->side = side;
	dutyCyclePtr = nullptr;
}

Motor::Motor(uint16_t *dutyCyclePtr) {
	enabled = false;
	side = Side::UNKNOWN;
	this->dutyCyclePtr = dutyCyclePtr;
}

/*
void Motor::enable() {
	enabled = true;
}

void Motor::disable() {
	enabled = false;
}
*/