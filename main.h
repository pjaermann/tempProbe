#ifndef MAIN_H
#define MAIN_H
extern uint8_t targetTemp;
typedef struct tempSplitted{
	uint8_t digit1;
	uint8_t digit2;
}TEMPSPLITTED;
void ioinit();
TEMPSPLITTED splitDigits(uint8_t temp);
#endif
