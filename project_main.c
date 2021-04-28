/**
 * @file project_main.c
 * @author Nikhil Nevin Vas (nikhilvas123@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "activity1.h"
#include "activity2.h"

/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void){
	activity1_init();
	activity2_init();
}

/**
 * @brief Main function where the code execution starts
 * 
 * @return int Return 0 if the program completes successfully
 * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
 * @note PORTD0 and PORTD1 have pull up register. i.e if the pins are open, the pins are inherently high
 */
int main(void)
{
	volatile uint16_t temp_val;
	/* Initialize Peripherals */
	peripheral_init();

	for(;;){
		/* Check if both Switch is closed; i.e Pins 0 and 1 of port D is low*/
		change_led_state();
		temp_val = read_adc(TEMP_PIN);
		_delay_ms(200);
    }
	return 0;
}
