#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include <stdint.h>

#include "motor.h"

class ServoMotor : public Motor {
private:
	uint8_t speed;

public:
	void setSpeed(uint8_t speed);
};

#endif