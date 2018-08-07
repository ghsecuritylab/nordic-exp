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
#include "defines.h"

class PWM {
private:
	const uint32_t PIN_NUMBER = PWM_PIN_1;
	// Constant pointer to a changeable uint16_t
	uint16_t *const VALUE;

	nrf_drv_pwm_t 				m_pwm0;
	nrf_drv_pwm_config_t 		config;
	nrf_pwm_sequence_t 			seq;

	void setConfig();

public:
	PWM(uint16_t *const initialVal);
	~PWM();

	inline void setValue(uint16_t val);
	inline void play();
	inline void stop();
};



#endif // PWM_H