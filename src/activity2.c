#include "activity2.h"
void activity2_init(){
    /* Set Avref = Avcc*/
    ADMUX = (1<<REFS0);
    /* Enable ADC and set prescaler to 128 */
    ADCSRA |= (1<<ADEN) | (0x07<<ADPS0);
}

uint16_t read_adc(uint8_t ch){
    /* ch must be 0-7 */
    ADMUX &= 0xf8;
    ch &= 0x07;
    /* Set channel in ADMUX register*/
    ADMUX |= ch;
    /* Start Convertion */
    ADCSRA |= (1<<ADSC);
    /* Wait for Convertion */
    while(!(ADCSRA & (1<<ADIF)));
    /* Set ADIF for next Convertion */
    ADCSRA |= (1<<ADIF);
    return ADC;
}