/*
 * Main.c
 *
 *  Created on: Feb 9, 2020
 *      Author: seif_
 */
#include "Register Map.h"
#include "utils.h"
#include "GPIO_Priv.h"
#include "GPIO_Config.h"
#include "GPIO_Init.h"


void main(void)
{
    GPIO_voidInit();
    //GPIO_voidSetPortDir(GPIODIR_FP, 0b0001110);

    GPIO_voidSetAFunc(GPIO_PIN41, GPIO);
    GPIO_voidSetAFunc(GPIO_PIN42, GPIO);
    GPIO_voidSetAFunc(GPIO_PIN43, GPIO);
    GPIO_voidSetAFunc(GPIO_PIN44, GPIO);

    GPIO_voidSetPINDir(PORTF, 0, IN);
    GPIO_voidSetPINDir(PORTF, 1, OUT);
    GPIO_voidSetPINDir(PORTF, 2, OUT);
    GPIO_voidSetPINDir(PORTF, 3, OUT);
    GPIO_voidSetPINDir(PORTF, 4, IN);

    GPIO_voidSetPinState(GPIO_PIN41, PUP);
    GPIO_voidSetPinState(GPIO_PIN42, PUP);
    GPIO_voidSetPinState(GPIO_PIN43, PUP);
    GPIO_voidSetPinState(GPIO_PIN44, PUP);

    //int i = 0;
    SETBIT(GPIODATA_FP,1);
    SETBIT(GPIODATA_FP,2);
    CLRBIT(GPIODATA_FP,3);
//    while(1)
//    {
//        // GPIO_voidSetPin(PORTF_PIN1, GPIO_LOW);
//        // GPIO_voidSetPin(PORTF_PIN2, GPIO_LOW);
//        // GPIO_voidSetPin(PORTF_PIN3, GPIO_LOW);
//        // i = 0;
//        // while(i < 100000)
//        // {
//        //     i++;
//        // }
//
//        // GPIO_voidSetPin(PORTF_PIN1, GPIO_HIGH);
//        // GPIO_voidSetPin(PORTF_PIN2, GPIO_LOW);
//        // GPIO_voidSetPin(PORTF_PIN3, GPIO_LOW);
//        // i = 0;
//        // while(i < 1000000)
//        // {
//        //     i++;
//        // }
//
//        // GPIO_voidSetPin(PORTF_PIN1, GPIO_LOW);
//        // GPIO_voidSetPin(PORTF_PIN2, GPIO_HIGH);
//        // GPIO_voidSetPin(PORTF_PIN3, GPIO_LOW);
//        // i = 0;
//        // while(i < 1000000)
//        // {
//        //     i++;
//        // }
//
//        // GPIO_voidSetPin(PORTF_PIN1, GPIO_HIGH);
//        // GPIO_voidSetPin(PORTF_PIN2, GPIO_HIGH);
//        // GPIO_voidSetPin(PORTF_PIN3, GPIO_LOW);
//        // i = 0;
//        // while(i < 1000000)
//        // {
//        //     i++;
//        // }
//
//        // GPIO_voidSetPin(PORTF_PIN1, GPIO_LOW);
//        // GPIO_voidSetPin(PORTF_PIN2, GPIO_LOW);
//        // GPIO_voidSetPin(PORTF_PIN3, GPIO_HIGH);
//        // i = 0;
//        // while(i < 1000000)
//        //     {
//        //         i++;
//        //     }
//
//        // GPIO_voidSetPin(PORTF_PIN1, GPIO_HIGH);
//        // GPIO_voidSetPin(PORTF_PIN2, GPIO_LOW);
//        // GPIO_voidSetPin(PORTF_PIN3, GPIO_HIGH);
//        // i = 0;
//        // while(i < 1000000)
//        //     {
//        //         i++;
//        //     }
//
//        // GPIO_voidSetPin(PORTF_PIN1, GPIO_LOW);
//        // GPIO_voidSetPin(PORTF_PIN2, GPIO_HIGH);
//        // GPIO_voidSetPin(PORTF_PIN3, GPIO_HIGH);
//        // i = 0;
//        // while(i < 1000000)
//        //     {
//        //         i++;
//        //     }
//
//        // GPIO_voidSetPin(PORTF_PIN1, GPIO_HIGH);
//        // GPIO_voidSetPin(PORTF_PIN2, GPIO_HIGH);
//        // GPIO_voidSetPin(PORTF_PIN3, GPIO_HIGH);
//        // i = 0;
//        // while(i < 1000000)
//        // {
//        //     i++;
//        // }
//        // i = 0;
//
//    }
}
