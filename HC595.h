#ifndef HC595_H
#define HC595_H

#define SEG_1		1
#define SEG_2		2

#define DS1_PORT        PORTC
#define DS1_PIN         0
#define ST1_CP_PORT     PORTC
#define ST1_CP_PIN      1
#define SH1_CP_PORT     PORTC
#define SH1_CP_PIN      2

#define DS2_PORT	PORTC
#define DS2_PIN		3
#define ST2_CP_PORT	PORTC
#define ST2_CP_PIN	4
#define SH2_CP_PORT	PORTC
#define SH2_CP_PIN	5

#define DS1_low()       DS1_PORT&=~_BV(DS1_PIN)
#define DS1_high()      DS1_PORT|=_BV(DS1_PIN)
#define ST1_CP_low()    ST1_CP_PORT&=~_BV(ST1_CP_PIN)
#define ST1_CP_high()   ST1_CP_PORT|=_BV(ST1_CP_PIN)
#define SH1_CP_low()    SH1_CP_PORT&=~_BV(SH1_CP_PIN)
#define SH1_CP_high()   SH1_CP_PORT|=_BV(SH1_CP_PIN)

#define DS2_low()       DS2_PORT&=~_BV(DS2_PIN)
#define DS2_high()      DS2_PORT|=_BV(DS2_PIN)
#define ST2_CP_low()    ST2_CP_PORT&=~_BV(ST2_CP_PIN)
#define ST2_CP_high()   ST2_CP_PORT|=_BV(ST2_CP_PIN)
#define SH2_CP_low()    SH1_CP_PORT&=~_BV(SH2_CP_PIN)
#define SH2_CP_high()   SH2_CP_PORT|=_BV(SH2_CP_PIN)

extern uint8_t digits[11];
void HC595_writeDigit(uint8_t digit,uint8_t sevenSegTarg);
#endif
