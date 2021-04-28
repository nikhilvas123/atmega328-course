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