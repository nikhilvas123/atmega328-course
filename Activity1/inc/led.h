/**
 * @file  led.h
 * @author Nikhil Nevin Vas (nikhilvas123@gmail.com)
 * @brief Led Definitions
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __LED_H__
#define __LED_H__
/**
 * Macro Definitions
 */
#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */

#define LED_ON_TIME     (500)  /**< LED ON time in milli seconds  */
#define LED_OFF_TIME    (500)   /**< LED OFF time in milli seconds */

/**
 * Include files
 */ 
#include <avr/io.h>
#include <avr/delay.h>
/*
 * Function Definitions
 */

#endif /** __LED_H__ */