#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "main.h"
#include "HC595.h"
uint8_t targetTemp=33;
uint8_t setTempFlag=NOT_SET;
TEMPSPLITTED currentTemp;

ISR(TIMER0_COMPA_vect){
	adjustTemp();
}

ISR(INT0_vect){	
	if(bit_is_clear(PIND,2)){
		if(setTempFlag==NOT_SET)
			setTempFlag=SET;
		else
			setTempFlag=NOT_SET;
	}
}
int main (void){
	ioinit();
	EICRA |= (1<<ISC00);
	EIMSK |= (1<<INT0);
	TCCR0A |= (1<<WGM01);
	OCR0A = 0xF0;
	TIMSK0 |= (1<<OCIE0A);

	sei();
	TCCR0B |= (1<<CS00);
	TCCR0B |= (1<<CS02);

	while(1){
		currentTemp=splitDigits(targetTemp);
		displayTemp();
	}	
	return 1;
}


void ioinit(){
	DDRC = 0b00111111;
	PORTC= 0b00000000;

	DDRD &=~(1<<PIND2);//
	DDRD &=~(1<<PIND1);
	DDRD &=~(1<<PIND0);
	PORTD |=1<<PIND2;
	PORTD |=1<<PIND1;
	PORTD |=1<<PIND0;
}

TEMPSPLITTED splitDigits(uint8_t temp){
	TEMPSPLITTED t;
	t.digit1=temp/10;
	t.digit2=temp-t.digit1*10;
	return t;
}
void adjustTemp(){
	if(setTempFlag==SET){
		if(bit_is_clear(PIND,1))
			targetTemp=targetTemp+1;
		if(bit_is_clear(PIND,0))
			targetTemp=targetTemp-1;
	}
}

void displayTemp(){

	if(setTempFlag==NOT_SET){
		HC595_writeDigit(digits[currentTemp.digit1],SEG_1);
		HC595_writeDigit(digits[currentTemp.digit2],SEG_2);
	}
	else{
		HC595_writeDigit(digits[currentTemp.digit1],SEG_1);
		HC595_writeDigit(digits[currentTemp.digit2],SEG_2);
		_delay_ms(50);
		HC595_writeDigit(digits[10],SEG_1);
		HC595_writeDigit(digits[10],SEG_2);
		_delay_ms(20);
	}
}
