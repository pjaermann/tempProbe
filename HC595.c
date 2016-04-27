#include <avr/io.h>
#include "HC595.h"
//digits 0->9 based on the connection between the shift register and the
//7seg display
uint8_t digits[11]={
	0b01111110,
	0b00010010,
	0b10111100,
	0b10110110,
	0b11010010,
	0b11100110,
	0b11001110,
	0b00110010,
	0b11111110,
	0b11110110,
	0b00000000//display dot
};

void HC595_writeDigit(uint8_t digit,uint8_t sevenSegTarg){
	switch(sevenSegTarg){
	case(1):
		SH1_CP_low();
		ST1_CP_low();
		for(uint8_t i=0;i<8;i++){
			if(bit_is_set(digit,i))
				DS1_high();
			else
				DS1_low();
			SH1_CP_high();
			SH1_CP_low();
		}
		ST1_CP_high();
		break;
	case(2):
		SH2_CP_low();
		ST2_CP_low();
		for(uint8_t i=0;i<8;i++){
			if(bit_is_set(digit,i))
				DS2_high();
			else
				DS2_low();
			SH2_CP_high();
			SH2_CP_low();
		}
		ST2_CP_high();
		break;
	default:
		break;
	}
}		
