#include<activity4.h>

/* Initialize all the Peripherals and pin configurations */
void activity4_init(){
    /* Set Baud Rate */
    UBRR0H = (BAUDRATE >> 8);
    UBRR0L = BAUDRATE ;
    /* Set character size to 8 bit */
    UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
    /* Enable Tx Rx */
    UCSR0B |= (1<<TXEN0) | (1<<RXEN0);
}
/* Writes a character on Tx pin */
void write_ch_tx(char ch){
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = ch;
}
/* Reads a character on Rx pin */
// char read_ch_rx(){
//     while(!(UCSR0A & (1<<RXC0)));
//     return UDR0;
// }

/* Write a sentence on Tx pin*/
void write_tx(char *str){
    uint8_t i=0;
    for(i=0; str[i] != '\0'; i++){
        write_ch_tx(str[i]);
    }
}