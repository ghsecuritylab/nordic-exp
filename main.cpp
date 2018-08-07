/**
 * Copyright (c) 2015 - 2018, Nordic Semiconductor ASA
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 * 
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 * 
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 * 
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 * 
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
/** @file
 * @defgroup pwm_example_main main.c
 * @{
 * @ingroup pwm_example
 *
 * @brief PWM Example Application main file.
 *
 * This file contains the source code for a sample application using PWM.
 */

extern "C" {
	#include <stdio.h>
	#include <string.h>

	#include "nrf_drv_pwm.h"
	#include "app_util_platform.h"
	#include "app_error.h"
	#include "boards.h"
	#include "bsp.h"
	#include "app_timer.h"
	#include "nrf_drv_clock.h"

	#include "nrf_log.h"
	#include "nrf_log_ctrl.h"
	#include "nrf_log_default_backends.h"
}

#include <stdint.h>

#include "robot.h"
#include "defines.h"
#include "pwm.h"

/*
static nrf_drv_pwm_t m_pwm0 = NRF_DRV_PWM_INSTANCE(0);


void motorPWM() {
	nrf_drv_pwm_config_t /*const*/ /*config;

	config.output_pins[0] = PWM_PIN;// | NRF_DRV_PWM_PIN_INVERTED;	// channel 0
	config.output_pins[1] = NRF_DRV_PWM_PIN_NOT_USED;             // channel 1
    config.output_pins[2] = NRF_DRV_PWM_PIN_NOT_USED;             // channel 2
    config.output_pins[3] = NRF_DRV_PWM_PIN_NOT_USED;             // channel 3

    config.irq_priority = APP_IRQ_PRIORITY_LOW;
    config.base_clock   = NRF_PWM_CLK_2MHz;
    config.count_mode   = NRF_PWM_MODE_UP;
    config.top_value    = 100; // 20kHZ
    config.load_mode    = NRF_PWM_LOAD_COMMON;
    config.step_mode    = NRF_PWM_STEP_AUTO;

    APP_ERROR_CHECK(nrf_drv_pwm_init(&m_pwm0, &config, NULL));

    /*
    nrf_pwm_values_individual_t /*const*/ /*values;
    values.channel_0 = 0 | 0x8000;
    values.channel_1 = 0 | 0x8000;
    values.channel_2 = 0 | 0x8000;
    values.channel_3 = 0 | 0x8000;
    */
/*
    nrf_pwm_sequence_t /*const*/ /*seq;
	seq.values.common = VALUE;
	seq.length       	= NRF_PWM_VALUES_LENGTH(VALUE);
    seq.repeats      	= 0;
    seq.end_delay    	= 0;

    nrf_drv_pwm_simple_playback(&m_pwm0, &seq, 1, NRF_DRV_PWM_FLAG_LOOP);

    // value change test
    values.channel_0 = 10 | 0x8000;
    values.channel_0 = 20 | 0x8000;
    values.channel_0 = 30 | 0x8000;
    values.channel_0 = 40 | 0x8000;
    values.channel_0 = 50 | 0x8000;
    values.channel_0 = 60 | 0x8000;
    values.channel_0 = 70 | 0x8000;
    values.channel_0 = 80 | 0x8000;
    values.channel_0 = 90 | 0x8000;
    values.channel_0 = 100 | 0x8000;
    
}
*/
/*
static void bsp_evt_handler(bsp_event_t evt)
{
    void (* const demos[])(void) =
    {
        demo1,
        demo2,
        demo3,
        demo4,
        demo5
    };
    uint8_t const  demo_idx_max = (sizeof(demos) / sizeof(demos[0])) - 1;
    static uint8_t demo_idx     = 0;

    switch (evt)
    {
        // Button 1 - switch to the previous demo.
        case BSP_EVENT_KEY_0:
            if (demo_idx > 0)
            {
                --demo_idx;
            }
            else
            {
                demo_idx = demo_idx_max;
            }
            break;

        // Button 2 - switch to the next demo.
        case BSP_EVENT_KEY_1:
            if (demo_idx < demo_idx_max)
            {
                ++demo_idx;
            }
            else
            {
                demo_idx = 0;
            }
            break;

        default:
            return;
    }

    if (m_used & USED_PWM(0))
    {
        nrf_drv_pwm_uninit(&m_pwm0);
    }
    if (m_used & USED_PWM(1))
    {
        nrf_drv_pwm_uninit(&m_pwm1);
    }
    if (m_used & USED_PWM(2))
    {
        nrf_drv_pwm_uninit(&m_pwm2);
    }
    m_used = 0;

    demos[demo_idx]();
}
*/
static void init_bsp()
{
    APP_ERROR_CHECK(nrf_drv_clock_init());
    nrf_drv_clock_lfclk_request(NULL);

    APP_ERROR_CHECK(app_timer_init());
    //APP_ERROR_CHECK(bsp_init(BSP_INIT_BUTTONS, bsp_evt_handler));
    //APP_ERROR_CHECK(bsp_buttons_enable());
}


void app_error_fault_handler(uint32_t id, uint32_t pc, uint32_t info)
{
    bsp_board_leds_on();
    app_error_save_and_stop(id, pc, info);
}


int main(void)
{
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    init_bsp();

    NRF_LOG_INFO("PWM test application started.");

    // Start with Demo 1, then switch to another one when the user presses
    // button 1 or button 2 (see the 'bsp_evt_handler' function).
    //demo5();
    
    //nrf_gpio_cfg_output(PWM_PIN);
    nrf_gpio_cfg_output(MOTOR_PIN_0);
	nrf_gpio_cfg_output(MOTOR_PIN_1);

	// Set both pins low, motor is stopped
	//nrf_gpio_pin_clear(PWM_PIN);
	nrf_gpio_pin_clear(MOTOR_PIN_0);
	nrf_gpio_pin_clear(MOTOR_PIN_1);

	// Set direction
	nrf_gpio_pin_set(MOTOR_PIN_0);

    //motorPWM();

    // Robot test begin
    uint16_t val = 0x8000;
	PWM pwmTest = PWM(&val);
	pwmTest.play();
	pwmTest.setValue(10);
	pwmTest.setValue(30);
	pwmTest.setValue(40);
	pwmTest.setValue(60);
	pwmTest.setValue(80);
	pwmTest.setValue(100);
	pwmTest.setValue(110);
	pwmTest.stop();
    // Robot test end

    for (;;)
    {
        // Wait for an event.
        __WFE();

        // Clear the event register.
        __SEV();
        __WFE();

        NRF_LOG_FLUSH();
    }
}


/** @} */
