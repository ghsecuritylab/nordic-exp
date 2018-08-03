#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include <stdint.h>

#include "motor.h"
#include "defines.h"
#include "pwm.h"

/**
 * @brief      Class for a DC-motor. Inherits and implements the virtual
 *             functions in the abstract Motor class.
 */
class DC_Motor : public Motor {
private:

	/**
	 * The speed of the motor.
	 */
	uint8_t speed;

	/**
	 * The direction of the motor.
	 */
	Direction direction;

public:

	/**
	 * Default constructor.
	 */
	DC_Motor();
	DC_Motor(uint16_t *dutyCyclePtr);
	DC_Motor(Side side);


	/**
	 * @brief      Sets the speed of the motor. Implements virtual function.
	 *
	 * @param[in]  speed  The speed
	 */
	void setSpeed(uint8_t speed);

	/**
	 * @brief      Spets the direction of the motor. Implements virtual function.
	 *
	 * @param[in]  direction  The direction
	 */
	void setDirection(Direction dir);
};

#endif // DC_MOTOR_H