#include<project_config.h>

/* Sets the pin as input or output */
void pin_mode(dir d, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin){
    if(d)
        *ddr |= (1 << pin);
    else
        *ddr &= ~(1 << pin);
        *port |= (1 << pin);
}

/* Turns the pin high or low */
void pin_write(state s, volatile uint8_t *port, uint8_t pin){
    if(s)
        /* Turn ON LED*/
		*port|=(1<<pin);		
	else
        /* Turn OFF LED */
		*port&=~(1<<pin);
}

/* Reads the pin value */
state pin_read(volatile uint8_t *status, uint8_t pin){
    return !(*status&(1<<pin));
}