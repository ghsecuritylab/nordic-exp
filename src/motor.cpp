#include "motor.h"

Motor::Motor() {
  direction = NEUTRAL;
}

Motor::Motor(uint8_t dir) {
  direction = dir;
}

void Motor::setDirection(uint8_t dir) {
  direction = dir;
}