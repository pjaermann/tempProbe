#include <avr/io.h>

//#define F_CPU 8000000
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

void write_digit(unsigned char digit);
int main (void){
	DDRC = 0b00000111;
	PORTC= 0b00000000;
	while(1){
		
		for(uint8_t i=0;i<=7;i++){
			write_digit(_BV(i));
			_delay_ms(500);
		}

	}
	return 1;
}
void write_digit(unsigned char digit){
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
