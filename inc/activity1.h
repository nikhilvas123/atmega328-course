/**
 * @file  activity1.h
 * @author Nikhil Nevin Vas (nikhilvas123@gmail.com)
 * @brief Toggling LED based on inputs from button and heater
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ACTIVITY1_H__
#define __ACTIVITY1_H__


/**
 * Include files
 */ 
#include "project_config.h"
#include <avr/io.h>
#include <util/delay.h>

/**
 * Structure and enum definitions
 */ 
typedef enum{
    LOW,
    HIGH
}state;

/**
 * Macro Definitions
 */
#define LED_PORT (PORTB)    /**< LED Port */
#define LED_DDR (DDRB)    /**< LED Data Direction Register */
#define LED_PIN  (PB0)  /**< LED Pin Number  */

#define BUTTON_PORT (PORTD) /**< BUTTON and HEATER Port */
#define BUTTON_DDR (DDRD)  /**< BUTTON Data Direction Register */
#define BUTTON_STATUS (PIND) /**< BUTTON Status Register */
#define BUTTON_PIN (PD0)  /**< BUTTON Pin number */
#define HEATER_PIN (PD1)  /**< HEATER Pin number */

#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */

#define LED_ON_TIME     (500)  /**< LED ON time in milli seconds  */
#define LED_OFF_TIME    (500)   /**< LED OFF time in milli seconds */

/**
 * Function declarations
 */

/**
 * @brief Function checks if button and heater is on
 * 
 * @return returns true if both button and heater is on 
 */
uint8_t button_heater_check();

/**
 * @brief Function to change the led state
 * 
 * @param s 
 */
void led_state(state s);

/**
 * @brief Initialize all the Peripherals and pin configurations 
 * 
 */
void activity1_init();

/**
 * @brief Changes led state based on button and heater input
 * 
 */
void change_led_state();

#endif /** __ACTIVITY1_H__ */