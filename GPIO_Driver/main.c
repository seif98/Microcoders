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
	u32 i;
	while(1)
	{
		GPIOWrite(PORTF, 0b00001110, 0b00000000);
		for(i = 0; i < 16000000; i++);
		GPIOWrite(PORTF, 0b00001110, 0b00000010);
		for(i = 0; i < 16000000; i++);
		GPIOWrite(PORTF, 0b00001110, 0b00000100);
		for(i = 0; i < 16000000; i++);
		GPIOWrite(PORTF, 0b00001110, 0b00000110);
		for(i = 0; i < 16000000; i++);
		GPIOWrite(PORTF, 0b00001110, 0b00001000);
		for(i = 0; i < 16000000; i++);
		GPIOWrite(PORTF, 0b00001110, 0b00001010);
		for(i = 0; i < 16000000; i++);
		GPIOWrite(PORTF, 0b00001110, 0b00001100);
		for(i = 0; i < 16000000; i++);
		GPIOWrite(PORTF, 0b00001110, 0b00001110);
		for(i = 0; i < 16000000; i++);
	}
}
