#ifndef PWM_H
#define PWM_H

/**
 * - Duty cycle must be between 0 - 100, this corresponds to speed percentage
 *   values.
 * - New duty cycle values must be set as (cycle = newValue | 0x8000), in order to enable
 *   the most siginificant bit in this 16-bit field so that the correct polarity is
 *   achieved.
 */

#include <stdint.h>

#include "nrf_drv_pwm.h"

class PWM {
private:
	nrf_drv_pwm_t 				m_pwm0;
	nrf_drv_pwm_config_t 		config;
	nrf_pwm_values_individual_t values;
	nrf_pwm_sequence_t 			seq;

	void setConfig();

public:
	PWM();
	~PWM();
	//void setPeriod(uint16_t period);
	//void setDutyCycle(uint16_t dutyCycle);
	void start();
	void stop();
};



#endif // PWM_H