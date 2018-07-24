/**
 * { item_description }
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "motor_controller.h"

/**
 * @brief      Class which represents the robot as a whole.
 */
class Robot {
private:

	/**
	 * Instance of MotorController contained in the robot.
	 */
	MotorController motorController;

public:

	/**
	 * @brief      Default constructor.
	 */
	Robot();
};

#endif