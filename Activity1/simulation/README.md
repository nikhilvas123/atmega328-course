# Project In Action

|ON|OFF|
|:--:|:--:|
|![ON](ON.png)|![OFF](OFF.png)|

## Code 
```
	for(;;){
		if(!((PIND&(1<<SW_PIN_0)) || (PIND&(1<<SW_PIN_1)))){
			LED_PORT|=(1<<LED_PIN);
            _delay_ms(500);
        }
        else{
            LED_PORT&=~(1<<LED_PIN);
			_delay_ms(500);
        }
    }
```