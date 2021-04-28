/**
 * @file activity3.h
 * @author Nikhil Nevin Vas (nikhilvas123@gmail.com)
 * @brief Generating PWM pulse from temperature sensor values
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef __ACTIVITY3_H__
#define __ACTIVITY3_H__

/**
 * Include files
 */ 
#include "project_config.h"
#include <avr/io.h>
#include <util/delay.h>

/**
 * Macro Definitions
 */
#define PWM_DDR DDRB
#define PWM_PIN PB1
#define COMPARE_REG OCR1A

/**
 * @brief Initialize all the Peripherals and pin configurations 
 * 
 */
void activity3_init();

/**
 * @brief Set the pwm threshold register
 * 
 * @param temp 
 */
void set_pwm_threshold(uint16_t temp);

#endif /** __ACTIVITY3_H__ */