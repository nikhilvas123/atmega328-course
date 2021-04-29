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
    switch(temp){
        case 20:
            *COMPARE_REG = 205;
            break;
        case 25:
            *COMPARE_REG = 409;
            break;
        case 29:
            *COMPARE_REG = 716;
            break;
        case 33:
            *COMPARE_REG = 972;
            break;
    }
}

/* Gets the temperature from ADC value using LUT */
uint16_t get_temp_in_c(uint16_t temp){
    if(temp <=200)
        return 20;
    else if (temp <=500)
        return 25;
    else if (temp <=700)
        return 29;
    return 33;
}