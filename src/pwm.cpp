#include "pwm.h"

#include "defines.h"
#include "bsp.h"

void PWM::setConfig() {
	// Set default config parameters. Defaults to output on LED_0 using channel 0.
	//config.output_pins[0] = BSP_LED_0 | NRF_DRV_PWM_PIN_INVERTED; // channel 0
	config.output_pins[0] = PWM_PIN;								// channel 0
	config.output_pins[1] = NRF_DRV_PWM_PIN_NOT_USED;             // channel 1
    config.output_pins[2] = NRF_DRV_PWM_PIN_NOT_USED;             // channel 2
    config.output_pins[3] = NRF_DRV_PWM_PIN_NOT_USED;             // channel 3

    config.irq_priority = APP_IRQ_PRIORITY_LOW;
    config.base_clock   = NRF_PWM_CLK_1MHz;
    config.count_mode   = NRF_PWM_MODE_UP;
    config.top_value    = 1000;
    config.load_mode    = NRF_PWM_LOAD_COMMON;
    config.step_mode    = NRF_PWM_STEP_AUTO;
}

PWM::PWM() {

	// Create PWM instance
	m_pwm0 = NRF_DRV_PWM_INSTANCE(0);

	// Set config using the argument as output pin
	setConfig();

    // Initialize
    uint32_t err_code;
    err_code = nrf_drv_pwm_init(&m_pwm0, &config, NULL);

    if (err_code != NRF_SUCCESS) {
    	// Initialization failed. Take recovery action.
	}

	// Set default sequence values
	seq_values[0] = 0;

	seq.values.p_common = seq_values;
	seq.length       	= NRF_PWM_VALUES_LENGTH(seq_values);
    seq.repeats      	= 0;
    seq.end_delay    	= 0;

}

PWM::~PWM() {
	// Uninitialize PWM instance
	nrf_drv_pwm_uninit(&m_pwm0);
}

// for testing
void PWM::setDutyCycle(uint16_t dutyCycle) {
	seq_values[1] = dutyCycle;
}

void PWM::start() {
	// Starts simple playback in a loop
	nrf_drv_pwm_simple_playback(&m_pwm0, &seq, 3, NRF_DRV_PWM_FLAG_LOOP);
}

void PWM::stop() {
	// Stops the simple playback, does not wait for it to finish
	nrf_drv_pwm_stop(&m_pwm0, false);
}