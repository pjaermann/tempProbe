#include <avr/io.h>
#include <util/delay.h>
#include "main.h"
#include "HC595.h"
uint8_t targetTemp=72;

int main (void){
	ioinit();
	TEMPSPLITTED init;
	init=splitDigits(targetTemp);
	HC595_writeDigit(digits[init.digit1],SEG_1);
	HC595_writeDigit(digits[init.digit2],SEG_2);
	while(1){
	}
	return 1;
}


void ioinit(){
	DDRC = 0b00111111;
	PORTC= 0b00000000;

}

TEMPSPLITTED splitDigits(uint8_t temp){
	TEMPSPLITTED t;
	t.digit1=temp/10;
	t.digit2=temp-t.digit1*10;
	return t;
}
