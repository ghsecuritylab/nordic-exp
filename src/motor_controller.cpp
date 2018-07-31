#include "motor_controller.h"

MotorController::MotorController() {
	leftMotor = DC_Motor(Side::LEFT);
	//rightMotor = DC_Motor(RIGHT);
}

void MotorController::moveForward() {
	leftMotor.setDirection(Direction::FORWARD);
	leftMotor.setSpeed(50);
	//rightMotor.setDirection(FORWARD);
	//rightMotor.setSpeed(50);
}

void MotorController::stop() {
	leftMotor.setSpeed(0);
	//rightMotor.setSpeed(0);
}