#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#include "nrf_drv_pwm.h"

class PWM {
private:
	nrf_drv_pwm_config_t const config;

public:
	PWM();
};

#endif