#include "motor.h"

#include "nrf_gpio.h"


uint16_t Motor::initialDutyCycle = 0x8000;

Motor::Motor() : pwm(&initialDutyCycle), loc(Location::UNKNOWN), INPUT_PIN_1(255), INPUT_PIN_2(255) {
	initPins();
}

Motor::Motor(Location loc, uint8_t pin_1, uint8_t pin_2) : pwm(&initialDutyCycle), loc(loc), INPUT_PIN_1(pin_1), INPUT_PIN_2(pin_2) {
	initPins();
}

void Motor::initPins() {

	// Set pins to output
	//nrf_gpio_cfg_output(PWM_PIN);
    nrf_gpio_cfg_output(MOTOR_PIN_0);
	nrf_gpio_cfg_output(MOTOR_PIN_1);

	// Set both pins low, motor is stopped
	//nrf_gpio_pin_clear(PWM_PIN);
	nrf_gpio_pin_clear(MOTOR_PIN_0);
	nrf_gpio_pin_clear(MOTOR_PIN_1);

	// Set direction
	//nrf_gpio_pin_set(MOTOR_PIN_0);
}

void Motor::setSpeed(uint8_t speed) {
	if (speed > 100)
		speed = 100;
	else if (speed < 0)
		speed = 0;

	// Value must be bitwise OR'ed to ensure correct polarity of the signal. Move this to pwm class?
	pwm.setValue(speed | 0x8000);
}

uint8_t Motor::getSpeed() const {
	uint16_t value = pwm.getValue();
	// Clear the MSB in case the PWM cycle has the wrong polarity
	value &= ~0x8000;
	return (uint8_t) value;
}