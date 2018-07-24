#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include <stdint.h>

#include "motor.h"

class DC_Motor : public Motor {
private:
	uint8_t speed;
	uint8_t direction;

public:
	DC_Motor();
	void setSpeed(uint8_t speed);
	void setDirection(uint8_t direction);
};

#endif