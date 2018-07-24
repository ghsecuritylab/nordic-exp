#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "dc_motor.h"

class MotorController {
private:
	DC_Motor leftMotor;
	DC_Motor rightMotor;

public:
	MotorController();
};

#endif