#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>

#include "defines.h"

/**
 * @brief      Abstract class which contains some properties that exist for all
 *             motor types, and some pure virtual functions representing
 *             functionality that is special for each one.
 */
class Motor {
private:

	Side side;
	uint16_t *dutyCyclePtr;

	/**
	 * Says if a motor is enabled or not.
	 */
	bool enabled;

public:

	/**
	 * @brief      Default constructor.
	 */
	Motor();
	Motor(Side side);
	Motor(uint16_t *dutyCyclePtr);

	/**
	 * @brief      Sets enabled to "true".
	 */
	//void enable();

	/**
	 * @brief      Sets enabled to "false".
	 */
	//void disable();

	/**
	 * @brief      Sets the rotation speed of the motor. Specific to each motor
	 *             type.
	 *
	 * @param[in]  speed  The speed
	 */
	virtual void setSpeed(uint8_t speed) = 0;

	/**
	 * @brief      Sets the rotation direction of the motor. Specific to each
	 *             motor type.
	 *
	 * @param[in]  direction  The direction
	 */
	virtual void setDirection(Direction dir) = 0;
};

#endif // MOTOR_H