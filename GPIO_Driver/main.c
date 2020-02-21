/**
 * main.c
 */
#include "std_types.h"
#include "utils.h"
#include "Register Map.h"
#include "GPIO.h"

void main(void)
{
	GPIOINIT();
	GPIOClockSet(PORTF);
	GPIODirectionModeSet(PORTF, 0b00001110, MODE_OUT);
	GPIODirectionModeSet(PORTF, 0b00010000, MODE_IN);
	GPIOPadSet(PORTF, 0b00010000, Drive_4mA, Pad_PU);
	GPIOPadSet(PORTF, 0b00001110, Drive_2mA, PAD_NPU_NPD);
	CLRBIT(OFFSET(PORTF, 0x3FC), 2);
	CLRBIT(OFFSET(PORTF, 0x3FC), 3);
	SETBIT(OFFSET(PORTF, 0x3FC), 4);
	//GPIOWrite(PORTF, 0b00001110, 0b00000010);
}
