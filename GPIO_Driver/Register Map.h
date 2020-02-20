/*
 * Register Map.h
 *
 *  Created on: Feb 9, 2020
 *      Author: seif_
 */

#ifndef REGISTER_MAP_H_
#define REGISTER_MAP_H_

#include "utils.h"
#include "std_types.h"

/***              GPIOADCCTL                 ***/

#define SYSCTRL_BASE 0x400FE000

#define GPIO_PORTAP 0x40004000
#define GPIO_PORTAH 0x40058000
#define GPIO_PORTBP 0x40005000
#define GPIO_PORTBH 0x40059000
#define GPIO_PORTCP 0x40006000
#define GPIO_PORTCH 0x4005A000
#define GPIO_PORTDP 0x40007000
#define GPIO_PORTDH 0x4005B000
#define GPIO_PORTEP 0x40024000
#define GPIO_PORTEH 0x4005C000
#define GPIO_PORTFP 0x40025000
#define GPIO_PORTFH 0x4005D000


#define GPIODIR     0x400
#define GPIOAFSEL   0x420
#define GPIOPCTL    0x52C
#define GPIOADCCTL  0x530
#define GPIODMACTL  0x534
#define GPIODR2R    0x500
#define GPIODR4R    0x504
#define GPIODR8R    0x508
#define GPIOPUR     0x510
#define GPIOPDR     0x514
#define GPIOODR     0x50C
#define GPIODEN     0x51C


#define RCGCGPIO OFFSET(SYSCTRL_BASE, 0x608)
#define SYSCTRL_RCC OFFSET(SYSCTRL_BASE, 0x060)
#define SYSCTRL_RCC2 OFFSET(SYSCTRL_BASE, 0x070)
#define GPIOHBCTL OFFSET(SYSCTRL_BASE, 0x06C)


#define AHB 0
#define APB 1

#define BUS AHB

#if BUS == AHB
    #define GPIO_PORTA GPIO_PORTAH
    #define GPIO_PORTB GPIO_PORTBH
    #define GPIO_PORTC GPIO_PORTCH
    #define GPIO_PORTD GPIO_PORTDH
    #define GPIO_PORTE GPIO_PORTEH
    #define GPIO_PORTF GPIO_PORTFH
#elif BUS == APB
    #define GPIO_PORTA GPIO_PORTAP
    #define GPIO_PORTB GPIO_PORTBP
    #define GPIO_PORTC GPIO_PORTCP
    #define GPIO_PORTD GPIO_PORTDP
    #define GPIO_PORTE GPIO_PORTEP
    #define GPIO_PORTF GPIO_PORTFP
#endif


/** RCC PINS **/
#define PWRDN 13
#define BYBASS 11
#define USESYSDIV 22


#endif
