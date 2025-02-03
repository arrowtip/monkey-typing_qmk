
compile:
	qmk compile -kb monkey_typing/v1 -km arrowtip

flash:
	qmk flash -kb monkey_typing/v1 -km arrowtip

clean:
	qmk clean

clear-eeprom:
	@echo "Put keyboard into bootloader mode"
	@sleep 5
	dfu-programmer atmega32u4 erase --force
	dfu-programmer atmega32u4 flash --force --suppress-validation --eeprom reset.eep
	dfu-programmer atmega32u4 erase --force
	qmk flash -kb monkey_typing/v1 -km arrowtip


