#include "motor.h"

#include "nrf_gpio.h"


uint16_t Motor::initialDutyCycle = 0x8000;

Motor::Motor() : pwm(&initialDutyCycle), loc(Location::UNKNOWN), INPUT_PIN_1(255), INPUT_PIN_2(255) {}

Motor::Motor(Location loc, uint8_t pin_1, uint8_t pin_2) : pwm(&initialDutyCycle), loc(loc), INPUT_PIN_1(pin_1), INPUT_PIN_2(pin_2) {}