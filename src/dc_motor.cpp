#include "dc_motor.h"

#include "nrf_gpio.h"

DC_Motor::DC_Motor() {
	speed = 0;

	// Initialize driver pins to be output
	nrf_gpio_cfg_output(MOTOR_PIN_0);
	nrf_gpio_cfg_output(MOTOR_PIN_1);

	// Set both pins low, motor is stopped
	nrf_gpio_pin_clear(MOTOR_PIN_0);
	nrf_gpio_pin_clear(MOTOR_PIN_1);

	//direction = Direction::NEUTRAL;
	//pwm = PWM();
}

DC_Motor::DC_Motor(Side side) {
	// Kludged to left side for testing
	DC_Motor();
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