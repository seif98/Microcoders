/**
 * main.c
 */

#include "Register Map.h"
#include "std_types.h"
#include "GPIO.h"

void GPIOINIT()
{   
    #if BUS == AHB
        SETBIT(GPIOHBCTL, 5);
        SETBIT(GPIOHBCTL, 4);
        SETBIT(GPIOHBCTL, 3);
        SETBIT(GPIOHBCTL, 2);
        SETBIT(GPIOHBCTL, 1);
        SETBIT(GPIOHBCTL, 0);
    #elif BUS == APB
        CLRBIT(GPIOHBCTL, 5);
        CLRBIT(GPIOHBCTL, 4);
        CLRBIT(GPIOHBCTL, 3);
        CLRBIT(GPIOHBCTL, 2);
        CLRBIT(GPIOHBCTL, 1);
        CLRBIT(GPIOHBCTL, 0);
    #endif
    ClockInit();
}

void GPIODirectionModeSet(u32 port, u8 pins, gpio_mode_t mode)
{
    volatile u32 * reg = port + GPIODEN;
    u8 data = *reg;
    data &= ~(pins);
    data |= (0xFF & pins);

    *reg = data;

    reg = (port + GPIODIR);
    data = *reg;

    data &= ~(pins);
    if (mode == MODE_OUT)
        data |= (0xff & pins);
    else
        data |= (0x00 & pins);

	*reg = data;

    reg = (port + GPIOAFSEL);
    data = *reg;

    data &= ~(pins);
    if (mode == MODE_AF)
        data |= (0xff & pins);
    else
        data |= (0x00 & pins);

	*reg = data;
}

u8 GPIODirGet(u32 port, u8 pins)
{
    volatile u32 * reg = (port + GPIODIR);
    u8 data = *reg;
    data = pins;
    return data;
}

u8 GPIOOModeGet(u32 port, u8 pins)
{
    volatile u32 * reg = (port + GPIOAFSEL);
    u8 data = *reg;
    data = pins;
    return data;
}

void ClockInit()
{
    SETBIT(SYSCTRL_RCC,PWRDN);
    SETBIT(SYSCTRL_RCC,BYBASS);
    CLRBIT(SYSCTRL_RCC,USESYSDIV);
}

void GPIOClockSet(u32 port)
{
    if(port == PORTA)
        SETBIT(RCGCGPIO,0);
    else if(port == PORTB)
        SETBIT(RCGCGPIO, 1);
    else if(port == PORTC)
        SETBIT(RCGCGPIO, 2);
    else if(port == PORTD)
        SETBIT(RCGCGPIO, 3);
    else if(port == PORTE)
        SETBIT(RCGCGPIO, 4);
    else if(port == PORTF)
        SETBIT(RCGCGPIO, 5);
}

void GPIOClockRst(u32 port)
{
    if(port == PORTA)
        CLRBIT(RCGCGPIO,0);
    else if(port == PORTB)
        CLRBIT(RCGCGPIO, 1);
    else if(port == PORTC)
        CLRBIT(RCGCGPIO, 2);
    else if(port == PORTD)
        CLRBIT(RCGCGPIO, 3);
    else if(port == PORTE)
        CLRBIT(RCGCGPIO, 4);
    else if(port == PORTF)
        CLRBIT(RCGCGPIO, 5);
}

u8 GPIOClockGet(u32 port)
{
    volatile u32* reg = RCGCGPIO;
    u8 data = *reg;
    return data;
}

void GPIOPadSet(u32 port, u8 pins, gpio_drive_t str, gpio_pad_t pad)
{
    volatile u32* reg;
    u32 data;

    if(pad == Pad_PU)
    {
        reg = (port + GPIOPUR);
        data = *reg;
        data &= ~(pins);
        data |= (0xFF & pins);
    }
    else if(pad == Pad_PD)
    {
        reg = (port + GPIOPDR);
        data = *reg;
        data &= ~(pins);
        data |= (0xFF & pins);
    }
    else if(pad == Pad_OD)
    {
        reg = (port + GPIOODR);
        data = *reg;
        data &= ~(pins);
        data |= (0xFF & pins);
    }
    else if(pad == PAD_NPU_NPD)
    {
        reg = (port + GPIOPDR);
        data = *reg;
        data &= ~(pins);
        data |= (0x00 & pins);

        reg = (port + GPIOPUR);
        data = *reg;
        data &= ~(pins);
        data |= (0x00 & pins);

        reg = (port + GPIOODR);
        data = *reg;
        data &= ~(pins);
        data |= (0x00 & pins);
    }

    *reg = data;

    if(str == Drive_2mA)
    {
        reg = (port + GPIODR2R);
        data = *reg;
        data &= ~(pins);
        data |= (0xFF & pins);
    }
    else if(str == Drive_4mA)
    {
        reg = (port + GPIODR4R);
        data = *reg;
        data &= ~(pins);
        data |= (0xFF & pins);
    }
    else if(str == Drive_8mA)
    {
        reg = (port + GPIODR8R);
        data = *reg;
        data &= ~(pins);
        data |= (0xFF & pins);
    }

    *reg = data;
    

}

u8 GPIODrivePullUpGet(u32 port, u8 pins)
{
    volatile u32* reg = (port + GPIOPUR);
    u8 data = *reg;
    data &= pins;
    return data;
}

u8 GPIOPullDownGet(u32 port, u8 pins)
{
    volatile u32* reg = (port + GPIOPDR);
    u8 data = *reg;
    data &= pins;
    return data;
}

u8 GPIOOpenDrainGet(u32 port, u8 pins)
{
    volatile u32* reg = (port + GPIOODR);
    u8 data = *reg;
    data &= pins;
    return data;
}

void GPIOWrite(u32 port, u8 pins, u8 data)
{
    volatile u32* reg = (port + (pins << 2));
    *reg |= data;
    *reg &= data;
}

u8 GPIORead(u32 port, u8 pins)
{
    volatile u32* reg = (port + (pins << 2));
    return *reg;
}
