#include "motor_controller.h"

MotorController::MotorController() {
	leftMotor = DC_Motor();
	rightMotor = DC_Motor();
}