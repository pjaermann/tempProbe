.PHONY: flash
flash: oneShiftRegTest.hex
	avrdude -P /dev/ttyUSB0 -b 19200 -c avrisp -p m328 -U flash:w:oneShiftRegTest.hex

%.o: %.c
	avr-gcc -g -Os -DF_CPU=8000000UL -mmcu=atmega328 -c -o $@ $<

%: %.o
	avr-gcc -g -mmcu=atmega328 $< -o $@

%.hex: %
	avr-objcopy -O ihex -R .eeprom $< $@

