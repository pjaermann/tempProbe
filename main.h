#ifndef MAIN_H
#define MAIN_H
#define NOT_SET	0
#define SET 	1
extern uint8_t targetTemp;
typedef struct tempSplitted{
	uint8_t digit1;
	uint8_t digit2;
}TEMPSPLITTED;
void ioinit();
void adjustTemp();
void displayTemp();
TEMPSPLITTED splitDigits(uint8_t temp);
#endif
