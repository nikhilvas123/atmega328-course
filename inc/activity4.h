/**
 * @file activity4.h
 * @author  Nikhil Nevin Vas (nikhilvas123@gmail.com)
 * @brief USART Protocol to transmit Temperature values
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __ACTIVITY_4__
#define __ACTIVITY_4__

/**
 * Include files
 */ 
#include "project_config.h"
#include <avr/io.h>
#include <util/delay.h>

/**
 * Macro definitions
 */
#define BAUD 9600 /**< Baud rate to 9600 */
#define BAUDRATE (F_CPU/(BAUD*16UL)-1) /**< Baud rate conversion factor */

/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void activity4_init();

/**
 * @brief Writes a character on tx pin
 * 
 * @param ch 
 */
void write_ch_tx(char ch);

/**
 * @brief Reads a character on rx pin
 * 
 * @return Returns the read character 
 */
char read_ch_rx();

/**
 * @brief Writes a line on tx pin
 * 
 * @param str 
 */
void write_tx(char *str);

#endif /** __ACTIVITY4_H__ */