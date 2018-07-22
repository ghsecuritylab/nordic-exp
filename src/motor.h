#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>

enum Direction {
  FORWARD,
  BACKWARDS,
  NEUTRAL
};

class Motor {
  private:
	uint8_t direction;

  public:
	Motor();
	Motor(uint8_t dir);
	virtual void setDirection(uint8_t dir);
    virtual void setSpeed(uint8_t speed) = 0;
};

#endif