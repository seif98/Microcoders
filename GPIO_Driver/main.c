

/**
 * main.c
 */

#include "std_types.h"
#include "utils.h"
#include "Register Map.h"
#include "GPIO.h"
#include "Interrupt.h"
#define TIMER0  0x40030000
void main(void)
5{
    ClockInit();
    GPIOINIT();
    GPIOClockSet(PORTF);
    GPIODirectionModeSet(PORTF,0b00001110,MODE_OUT);
    GPIODirectionModeSet(PORTF,0b00010000,MODE_IN);
    GPIOPadSet(PORTF, 0x0E, Drive_4mA,PAD_NPU_NPD);
    GPIOPadSet(PORTF, 0x10, Drive_4mA,Pad_PU);

    GPIOISet(PORTF, 0x10, MODE_RISING);

//    volatile u32 *reg = GPIO_PORTF + GPIOICR;
//    SETBIT(*reg , 4);

    volatile u32 * EN0 = 0xE000E100;
    SETBIT(*EN0 , 30);
    SETBIT(*EN0 , 19);
  volatile u32 *reg = 0x400FE000 + 0x604;
    SETBIT(*reg , 0);
    reg = TIMER0 + 0x00C;
    CLRBIT(*reg , 0);
    reg = TIMER0 + 0x000;
    CLRBIT(*reg , 0);
    CLRBIT(*reg , 1);
    CLRBIT(*reg , 2);
    reg= TIMER0+0x004;
    SETBIT(*reg , 1);
    CLRBIT(*reg , 0);
    reg = TIMER0+ 0x028;
    *reg = 0xFFFFF;
    reg = TIMER0 + 0x018;
    SETBIT(*reg , 0);
    reg = TIMER0 + 0x00C;
      SETBIT(*reg , 0);
      reg = TIMER0 + 0x024;
      SETBIT(*reg , 0);

    while(1);
}
void ISR_PORTF()
{
    static u8 f=0;
    if(f==0)
    {
    GPIOWrite(PORTF,0b00001110,0b00001110);
    f++;
    }
    else
    {
        GPIOWrite(PORTF,0b00001110,0b00000000);
        f=0;

    }

    volatile u32 *reg = GPIO_PORTF + GPIOICR;
    SETBIT(*reg , 4);

}
void ISR_TIMER0()
{
    GPIOWrite(PORTF,0b00001110,0b00001110);

    volatile u32 *reg = TIMER0 + 0x024;
    SETBIT(*reg , 0);

}

void GPIOISet(u32 port, u8 pins,Interrupt_mode_t mode)
{
    volatile u32* reg = port + GPIOIM;
    u8 data = *reg;
    data &= (~pins);
    *reg = data;

    if(mode == MODE_EDGE)
    {
        reg = port + GPIOIS;
        data = *reg;
        data &= (~pins);
        *reg = data;
        
        reg = port + GPIOIBE;
        data = *reg;
        data |= pins;
        *reg = data;

    }
    else if(mode == MODE_RISING)
    {
        reg = port + GPIOIS;
        data = *reg;
        data &= (~pins);

        *reg = data;

        reg = port + GPIOIBE;
        data = *reg;
        data &= (~pins);
        *reg = data;

        reg = port + GPIOIEV;
        data = *reg;
        data |= pins;
        *reg = data;
    }
    else if(mode == MODE_FALLING)
    {
        reg = port + GPIOIS;
        data = *reg;
        data &= (~pins);
        *reg = data;

        reg = port + GPIOIBE;
        data = *reg;
        data &= (~pins);
        *reg = data;

        reg = port + GPIOIEV;
        data = *reg;
        data &= (~pins);
        *reg = data;
    }
   else if(mode == MODE_HIGH)
    {
        reg = port + GPIOIS;
        data = *reg;
        data |= pins;
        *reg = data;

        reg = port + GPIOIEV;
        data = *reg;
        data |= pins;
        *reg = data;
    }
    else if(mode == MODE_LOW)
    {
        reg = port + GPIOIS;
        data = *reg;
        data |= pins;
        *reg = data;

        reg = port + GPIOIEV;
        data = *reg;
        data &= (~pins);
        *reg = data;
    }

    reg = port + GPIOIM;
    data = *reg;
    data |= pins;
    *reg = data;
}
