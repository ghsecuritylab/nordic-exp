#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "dc_motor.h"
#include "pwm.h"
#include "defines.h"



/**
 * @brief      Provides control functionality for the contained motor objects.
 */
class MotorController {
private:

	/**
	 * Common instance of PWM-driver shared between the motors. Each motor is
	 * given one channel.
	 */
	PWM pwm;

	/**
	 * The motor for the left wheel.
	 */
	DC_Motor leftMotor;

	/**
	 * The motor for the right wheel.
	 */
	//DC_Motor rightMotor;

public:

	/**
	 * @brief      Default constructor.
	 */
	MotorController();

	/**
	 * @brief      Sets the speed of the left and right motors to a
	 *             percentage-value.
	 */
	void moveForward();

	void stop();
};

#endif // MOTOR_CONTROLLER_H