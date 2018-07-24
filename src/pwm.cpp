#include "pwm.h"

#include "bsp.h"

PWM::PWM() {

	// Create PWM instance
	m_pwm0 = NRF_DRV_PWM_INSTANCE(0);

	// Set default config parameters. Defaults to output on LED_0 using channel 0.
	config.output_pins[0] = BSP_LED_0 | NRF_DRV_PWM_PIN_INVERTED; // channel 0
	config.output_pins[1] = NRF_DRV_PWM_PIN_NOT_USED;             // channel 1
    config.output_pins[2] = NRF_DRV_PWM_PIN_NOT_USED;             // channel 2
    config.output_pins[3] = NRF_DRV_PWM_PIN_NOT_USED;             // channel 3

    config.irq_priority = APP_IRQ_PRIORITY_LOW;
    config.base_clock   = NRF_PWM_CLK_1MHz;
    config.count_mode   = NRF_PWM_MODE_UP;
    config.top_value    = 1000;
    config.load_mode    = NRF_PWM_LOAD_COMMON;
    config.step_mode    = NRF_PWM_STEP_AUTO;

    // Initialize
    uint32_t err_code;
    err_code = nrf_drv_pwm_init(&m_pwm0, &config, NULL);

    if (err_code != NRF_SUCCESS) {
    	// Initialization failed. Take recovery action.
	}
}