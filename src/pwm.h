#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#include "nrf_drv_pwm.h"

class PWM {
private:
	nrf_drv_pwm_t m_pwm0;
	nrf_drv_pwm_config_t config;
	nrf_pwm_values_common_t seq_values[]; // Implement
	nrf_pwm_sequence_t seq;					// Implement

public:
	PWM();
	void setPercentage(uint8_t val);
};

#endif