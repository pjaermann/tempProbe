#include <avr/io.h>

#define F_CPU 8000000
#include <util/delay.h>

#define DS_PORT		PORTC
#define DS_PIN		0
#define ST_CP_PORT	PORTC
#define ST_CP_PIN	1
#define SH_CP_PORT	PORTC
#define SH_CP_PIN	2

#define DS_low()	DS_PORT&=~_BV(DS_PIN)
#define DS_high()	DS_PORT|=_BV(DS_PIN)
#define ST_CP_low()	ST_CP_PORT&=~_BV(ST_CP_PIN)
#define ST_CP_high()	ST_CP_PORT|=_BV(ST_CP_PIN)
#define SH_CP_low()	SH_CP_PORT&=~_BV(SH_CP_PIN)
#define SH_CP_high()	SH_CP_PORT|=_BV(SH_CP_PIN)
//map of the digits 0->9 BASED on the connection between the shift register and the 7 segments
uint8_t digits[10]={
	0b01111110,
	0b00010010,
	0b10111100,
	0b10110110,
	0b11010010,
	0b11100110,
	0b11001110,
	0b00110010,
	0b11111110,
	0b11110110
};
void write_digit(uint8_t digit);
int main (void){
	DDRC = 0b00000111;
	PORTC= 0b00000000;
	while(1){
		
		for(uint8_t i=0;i<10;i++){
			write_digit(digits[i]);
			_delay_ms(100);
		}

	}
	return 1;
}
void write_digit(uint8_t digit){
	SH_CP_low();
	ST_CP_low();
	for(uint8_t i=0;i<8;i++){
		if(bit_is_set(digit,i))
			DS_high();
		else
			DS_low();

		SH_CP_high();
		SH_CP_low();
	}
	ST_CP_high();
}
