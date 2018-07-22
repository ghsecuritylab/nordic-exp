#include "dc_motor.h"

DC_Motor::DC_Motor() {
  speed = 0;
}

void DC_Motor::setSpeed(uint8_t speed) {
  this->speed = speed;
}