#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>

#include "defines.h"
#include "pwm.h"


class Motor {
private:
	
	static uint16_t initialDutyCycle;
	PWM pwm;
	const Location loc;
	const uint8_t INPUT_PIN_1;
	const uint8_t INPUT_PIN_2;

public:

	Motor();
	Motor(Location loc, uint8_t pin_1, uint8_t pin_2);

	void enable() 	{ pwm.play(); }
	void disable() 	{ pwm.stop(); }

	void setSpeed(uint8_t speed);
	//void setDirection(Direction dir);
};

#endif // MOTOR_H