#include "dc_motor.h"

#include "nrf_gpio.h"

DC_Motor::DC_Motor() {
	speed = 0;
	direction = Direction::NEUTRAL;

	// Initialize driver pins to be output
	nrf_gpio_cfg_output(MOTOR_PIN_0);
	nrf_gpio_cfg_output(MOTOR_PIN_1);

	// Set both pins low, motor is stopped
	nrf_gpio_pin_clear(MOTOR_PIN_0);
	nrf_gpio_pin_clear(MOTOR_PIN_1);
}

DC_Motor::DC_Motor(Side side) : Motor(side) {
	DC_Motor();
	switch (side) {
		case Side::LEFT:
			setDirection(Direction::FORWARD);
			break;
		case Side::RIGHT:
			setDirection(Direction::BACKWARDS);
			break;
		default:
			break;
	}
}

DC_Motor::DC_Motor(uint16_t *dutyCyclePtr) : Motor(dutyCyclePtr) {

}

void DC_Motor::setSpeed(uint8_t speed) {
	this->speed = speed;

	//pwm.setDutyCycle(speed * 10); // test
}

void DC_Motor::setDirection(Direction dir) {
	switch (dir) {
		case Direction::FORWARD:
			nrf_gpio_pin_set(MOTOR_PIN_0);
			nrf_gpio_pin_clear(MOTOR_PIN_1);
			break;
		case Direction::BACKWARDS:
			nrf_gpio_pin_clear(MOTOR_PIN_0);
			nrf_gpio_pin_set(MOTOR_PIN_1);
			break;
		case Direction::NEUTRAL:
			nrf_gpio_pin_clear(MOTOR_PIN_0);
			nrf_gpio_pin_clear(MOTOR_PIN_1);
			break;
		default:
			break;
	}
}