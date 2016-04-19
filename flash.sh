#!/bin/sh
avr-gcc -g -Os -mmcu=atmega328 -c oneShiftRegTest.c
avr-gcc -g -mmcu=atmega328 -o oneShiftRegTest.elf oneShiftRegTest.o
avr-objcopy -j .text -j .data -O ihex oneShiftRegTest.elf oneShiftRegTest.hex
avrdude -P /dev/ttyUSB0 -b 19200 -c avrisp -p m328 -U flash:w:oneShiftRegTest.hex
