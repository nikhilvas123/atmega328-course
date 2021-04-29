/**
 * @file project_config.h
 * @author Nikhil Nevin Vas (nikhilvas123@gmail.com)
 * @brief Configuration file to define pins and ports for the interfaced peripherals
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __PROJECT_CONFIG_H__
#define __PROJECT_CONFIG_H__

/**
 * Include files
 */
#include <avr/io.h>

/**
 * Macro Definitions
 */

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

/**
 * @brief Enum for input output value
 * 
 */
typedef enum{
    IN,
    OUT
}dir;

/**
 * @brief Enum for high and low value
 * 
 */
typedef enum{
    LOW,
    HIGH
}state;
/**
 * @brief Sets the pin as input or output
 * 
 * @param d 
 * @param ddr 
 * @param port 
 * @param pin 
 */
void pin_mode(dir d, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin);

/**
 * @brief Reads the pin value
 * 
 * @param status 
 * @param pin 
 * @return Returns the digital value of pin 
 */
state pin_read(volatile uint8_t *status, uint8_t pin);

/**
 * @brief Turns the pin high or low
 * 
 * @param s 
 * @param port 
 * @param pin 
 */
void pin_write(state s, volatile uint8_t *port, uint8_t pin);

#endif /* __PROJECT_CONFIG_H__ */