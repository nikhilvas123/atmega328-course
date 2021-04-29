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
#include "activity3.h"
#include "activity4.h"
/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void){
	activity1_init();
	activity2_init();
	activity3_init();
	activity4_init();
}

/**
 * @brief Converts temperature to string
 * 
 * @param temp_val 
 * @param temp_str 
 */
void temp_to_str(volatile uint16_t temp_val, char *temp_str){
	uint8_t j=0, i=0;
	char buffer[5];
	/* Stores temperature in buffer but is reversed*/
	while(temp_val){
		buffer[j] = '0' + temp_val%10;
		temp_val /= 10;
		j++;
	}
	/* Reverse string again */
	for(i=0;j--;i++){
		temp_str[i] = buffer[j];
	}
	/* Add null character */
	temp_str[i]='\0';
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
	volatile uint16_t temp_val = 0;
	char temp_str[5];
	/* Initialize Peripherals */
	peripheral_init();
	write_tx("SeatHeater initialze successfull\n");
	for(;;){
		/* Check if button and heater is on and change led state; i.e Pins 0 and 1 of port D is low*/
		change_led_state();
		/* Get temperature value from temperature sensor through ADC */
		temp_val = read_adc(TEMP_PIN);
		/* Convert raw value to temperature in degree C */
		temp_val = get_temp_in_c(temp_val);
		/* Set pwm threshold value to temperature value */
		set_pwm_threshold(temp_val);
		/* Write Temperature Reading to UART */
		write_tx("Temperature Reading is: ");
		/* Convert temperature to string */
		temp_to_str(temp_val,temp_str);
		write_tx(temp_str);
		write_tx("\"C\n");

		_delay_ms(1000);
    }
	return 0;
}
