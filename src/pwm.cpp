#include "pwm.h"

#include "defines.h"
#include "bsp.h"

void PWM::setConfig() {

	// Set pin configuration
	config.output_pins[0] = PIN_NUMBER;					// In use
	config.output_pins[1] = NRF_DRV_PWM_PIN_NOT_USED;   // Unused
    config.output_pins[2] = NRF_DRV_PWM_PIN_NOT_USED;   // Unused
    config.output_pins[3] = NRF_DRV_PWM_PIN_NOT_USED;   // Unused

    // These values correspond to a max PWM frequency of 20KHz, which is
    // suitable for a DC motor.
    config.irq_priority = APP_IRQ_PRIORITY_LOW;
    config.base_clock   = NRF_PWM_CLK_2MHz;
    config.count_mode   = NRF_PWM_MODE_UP;
    config.top_value    = 100;
    config.load_mode    = NRF_PWM_LOAD_COMMON;
    config.step_mode    = NRF_PWM_STEP_AUTO;
}

PWM::PWM(uint16_t *const initialVal) : VALUE(initialVal) {

	// Initialize a PWM instance
	m_pwm0 = NRF_DRV_PWM_INSTANCE(0);

	// Set config using separate function
	setConfig();

    // Initialize
    APP_ERROR_CHECK(nrf_drv_pwm_init(&m_pwm0, &config, NULL));

	seq.values.p_common = VALUE;
	seq.length       	= NRF_PWM_VALUES_LENGTH(VALUE);
    seq.repeats      	= 0;
    seq.end_delay    	= 0;

}

PWM::~PWM() {
	nrf_drv_pwm_uninit(&m_pwm0);
}

void PWM::setValue(uint16_t val) {
	// Value must be bitwise or'ed to ensure correct polarity of the signal.
	*VALUE = val | 0x8000;
}

void PWM::play() {
	// Starts the PWM playback in an eternal loop
	nrf_drv_pwm_simple_playback(&m_pwm0, &seq, 1, NRF_DRV_PWM_FLAG_LOOP);
}

void PWM::stop() {
	// Stops the simple playback, the second parameter decides if it should wait
	// for the current cycle to finish.
	nrf_drv_pwm_stop(&m_pwm0, false);
}