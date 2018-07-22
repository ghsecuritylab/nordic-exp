#ifndef ROBOT_H
#define ROBOT_H

#include "motor_controller.h"

class Robot {
  private:
	MotorController motorController;

  public:
	Robot();
};

#endif