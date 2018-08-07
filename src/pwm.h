#ifndef PWM_H
#define PWM_H

/**
 * - Duty cycle must be within the interval [0,100]. This corresponds to the
 *   percentage values of the speed of a motor.
 * - The most significant bit (15) of the duty cycle value must be positive,
 *   since it determines the polarity of the signal.
 */

#include <stdint.h>

#include "nrf_drv_pwm.h"
#include "defines.h"

/**
 * @brief      Class that contains the settings for a PWM instance, which can be
 *             used for speed control of a DC or Servo motor on the robot. The
 *             speed is set by changing the value that is pointed to by the
 *             const pointer VALUE, which again is read by the PWM driver.
 */
class PWM {
private:

	// The GPIO-pin used for PWM output
	const uint32_t PIN_NUMBER = PWM_PIN_1;

	// Constant pointer to a changeable uint16_t which holdes the value of the
	// PWM counter
	uint16_t *const VALUE;

	// Data structures provided by the hardware abstraction layer for PWM by
	// Nordic
	nrf_drv_pwm_t 				m_pwm0;
	nrf_drv_pwm_config_t 		config;
	nrf_pwm_sequence_t 			seq;

	/**
	 * @brief      Helper function for setting the config parameters at
	 *             initialization time.
	 */
	void setConfig();

public:
	/**
	 * @brief      Constructor with initializer-list for the const pointer VALUE
	 *
	 * @param      initialVal  address of int [0,100]
	 */
	PWM(uint16_t *const initialVal);

	/**
	 * @brief      Destroys the object.
	 */
	~PWM();

	/**
	 * @brief      Sets the value of the PWM counter
	 *
	 * @param[in]  val   An integer in range [0,100]
	 */
	void setValue(uint16_t val);

	/**
	 * @brief      Starts simple PWM playback with the current config
	 */
	void play();

	/**
	 * @brief      Disables PWM output
	 */
	void stop();
};



#endif // PWM_H