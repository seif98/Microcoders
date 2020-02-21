/*
 * GPIO.h
 *
 *  Created on: Feb 19, 2020
 *      Author: seif_
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "Register Map.h"

typedef enum {MODE_IN = 0x00, MODE_OUT = 0xff, MODE_AF = 0x3} gpio_mode_t;
typedef enum {PORTA = GPIO_PORTA, PORTB = GPIO_PORTB, PORTC = GPIO_PORTC, PORTD = GPIO_PORTD, PORTE = GPIO_PORTE, PORTF = GPIO_PORTF} gpio_port_t;
typedef enum {Drive_2mA, Drive_4mA, Drive_8mA, Drive_8mA_Slow} gpio_drive_t;
typedef enum {Pad_PU, Pad_PD , PAD_NPU_NPD, Pad_OD} gpio_pad_t;

//Functions prototype

void GPIOINIT();

void GPIOClockSet(u32 port);
void GPIOClockRst(u32 port);
u8 GPIOClockGet(u32 port);

void GPIODirectionModeSet(u32 port, u8 pins, gpio_mode_t mode);
u8 GPIODirGet(u32 port, u8 pins);
u8 GPIOOModeGet(u32 port, u8 pins);

void GPIOPadSet(u32 port, u8 pins, gpio_drive_t str, gpio_pad_t pad);
u8 GPIODrivePullUpGet(u32 port, u8 pins);
u8 GPIOPullDownGet(u32 port, u8 pins);
u8 GPIOOpenDrainGet(u32 port, u8 pins);

u8 GPIORead(u32 port, u8 pins);
void GPIOWrite(u32 port, u8 pins, u8 data);

void ClockInit();


#endif /* GPIO_H_ */
