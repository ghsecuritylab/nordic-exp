#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>

enum {
	FORWARD,
	BACKWARDS,
	NEUTRAL
};

class Motor {
private:
	bool enabled;

public:
	Motor();
	void enable();
	void disable();
	virtual void setSpeed(uint8_t speed) = 0;
	virtual void setDirection(uint8_t direction) = 0;
};

#endif