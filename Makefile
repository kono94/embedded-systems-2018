MCU := atmega32
SOURCE := src/main.c src/DCF/*.c src/util/*.c src/validation/*.c
F_CPU := 16000000

# Schon drin sind /usr/lib/avr/include
# Es fehlen noch die Bibliotheken von simavr
I_FLAGS := -I /usr/include/simavr/

# Compiler-Optionen für alle Kompiliervorgänge
C_FLAGS := -O -Wall

OBJECTS := test-main.elf

SIMULATOR := simavr

main.hex: main
	avr-objcopy -O ihex main.elf main.hex
main:	src/main.c
	avr-gcc -mmcu=$(MCU) \
		-o main.elf \
		$(I_FLAGS) \
		$(C_FLAGS) \
		$(SOURCE)


# Die Option
#  -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000
# ist seltsam, aber bewahrt den Wert .mmcu in der Hex-Datei und lässt
# diesen nicht wegoptimieren. Das ist für den Testbetrieb in der Simulation wichtig.
test-main-elf:
	avr-gcc -mmcu=$(MCU) \
		-o test-main.elf \
		-Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 \
		$(I_FLAGS) \
		$(C_FLAGS) \
		$(SOURCE)

test-main: test-main-elf
	$(SIMULATOR) -m $(MCU) -f $(F_CPU) test-main.elf

clean:
	rm -f runAllTest
	rm -f main

firm: main.hex
	avrdude -P /dev/ttyS0 -p m32 -c ponyser -v -U main.hex
