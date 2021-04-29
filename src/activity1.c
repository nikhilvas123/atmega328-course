#include<activity1.h>
/* Function checks if button and heater is on */
uint8_t button_heater_check(){
	return pin_read(BUTTON_STATUS, BUTTON_PIN) & pin_read(BUTTON_STATUS, HEATER_PIN);
}

/* Initialize all the Peripherals and pin configurations */
void activity1_init(){
	/* Configure LED Pin as Output */
    pin_mode(OUT,LED_DDR,LED_PORT,LED_PIN);
	/* Configure Button pin as Input */
    pin_mode(IN,BUTTON_DDR,BUTTON_PORT,BUTTON_PIN);
	/* Configure Heater pin as Input */
    pin_mode(IN,BUTTON_DDR,BUTTON_PORT,HEATER_PIN);
}

/* Changes LED state based on button and heater */
void change_led_state(){
    /* Check if both Switch is closed; i.e Pins 0 and 1 of port D is low*/
    if(button_heater_check()){
        /* Turn on LED */
        pin_write(HIGH,LED_PORT,LED_PIN);
        _delay_ms(LED_ON_TIME);
    }
    else{
        /* Turn off LED*/
        pin_write(LOW,LED_PORT,LED_PIN);
        _delay_ms(LED_OFF_TIME);
    }
}