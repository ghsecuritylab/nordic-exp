#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#include "nrf_drv_pwm.h"

class PWM {
private:
	nrf_drv_pwm_t m_pwm0 = NRF_DRV_PWM_INSTANCE(0);
	nrf_drv_pwm_config_t config;

public:
	PWM();
};

#endif