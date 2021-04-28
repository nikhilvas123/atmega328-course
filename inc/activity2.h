/**
 * @file activity2.h
 * @author Nikhil Nevin Vas (nikhilvas123@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY2_H__
#define __ACTIVITY2_H__

/**
 * Include files
 */ 
#include "project_config.h"
#include <avr/io.h>
#include <util/delay.h>

/**
 * Macro Definitions
 */
#define TEMP_PIN 0

/**
 * @brief Reads the adc value from the given input channel
 * 
 * @param ch 
 * @return Returns 10 bit value of ADC
 */
uint16_t read_adc(uint8_t ch);

/**
 * @brief Initialize all the Peripherals and pin configurations 
 * 
 */
void activity2_init();

#endif /** __ACTIVITY2_H__ */