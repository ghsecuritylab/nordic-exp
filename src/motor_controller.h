#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "motor.h"
#include "defines.h"



/**
 * @brief      Provides control functionality for the contained motor objects.
 */
class MotorController {
private:
	
	Motor leftMotor;
	Motor rightMotor;

public:

	/**
	 * @brief      Default constructor.
	 */
	MotorController();

};

#endif // MOTOR_CONTROLLER_H