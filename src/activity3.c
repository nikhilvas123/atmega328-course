#include<activity3.h>

/* Initialize all the Peripherals and pin configurations */
void activity3_init(){
    /* Set TCCR1A to phase correct 10 bit PWM mode */
    TCCR1A |= (1 << COM1A1) | (1 << WGM11) | (1 << WGM10);
    /* Pre-scale to 256 */
    TCCR1B |= (1 << CS12);
    /* Set PB1 pin as pwm output pin */
    pin_mode(OUT,PWM_DDR,PWM_PORT,PWM_PIN);
}

/* Sets the Output compare register */
void set_pwm_threshold(uint16_t temp){
    *COMPARE_REG = temp;
}