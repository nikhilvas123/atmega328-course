#include<activity1.h>
/* Function checks if button and heater is on */
uint8_t button_heater_check(){
	return !((BUTTON_STATUS&(1<<BUTTON_PIN)) || (BUTTON_STATUS&(1<<HEATER_PIN)));
}

/* Function to change the led state */
void led_state(state s){
	if(s)
		LED_PORT|=(1<<LED_PIN);		
	else
		LED_PORT&=~(1<<LED_PIN);
}

/* Initialize all the Peripherals and pin configurations */
void activity1_init(){
	/* Configure LED Pin as Output */
	LED_DDR |= (1 << LED_PIN);
	/* Configure Button pin as Input */
	BUTTON_DDR&=~(1<<BUTTON_PIN);
    BUTTON_PORT|=(1<<BUTTON_PIN);
	/* Configure Heater pin as Input */
    BUTTON_DDR&=~(1<<HEATER_PIN);
    BUTTON_PORT|=(1<<HEATER_PIN);
}

/* Changes LED state based on button and heater */
void change_led_state(){
    /* Check if both Switch is closed; i.e Pins 0 and 1 of port D is low*/
    if(button_heater_check()){
        /* Turn on LED */
        led_state(HIGH);
        _delay_ms(500);
    }
    else{
        /* Turn off LED*/
        led_state(LOW);
        _delay_ms(500);
    }
}