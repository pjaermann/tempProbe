#include <avr/io.h>
#include <util/delay.h>
#include "main.h"
#include "HC595.h"
uint32_t targetTemp=72;
int main (void){
	ioinit();
	while(1){
		
	/*	for(uint8_t i=0;i<10;i++){
			HC595_writeDigit(digits[i],SEG_2);
			_delay_ms(100);
		}
	*/
	}
	return 1;
}
void ioinit(){
	DDRC = 0b00111111;
	PORTC= 0b00000000;

	HC595_writeDigit(digits[7],1);
	HC595_writeDigit(digits[2],2);
}

