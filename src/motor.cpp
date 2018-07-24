#include "motor.h"

Motor::Motor() {
  enabled = false;
}

void Motor::enable() {
  enabled = true;
}

void Motor::disable() {
  enabled = false;
}