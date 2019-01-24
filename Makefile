MCU := atmega32
AVR_SOURCE := src/**/*.c
TEST_SOURCE := tests/*.c src/dcf/*.c src/util/*.c  src/display/*.c src/validation/*.c src/internClock/*.c
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

test:	tests/runAllTests.c
	gcc	-o runAllTests \
		$(C_FLAGS) \
		$(TEST_SOURCE)

main:	src/hardware/main.c
	avr-gcc -mmcu=$(MCU) \
		-o main.elf \
		$(I_FLAGS) \
		$(C_FLAGS) \
		$(AVR_SOURCE)


# Die Option
#  -Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000
# ist seltsam, aber bewahrt den Wert .mmcu in der Hex-Datei und lässt
# diesen nicht wegoptimieren. Das ist für den Testbetrieb in der Simulation wichtig.
simulate-main-elf:
	avr-gcc -mmcu=$(MCU) \
		-o simulate-main.elf \
		-Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 \
		$(I_FLAGS) \
		$(C_FLAGS) \
		$(AVR_SOURCE)

simulate-main: simulate-main-elf
	$(SIMULATOR) -m $(MCU) -f $(F_CPU) -i input.vcd simulate-main.elf

clean:
	rm -f runAllTests
	rm -f main
	rm -f simulate-main.elf
	rm -f development

firm: main.hex
	avrdude -P /dev/ttyS0 -p m32 -c ponyser -v -U main.hex
