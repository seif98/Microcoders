/*
 * GPIO_Init.h
 *
 *  Created on: Feb 9, 2020
 *      Author: seif_
 */

#ifndef GPIO_INIT_H_
#define GPIO_INIT_H_

#include "utils.h"

void GPIO_voidInit();
void GPIO_voidSetPINDir(u8 GPIO_PORT,u8 GPIO_PIN,u8 PINDIR);
void GPIO_voidSetPortDir(u8 GPIO_PORT,u8 Value);
void GPIO_voidSetPin(u32* GPIO_PIN, u8 Value);
void GPIO_voidSetAFunc(u8 GPIO_PIN, u8 TYPE);
void GPIO_voidSetPinState(u8 GPIO_PIN,u8 PINSTATE);
u8 GPIO_u8GetPIN(u8 GPIO_PIN);


#endif /* GPIO_INIT_H_ */
